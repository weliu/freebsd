/*
 * Copyright (c) 2005 Voltaire Inc.  All rights reserved.
 * Copyright (c) 2002-2005, Network Appliance, Inc. All rights reserved.
 * Copyright (c) 1999-2005, Mellanox Technologies, Inc. All rights reserved.
 * Copyright (c) 2005 Intel Corporation.  All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <linux/mutex.h>
#include <linux/inetdevice.h>
#include <linux/workqueue.h>
#include <net/arp.h>
#include <net/neighbour.h>
#include <net/route.h>
#include <net/netevent.h>
#include <net/addrconf.h>
#include <net/ip6_route.h>
#include <rdma/ib_addr.h>

MODULE_AUTHOR("Sean Hefty");
MODULE_DESCRIPTION("IB Address Translation");
MODULE_LICENSE("Dual BSD/GPL");

struct addr_req {
	struct list_head list;
	struct sockaddr_storage src_addr;
	struct sockaddr_storage dst_addr;
	struct rdma_dev_addr *addr;
	struct rdma_addr_client *client;
	void *context;
	void (*callback)(int status, struct sockaddr *src_addr,
			 struct rdma_dev_addr *addr, void *context);
	unsigned long timeout;
	int status;
};

static void process_req(struct work_struct *work);

static DEFINE_MUTEX(lock);
static LIST_HEAD(req_list);
static struct delayed_work work;
static struct workqueue_struct *addr_wq;

void rdma_addr_register_client(struct rdma_addr_client *client)
{
	atomic_set(&client->refcount, 1);
	init_completion(&client->comp);
}
EXPORT_SYMBOL(rdma_addr_register_client);

static inline void put_client(struct rdma_addr_client *client)
{
	if (atomic_dec_and_test(&client->refcount))
		complete(&client->comp);
}

void rdma_addr_unregister_client(struct rdma_addr_client *client)
{
	put_client(client);
	wait_for_completion(&client->comp);
}
EXPORT_SYMBOL(rdma_addr_unregister_client);

#ifdef __linux__
int rdma_copy_addr(struct rdma_dev_addr *dev_addr, struct net_device *dev,
		     const unsigned char *dst_dev_addr)
{
	dev_addr->dev_type = dev->type;
	memcpy(dev_addr->src_dev_addr, dev->dev_addr, MAX_ADDR_LEN);
	memcpy(dev_addr->broadcast, dev->broadcast, MAX_ADDR_LEN);
	if (dst_dev_addr)
		memcpy(dev_addr->dst_dev_addr, dst_dev_addr, MAX_ADDR_LEN);
	dev_addr->bound_dev_if = dev->ifindex;
	return 0;
}
#else
int rdma_copy_addr(struct rdma_dev_addr *dev_addr, struct ifnet *dev,
		     const unsigned char *dst_dev_addr)
{
	if (dev->if_type == IFT_INFINIBAND)
		dev_addr->dev_type = ARPHRD_INFINIBAND;
	else if (dev->if_type == IFT_ETHER)
		dev_addr->dev_type = ARPHRD_ETHER;
	else
		dev_addr->dev_type = 0;
	memcpy(dev_addr->src_dev_addr, IF_LLADDR(dev), dev->if_addrlen);
	memcpy(dev_addr->broadcast, __DECONST(char *, dev->if_broadcastaddr),
	    dev->if_addrlen);
	if (dst_dev_addr)
		memcpy(dev_addr->dst_dev_addr, dst_dev_addr, dev->if_addrlen);
	dev_addr->bound_dev_if = dev->if_index;
	return 0;
}
#endif
EXPORT_SYMBOL(rdma_copy_addr);

int rdma_translate_ip(struct sockaddr *addr, struct rdma_dev_addr *dev_addr)
{
	struct net_device *dev;
	int ret = -EADDRNOTAVAIL;

	if (dev_addr->bound_dev_if) {
		dev = dev_get_by_index(&init_net, dev_addr->bound_dev_if);
		if (!dev)
			return -ENODEV;
		ret = rdma_copy_addr(dev_addr, dev, NULL);
		dev_put(dev);
		return ret;
	}

	switch (addr->sa_family) {
	case AF_INET:
		dev = ip_dev_find(NULL,
			((struct sockaddr_in *) addr)->sin_addr.s_addr);

		if (!dev)
			return ret;

		ret = rdma_copy_addr(dev_addr, dev, NULL);
		dev_put(dev);
		break;

#if defined(INET6)
	case AF_INET6:
#ifdef __linux__
		read_lock(&dev_base_lock);
		for_each_netdev(&init_net, dev) {
			if (ipv6_chk_addr(&init_net,
					  &((struct sockaddr_in6 *) addr)->sin6_addr,
					  dev, 1)) {
				ret = rdma_copy_addr(dev_addr, dev, NULL);
				break;
			}
		}
		read_unlock(&dev_base_lock);
#else
		{
			struct sockaddr_in6 *sin6;
			struct ifaddr *ifa;
			in_port_t port;

			sin6 = (struct sockaddr_in6 *)addr;
			port = sin6->sin6_port;
			sin6->sin6_port = 0;
			ifa = ifa_ifwithaddr(addr);
			sin6->sin6_port = port;
			if (ifa == NULL) {
				ret = -ENODEV;
				break;
			}
			ret = rdma_copy_addr(dev_addr, ifa->ifa_ifp, NULL);
			ifa_free(ifa);
			break;
		}
#endif
		break;
#endif
	}
	return ret;
}
EXPORT_SYMBOL(rdma_translate_ip);

static void set_timeout(unsigned long time)
{
	unsigned long delay;

	cancel_delayed_work(&work);

	delay = time - jiffies;
	if ((long)delay <= 0)
		delay = 1;

	queue_delayed_work(addr_wq, &work, delay);
}

static void queue_req(struct addr_req *req)
{
	struct addr_req *temp_req;

	mutex_lock(&lock);
	list_for_each_entry_reverse(temp_req, &req_list, list) {
		if (time_after_eq(req->timeout, temp_req->timeout))
			break;
	}

	list_add(&req->list, &temp_req->list);

	if (req_list.next == &req->list)
		set_timeout(req->timeout);
	mutex_unlock(&lock);
}

#ifdef __linux__
static int addr4_resolve(struct sockaddr_in *src_in,
			 struct sockaddr_in *dst_in,
			 struct rdma_dev_addr *addr)
{
	__be32 src_ip = src_in->sin_addr.s_addr;
	__be32 dst_ip = dst_in->sin_addr.s_addr;
	struct flowi fl;
	struct rtable *rt;
	struct neighbour *neigh;
	int ret;

	memset(&fl, 0, sizeof fl);
	fl.nl_u.ip4_u.daddr = dst_ip;
	fl.nl_u.ip4_u.saddr = src_ip;
	fl.oif = addr->bound_dev_if;

	ret = ip_route_output_key(&init_net, &rt, &fl);
	if (ret)
		goto out;

	src_in->sin_family = AF_INET;
	src_in->sin_addr.s_addr = rt->rt_src;

	if (rt->idev->dev->flags & IFF_LOOPBACK) {
		ret = rdma_translate_ip((struct sockaddr *) dst_in, addr);
		if (!ret)
			memcpy(addr->dst_dev_addr, addr->src_dev_addr, MAX_ADDR_LEN);
		goto put;
	}

	/* If the device does ARP internally, return 'done' */
	if (rt->idev->dev->flags & IFF_NOARP) {
		rdma_copy_addr(addr, rt->idev->dev, NULL);
		goto put;
	}

	neigh = neigh_lookup(&arp_tbl, &rt->rt_gateway, rt->idev->dev);
	if (!neigh || !(neigh->nud_state & NUD_VALID)) {
		neigh_event_send(rt->u.dst.neighbour, NULL);
		ret = -ENODATA;
		if (neigh)
			goto release;
		goto put;
	}

	ret = rdma_copy_addr(addr, neigh->dev, neigh->ha);
release:
	neigh_release(neigh);
put:
	ip_rt_put(rt);
out:
	return ret;
}

#if defined(INET6)
static int addr6_resolve(struct sockaddr_in6 *src_in,
			 struct sockaddr_in6 *dst_in,
			 struct rdma_dev_addr *addr)
{
	struct flowi fl;
	struct neighbour *neigh;
	struct dst_entry *dst;
	int ret;

	memset(&fl, 0, sizeof fl);
	ipv6_addr_copy(&fl.fl6_dst, &dst_in->sin6_addr);
	ipv6_addr_copy(&fl.fl6_src, &src_in->sin6_addr);
	fl.oif = addr->bound_dev_if;

	dst = ip6_route_output(&init_net, NULL, &fl);
	if ((ret = dst->error))
		goto put;

	if (ipv6_addr_any(&fl.fl6_src)) {
		ret = ipv6_dev_get_saddr(&init_net, ip6_dst_idev(dst)->dev,
					 &fl.fl6_dst, 0, &fl.fl6_src);
		if (ret)
			goto put;

		src_in->sin6_family = AF_INET6;
		ipv6_addr_copy(&src_in->sin6_addr, &fl.fl6_src);
	}

	if (dst->dev->flags & IFF_LOOPBACK) {
		ret = rdma_translate_ip((struct sockaddr *) dst_in, addr);
		if (!ret)
			memcpy(addr->dst_dev_addr, addr->src_dev_addr, MAX_ADDR_LEN);
		goto put;
	}

	/* If the device does ARP internally, return 'done' */
	if (dst->dev->flags & IFF_NOARP) {
		ret = rdma_copy_addr(addr, dst->dev, NULL);
		goto put;
	}
	
	neigh = dst->neighbour;
	if (!neigh || !(neigh->nud_state & NUD_VALID)) {
		neigh_event_send(dst->neighbour, NULL);
		ret = -ENODATA;
		goto put;
	}

	ret = rdma_copy_addr(addr, dst->dev, neigh->ha);
put:
	dst_release(dst);
	return ret;
}
#else
static int addr6_resolve(struct sockaddr_in6 *src_in,
			 struct sockaddr_in6 *dst_in,
			 struct rdma_dev_addr *addr)
{
	return -EADDRNOTAVAIL;
}
#endif

#else
#include <netinet/if_ether.h>

static int addr_resolve(struct sockaddr *src_in,
			struct sockaddr *dst_in,
			struct rdma_dev_addr *addr)
{
	struct sockaddr_in *sin;
	struct sockaddr_in6 *sin6;
	struct ifaddr *ifa;
	struct ifnet *ifp;
	struct llentry *lle;
	struct rtentry *rte;
	in_port_t port;
	u_char edst[MAX_ADDR_LEN];
	int multi;
	int bcast;
	int error;

	/*
	 * Determine whether the address is unicast, multicast, or broadcast
	 * and whether the source interface is valid.
	 */
	multi = 0;
	bcast = 0;
	sin = NULL;
	sin6 = NULL;
	ifp = NULL;
	rte = NULL;
	switch (dst_in->sa_family) {
	case AF_INET:
		sin = (struct sockaddr_in *)dst_in;
		if (sin->sin_addr.s_addr == INADDR_BROADCAST)
			bcast = 1;
		if (IN_MULTICAST(ntohl(sin->sin_addr.s_addr)))
			multi = 1;
		sin = (struct sockaddr_in *)src_in;
		if (sin->sin_addr.s_addr != INADDR_ANY) {
			/*
			 * Address comparison fails if the port is set
			 * cache it here to be restored later.
			 */
			port = sin->sin_port;
			sin->sin_port = 0;
			memset(&sin->sin_zero, 0, sizeof(sin->sin_zero));
		} else
			src_in = NULL; 
		break;
#ifdef INET6
	case AF_INET6:
		sin6 = (struct sockaddr_in6 *)dst_in;
		if (IN6_IS_ADDR_MULTICAST(&sin6->sin6_addr))
			multi = 1;
		sin6 = (struct sockaddr_in6 *)src_in;
		if (!IN6_IS_ADDR_UNSPECIFIED(&sin6->sin6_addr)) {
			port = sin6->sin6_port;
			sin6->sin6_port = 0;
		} else
			src_in = NULL;
		break;
#endif
	default:
		return -EINVAL;
	}
	/*
	 * If we have a source address to use look it up first and verify
	 * that it is a local interface.
	 */
	if (src_in) {
		ifa = ifa_ifwithaddr(src_in);
		if (sin)
			sin->sin_port = port;
		if (sin6)
			sin6->sin6_port = port;
		if (ifa == NULL)
			return -ENETUNREACH;
		ifp = ifa->ifa_ifp;
		ifa_free(ifa);
		if (bcast || multi)
			goto mcast;
	}
	/*
	 * Make sure the route exists and has a valid link.
	 */
	rte = rtalloc1(dst_in, 1, 0);
	if (rte == NULL || rte->rt_ifp == NULL || !RT_LINK_IS_UP(rte->rt_ifp)) {
		if (rte) 
			RTFREE_LOCKED(rte);
		return -EHOSTUNREACH;
	}
	/*
	 * If it's not multicast or broadcast and the route doesn't match the
	 * requested interface return unreachable.  Otherwise fetch the
	 * correct interface pointer and unlock the route.
	 */
	if (multi || bcast) {
		if (ifp == NULL)
			ifp = rte->rt_ifp;
		RTFREE_LOCKED(rte);
	} else if (ifp && ifp != rte->rt_ifp) {
		RTFREE_LOCKED(rte);
		return -ENETUNREACH;
	} else {
		if (ifp == NULL)
			ifp = rte->rt_ifp;
		RT_UNLOCK(rte);
	}
mcast:
	if (bcast)
		return rdma_copy_addr(addr, ifp, ifp->if_broadcastaddr);
	if (multi) {
		struct sockaddr *llsa;

		error = ifp->if_resolvemulti(ifp, &llsa, dst_in);
		if (error)
			return -error;
		error = rdma_copy_addr(addr, ifp,
		    LLADDR((struct sockaddr_dl *)llsa));
		free(llsa, M_IFMADDR);
		return error;
	}
	/*
	 * Resolve the link local address.
	 */
#ifdef INET6
	if (dst_in->sa_family == AF_INET6)
		error = nd6_storelladdr(ifp, NULL, dst_in, (u_char *)edst, &lle);
	else
#endif
		error = arpresolve(ifp, rte, NULL, dst_in, edst, &lle);
	RTFREE(rte);
	if (error == 0)
		return rdma_copy_addr(addr, ifp, edst);
	if (error == EWOULDBLOCK)
		return -ENODATA;
	return -error;
}

#endif

static void process_req(struct work_struct *work)
{
	struct addr_req *req, *temp_req;
	struct sockaddr *src_in, *dst_in;
	struct list_head done_list;

	INIT_LIST_HEAD(&done_list);

	mutex_lock(&lock);
	list_for_each_entry_safe(req, temp_req, &req_list, list) {
		if (req->status == -ENODATA) {
			src_in = (struct sockaddr *) &req->src_addr;
			dst_in = (struct sockaddr *) &req->dst_addr;
			req->status = addr_resolve(src_in, dst_in, req->addr);
			if (req->status && time_after_eq(jiffies, req->timeout))
				req->status = -ETIMEDOUT;
			else if (req->status == -ENODATA)
				continue;
		}
		list_move_tail(&req->list, &done_list);
	}

	if (!list_empty(&req_list)) {
		req = list_entry(req_list.next, struct addr_req, list);
		set_timeout(req->timeout);
	}
	mutex_unlock(&lock);

	list_for_each_entry_safe(req, temp_req, &done_list, list) {
		list_del(&req->list);
		req->callback(req->status, (struct sockaddr *) &req->src_addr,
			req->addr, req->context);
		put_client(req->client);
		kfree(req);
	}
}

int rdma_resolve_ip(struct rdma_addr_client *client,
		    struct sockaddr *src_addr, struct sockaddr *dst_addr,
		    struct rdma_dev_addr *addr, int timeout_ms,
		    void (*callback)(int status, struct sockaddr *src_addr,
				     struct rdma_dev_addr *addr, void *context),
		    void *context)
{
	struct sockaddr *src_in, *dst_in;
	struct addr_req *req;
	int ret = 0;

	req = kzalloc(sizeof *req, GFP_KERNEL);
	if (!req)
		return -ENOMEM;

	src_in = (struct sockaddr *) &req->src_addr;
	dst_in = (struct sockaddr *) &req->dst_addr;

	if (src_addr) {
		if (src_addr->sa_family != dst_addr->sa_family) {
			ret = -EINVAL;
			goto err;
		}

		memcpy(src_in, src_addr, ip_addr_size(src_addr));
	} else {
		src_in->sa_family = dst_addr->sa_family;
	}

	memcpy(dst_in, dst_addr, ip_addr_size(dst_addr));
	req->addr = addr;
	req->callback = callback;
	req->context = context;
	req->client = client;
	atomic_inc(&client->refcount);

	req->status = addr_resolve(src_in, dst_in, addr);
	switch (req->status) {
	case 0:
		req->timeout = jiffies;
		queue_req(req);
		break;
	case -ENODATA:
		req->timeout = msecs_to_jiffies(timeout_ms) + jiffies;
		queue_req(req);
		break;
	default:
		ret = req->status;
		atomic_dec(&client->refcount);
		goto err;
	}
	return ret;
err:
	kfree(req);
	return ret;
}
EXPORT_SYMBOL(rdma_resolve_ip);

void rdma_addr_cancel(struct rdma_dev_addr *addr)
{
	struct addr_req *req, *temp_req;

	mutex_lock(&lock);
	list_for_each_entry_safe(req, temp_req, &req_list, list) {
		if (req->addr == addr) {
			req->status = -ECANCELED;
			req->timeout = jiffies;
			list_move(&req->list, &req_list);
			set_timeout(req->timeout);
			break;
		}
	}
	mutex_unlock(&lock);
}
EXPORT_SYMBOL(rdma_addr_cancel);

static int netevent_callback(struct notifier_block *self, unsigned long event,
	void *ctx)
{
	if (event == NETEVENT_NEIGH_UPDATE) {
#ifdef __linux__
		struct neighbour *neigh = ctx;

		if (neigh->nud_state & NUD_VALID) {
			set_timeout(jiffies);
		}
#else
		set_timeout(jiffies);
#endif
	}
	return 0;
}

static struct notifier_block nb = {
	.notifier_call = netevent_callback
};

static int addr_init(void)
{
	INIT_DELAYED_WORK(&work, process_req);
	addr_wq = create_singlethread_workqueue("ib_addr");
	if (!addr_wq)
		return -ENOMEM;

	register_netevent_notifier(&nb);
	return 0;
}

static void addr_cleanup(void)
{
	unregister_netevent_notifier(&nb);
	destroy_workqueue(addr_wq);
}

module_init(addr_init);
module_exit(addr_cleanup);
