/*
 * Namespace munging inspired by an equivalent hack in NetBSD's tree: add
 * the "ssh_" prefix to every symbol in libssh which doesn't already have
 * it.  This prevents collisions between symbols in libssh and symbols in
 * other libraries or applications which link with libssh, either directly
 * or indirectly (e.g. through PAM loading pam_ssh).
 *
 * A list of symbols which need munging is obtained as follows:
 *
 * nm libssh.a | awk '/[0-9a-z] [A-Z] / && $3 !~ /^ssh_/ { print "#define", $3, "ssh_" $3 }'
 *
 * $FreeBSD$
 */

#define a2port					ssh_a2port
#define a2tun					ssh_a2tun
#define acss					ssh_acss
#define acss_setkey				ssh_acss_setkey
#define acss_setsubkey				ssh_acss_setsubkey
#define add_host_to_hostfile			ssh_add_host_to_hostfile
#define add_recv_bytes				ssh_add_recv_bytes
#define addargs					ssh_addargs
#define addr_match_list				ssh_addr_match_list
#define ask_permission				ssh_ask_permission
#define atomicio				ssh_atomicio
#define atomiciov				ssh_atomiciov
#define auth_request_forwarding			ssh_auth_request_forwarding
#define buffer_append				ssh_buffer_append
#define buffer_append_space			ssh_buffer_append_space
#define buffer_check_alloc			ssh_buffer_check_alloc
#define buffer_clear				ssh_buffer_clear
#define buffer_compress				ssh_buffer_compress
#define buffer_compress_init_recv		ssh_buffer_compress_init_recv
#define buffer_compress_init_send		ssh_buffer_compress_init_send
#define buffer_compress_uninit			ssh_buffer_compress_uninit
#define buffer_consume				ssh_buffer_consume
#define buffer_consume_end			ssh_buffer_consume_end
#define buffer_consume_end_ret			ssh_buffer_consume_end_ret
#define buffer_consume_ret			ssh_buffer_consume_ret
#define buffer_dump				ssh_buffer_dump
#define buffer_free				ssh_buffer_free
#define buffer_get				ssh_buffer_get
#define buffer_get_bignum			ssh_buffer_get_bignum
#define buffer_get_bignum2			ssh_buffer_get_bignum2
#define buffer_get_bignum2_ret			ssh_buffer_get_bignum2_ret
#define buffer_get_bignum_ret			ssh_buffer_get_bignum_ret
#define buffer_get_char				ssh_buffer_get_char
#define buffer_get_char_ret			ssh_buffer_get_char_ret
#define buffer_get_int				ssh_buffer_get_int
#define buffer_get_int64			ssh_buffer_get_int64
#define buffer_get_int64_ret			ssh_buffer_get_int64_ret
#define buffer_get_int_ret			ssh_buffer_get_int_ret
#define buffer_get_ret				ssh_buffer_get_ret
#define buffer_get_short			ssh_buffer_get_short
#define buffer_get_short_ret			ssh_buffer_get_short_ret
#define buffer_get_string			ssh_buffer_get_string
#define buffer_get_string_ptr			ssh_buffer_get_string_ptr
#define buffer_get_string_ret			ssh_buffer_get_string_ret
#define buffer_init				ssh_buffer_init
#define buffer_len				ssh_buffer_len
#define buffer_ptr				ssh_buffer_ptr
#define buffer_put_bignum			ssh_buffer_put_bignum
#define buffer_put_bignum2			ssh_buffer_put_bignum2
#define buffer_put_bignum2_ret			ssh_buffer_put_bignum2_ret
#define buffer_put_bignum_ret			ssh_buffer_put_bignum_ret
#define buffer_put_char				ssh_buffer_put_char
#define buffer_put_cstring			ssh_buffer_put_cstring
#define buffer_put_int				ssh_buffer_put_int
#define buffer_put_int64			ssh_buffer_put_int64
#define buffer_put_short			ssh_buffer_put_short
#define buffer_put_string			ssh_buffer_put_string
#define buffer_uncompress			ssh_buffer_uncompress
#define chan_ibuf_empty				ssh_chan_ibuf_empty
#define chan_is_dead				ssh_chan_is_dead
#define chan_mark_dead				ssh_chan_mark_dead
#define chan_obuf_empty				ssh_chan_obuf_empty
#define chan_rcvd_eow				ssh_chan_rcvd_eow
#define chan_rcvd_ieof				ssh_chan_rcvd_ieof
#define chan_rcvd_oclose			ssh_chan_rcvd_oclose
#define chan_read_failed			ssh_chan_read_failed
#define chan_write_failed			ssh_chan_write_failed
#define channel_add_adm_permitted_opens		ssh_channel_add_adm_permitted_opens
#define channel_add_permitted_opens		ssh_channel_add_permitted_opens
#define channel_after_select			ssh_channel_after_select
#define channel_by_id				ssh_channel_by_id
#define channel_cancel_cleanup			ssh_channel_cancel_cleanup
#define channel_cancel_rport_listener		ssh_channel_cancel_rport_listener
#define channel_clear_adm_permitted_opens	ssh_channel_clear_adm_permitted_opens
#define channel_clear_permitted_opens		ssh_channel_clear_permitted_opens
#define channel_close_all			ssh_channel_close_all
#define channel_close_fd			ssh_channel_close_fd
#define channel_connect_by_listen_address	ssh_channel_connect_by_listen_address
#define channel_connect_to			ssh_channel_connect_to
#define channel_find_open			ssh_channel_find_open
#define channel_free				ssh_channel_free
#define channel_free_all			ssh_channel_free_all
#define channel_input_close			ssh_channel_input_close
#define channel_input_close_confirmation	ssh_channel_input_close_confirmation
#define channel_input_data			ssh_channel_input_data
#define channel_input_extended_data		ssh_channel_input_extended_data
#define channel_input_ieof			ssh_channel_input_ieof
#define channel_input_oclose			ssh_channel_input_oclose
#define channel_input_open_confirmation		ssh_channel_input_open_confirmation
#define channel_input_open_failure		ssh_channel_input_open_failure
#define channel_input_port_forward_request	ssh_channel_input_port_forward_request
#define channel_input_port_open			ssh_channel_input_port_open
#define channel_input_status_confirm		ssh_channel_input_status_confirm
#define channel_input_window_adjust		ssh_channel_input_window_adjust
#define channel_lookup				ssh_channel_lookup
#define channel_new				ssh_channel_new
#define channel_not_very_much_buffered_data	ssh_channel_not_very_much_buffered_data
#define channel_open_message			ssh_channel_open_message
#define channel_output_poll			ssh_channel_output_poll
#define channel_permit_all_opens		ssh_channel_permit_all_opens
#define channel_post				ssh_channel_post
#define channel_pre				ssh_channel_pre
#define channel_prepare_select			ssh_channel_prepare_select
#define channel_print_adm_permitted_opens	ssh_channel_print_adm_permitted_opens
#define channel_register_cleanup		ssh_channel_register_cleanup
#define channel_register_confirm		ssh_channel_register_confirm
#define channel_register_filter			ssh_channel_register_filter
#define channel_register_open_confirm		ssh_channel_register_open_confirm
#define channel_register_status_confirm		ssh_channel_register_status_confirm
#define channel_request_remote_forwarding	ssh_channel_request_remote_forwarding
#define channel_request_rforward_cancel		ssh_channel_request_rforward_cancel
#define channel_request_start			ssh_channel_request_start
#define channel_send_open			ssh_channel_send_open
#define channel_send_window_changes		ssh_channel_send_window_changes
#define channel_set_af				ssh_channel_set_af
#define channel_set_fds				ssh_channel_set_fds
#define channel_setup_local_fwd_listener	ssh_channel_setup_local_fwd_listener
#define channel_setup_remote_fwd_listener	ssh_channel_setup_remote_fwd_listener
#define channel_still_open			ssh_channel_still_open
#define channel_stop_listening			ssh_channel_stop_listening
#define check_host_in_hostfile			ssh_check_host_in_hostfile
#define choose_dh				ssh_choose_dh
#define chop					ssh_chop
#define cipher_blocksize			ssh_cipher_blocksize
#define cipher_by_name				ssh_cipher_by_name
#define cipher_by_number			ssh_cipher_by_number
#define cipher_cleanup				ssh_cipher_cleanup
#define cipher_crypt				ssh_cipher_crypt
#define cipher_get_keycontext			ssh_cipher_get_keycontext
#define cipher_get_keyiv			ssh_cipher_get_keyiv
#define cipher_get_keyiv_len			ssh_cipher_get_keyiv_len
#define cipher_get_number			ssh_cipher_get_number
#define cipher_init				ssh_cipher_init
#define cipher_is_cbc				ssh_cipher_is_cbc
#define cipher_keylen				ssh_cipher_keylen
#define cipher_mask_ssh1			ssh_cipher_mask_ssh1
#define cipher_name				ssh_cipher_name
#define cipher_number				ssh_cipher_number
#define cipher_set_key_string			ssh_cipher_set_key_string
#define cipher_set_keycontext			ssh_cipher_set_keycontext
#define cipher_set_keyiv			ssh_cipher_set_keyiv
#define ciphers					ssh_ciphers
#define ciphers_valid				ssh_ciphers_valid
#define cleanhostname				ssh_cleanhostname
#define cleanup_exit				ssh_cleanup_exit
#define clear_cached_addr			ssh_clear_cached_addr
#define colon					ssh_colon
#define compat13				ssh_compat13
#define compat20				ssh_compat20
#define compat_cipher_proposal			ssh_compat_cipher_proposal
#define compat_datafellows			ssh_compat_datafellows
#define convtime				ssh_convtime
#define current_keys				ssh_current_keys
#define datafellows				ssh_datafellows
#define debug					ssh_debug
#define debug					ssh_debug
#define debug2					ssh_debug2
#define debug2					ssh_debug2
#define debug3					ssh_debug3
#define debug3					ssh_debug3
#define decode_reply				ssh_decode_reply
#define deny_input_open				ssh_deny_input_open
#define derive_ssh1_session_id			ssh_derive_ssh1_session_id
#define detect_attack				ssh_detect_attack
#define dh_estimate				ssh_dh_estimate
#define dh_gen_key				ssh_dh_gen_key
#define dh_new_group				ssh_dh_new_group
#define dh_new_group1				ssh_dh_new_group1
#define dh_new_group14				ssh_dh_new_group14
#define dh_new_group_asc			ssh_dh_new_group_asc
#define dh_pub_is_valid				ssh_dh_pub_is_valid
#define dispatch				ssh_dispatch
#define dispatch_init				ssh_dispatch_init
#define dispatch_protocol_error			ssh_dispatch_protocol_error
#define dispatch_protocol_ignore		ssh_dispatch_protocol_ignore
#define dispatch_range				ssh_dispatch_range
#define dispatch_run				ssh_dispatch_run
#define dispatch_set				ssh_dispatch_set
#define do_log					ssh_do_log
#define dump_base64				ssh_dump_base64
#define enable_compat13				ssh_enable_compat13
#define enable_compat20				ssh_enable_compat20
#define error					ssh_error
#define error					ssh_error
#define evp_acss				ssh_evp_acss
#define evp_aes_128_ctr				ssh_evp_aes_128_ctr
#define evp_rijndael				ssh_evp_rijndael
#define evp_ssh1_3des				ssh_evp_ssh1_3des
#define evp_ssh1_bf				ssh_evp_ssh1_bf
#define export_dns_rr				ssh_export_dns_rr
#define fatal					ssh_fatal
#define fatal					ssh_fatal
#define fmt_scaled				ssh_fmt_scaled
#define freeargs				ssh_freeargs
#define freerrset				ssh_freerrset
#define gen_candidates				ssh_gen_candidates
#define get_canonical_hostname			ssh_get_canonical_hostname
#define get_local_ipaddr			ssh_get_local_ipaddr
#define get_local_name				ssh_get_local_name
#define get_local_port				ssh_get_local_port
#define get_peer_ipaddr				ssh_get_peer_ipaddr
#define get_peer_port				ssh_get_peer_port
#define get_recv_bytes				ssh_get_recv_bytes
#define get_remote_ipaddr			ssh_get_remote_ipaddr
#define get_remote_name_or_ip			ssh_get_remote_name_or_ip
#define get_remote_port				ssh_get_remote_port
#define get_sock_port				ssh_get_sock_port
#define get_u16					ssh_get_u16
#define get_u32					ssh_get_u32
#define get_u64					ssh_get_u64
#define getrrsetbyname				ssh_getrrsetbyname
#define host_hash				ssh_host_hash
#define hostfile_read_key			ssh_hostfile_read_key
#define hpdelim					ssh_hpdelim
#define incoming_stream				ssh_incoming_stream
#define init_rng				ssh_init_rng
#define ipv64_normalise_mapped			ssh_ipv64_normalise_mapped
#define kex_derive_keys				ssh_kex_derive_keys
#define kex_dh_hash				ssh_kex_dh_hash
#define kex_finish				ssh_kex_finish
#define kex_get_newkeys				ssh_kex_get_newkeys
#define kex_input_kexinit			ssh_kex_input_kexinit
#define kex_send_kexinit			ssh_kex_send_kexinit
#define kex_setup				ssh_kex_setup
#define kexdh_client				ssh_kexdh_client
#define kexgex_client				ssh_kexgex_client
#define kexgex_hash				ssh_kexgex_hash
#define key_demote				ssh_key_demote
#define key_equal				ssh_key_equal
#define key_fingerprint				ssh_key_fingerprint
#define key_fingerprint_raw			ssh_key_fingerprint_raw
#define key_free				ssh_key_free
#define key_from_blob				ssh_key_from_blob
#define key_from_private			ssh_key_from_private
#define key_generate				ssh_key_generate
#define key_load_private			ssh_key_load_private
#define key_load_private_pem			ssh_key_load_private_pem
#define key_load_private_type			ssh_key_load_private_type
#define key_load_public				ssh_key_load_public
#define key_load_public_type			ssh_key_load_public_type
#define key_names_valid2			ssh_key_names_valid2
#define key_new					ssh_key_new
#define key_new_private				ssh_key_new_private
#define key_perm_ok				ssh_key_perm_ok
#define key_read				ssh_key_read
#define key_save_private			ssh_key_save_private
#define key_sign				ssh_key_sign
#define key_size				ssh_key_size
#define key_ssh_name				ssh_key_ssh_name
#define key_to_blob				ssh_key_to_blob
#define key_type				ssh_key_type
#define key_type_from_name			ssh_key_type_from_name
#define key_verify				ssh_key_verify
#define key_write				ssh_key_write
#define log_facility_name			ssh_log_facility_name
#define log_facility_number			ssh_log_facility_number
#define log_init				ssh_log_init
#define log_level_name				ssh_log_level_name
#define log_level_number			ssh_log_level_number
#define logit					ssh_logit
#define logit					ssh_logit
#define lookup_key_in_hostfile_by_type		ssh_lookup_key_in_hostfile_by_type
#define mac_clear				ssh_mac_clear
#define mac_compute				ssh_mac_compute
#define mac_init				ssh_mac_init
#define mac_setup				ssh_mac_setup
#define mac_valid				ssh_mac_valid
#define macs					ssh_macs
#define match_host_and_ip			ssh_match_host_and_ip
#define match_hostname				ssh_match_hostname
#define match_list				ssh_match_list
#define match_pattern				ssh_match_pattern
#define match_pattern_list			ssh_match_pattern_list
#define match_user				ssh_match_user
#define mm_receive_fd				ssh_mm_receive_fd
#define mm_send_fd				ssh_mm_send_fd
#define ms_subtract_diff			ssh_ms_subtract_diff
#define ms_to_timeval				ssh_ms_to_timeval
#define mysignal				ssh_mysignal
#define outgoing_stream				ssh_outgoing_stream
#define packet_add_padding			ssh_packet_add_padding
#define packet_backup_state			ssh_packet_backup_state
#define packet_close				ssh_packet_close
#define packet_connection_is_ipv4		ssh_packet_connection_is_ipv4
#define packet_connection_is_on_socket		ssh_packet_connection_is_on_socket
#define packet_disconnect			ssh_packet_disconnect
#define packet_get_bignum			ssh_packet_get_bignum
#define packet_get_bignum2			ssh_packet_get_bignum2
#define packet_get_char				ssh_packet_get_char
#define packet_get_connection_in		ssh_packet_get_connection_in
#define packet_get_connection_out		ssh_packet_get_connection_out
#define packet_get_encryption_key		ssh_packet_get_encryption_key
#define packet_get_input			ssh_packet_get_input
#define packet_get_int				ssh_packet_get_int
#define packet_get_int64			ssh_packet_get_int64
#define packet_get_keycontext			ssh_packet_get_keycontext
#define packet_get_keyiv			ssh_packet_get_keyiv
#define packet_get_keyiv_len			ssh_packet_get_keyiv_len
#define packet_get_maxsize			ssh_packet_get_maxsize
#define packet_get_newkeys			ssh_packet_get_newkeys
#define packet_get_output			ssh_packet_get_output
#define packet_get_protocol_flags		ssh_packet_get_protocol_flags
#define packet_get_raw				ssh_packet_get_raw
#define packet_get_ssh1_cipher			ssh_packet_get_ssh1_cipher
#define packet_get_state			ssh_packet_get_state
#define packet_get_string			ssh_packet_get_string
#define packet_get_string_ptr			ssh_packet_get_string_ptr
#define packet_have_data_to_write		ssh_packet_have_data_to_write
#define packet_inc_alive_timeouts		ssh_packet_inc_alive_timeouts
#define packet_is_interactive			ssh_packet_is_interactive
#define packet_need_rekeying			ssh_packet_need_rekeying
#define packet_not_very_much_data_to_write	ssh_packet_not_very_much_data_to_write
#define packet_process_incoming			ssh_packet_process_incoming
#define packet_put_bignum			ssh_packet_put_bignum
#define packet_put_bignum2			ssh_packet_put_bignum2
#define packet_put_char				ssh_packet_put_char
#define packet_put_cstring			ssh_packet_put_cstring
#define packet_put_int				ssh_packet_put_int
#define packet_put_int64			ssh_packet_put_int64
#define packet_put_raw				ssh_packet_put_raw
#define packet_put_string			ssh_packet_put_string
#define packet_read				ssh_packet_read
#define packet_read_expect			ssh_packet_read_expect
#define packet_read_poll			ssh_packet_read_poll
#define packet_read_poll_seqnr			ssh_packet_read_poll_seqnr
#define packet_read_seqnr			ssh_packet_read_seqnr
#define packet_remaining			ssh_packet_remaining
#define packet_restore_state			ssh_packet_restore_state
#define packet_send				ssh_packet_send
#define packet_send_debug			ssh_packet_send_debug
#define packet_send_ignore			ssh_packet_send_ignore
#define packet_set_alive_timeouts		ssh_packet_set_alive_timeouts
#define packet_set_authenticated		ssh_packet_set_authenticated
#define packet_set_connection			ssh_packet_set_connection
#define packet_set_encryption_key		ssh_packet_set_encryption_key
#define packet_set_interactive			ssh_packet_set_interactive
#define packet_set_iv				ssh_packet_set_iv
#define packet_set_keycontext			ssh_packet_set_keycontext
#define packet_set_maxsize			ssh_packet_set_maxsize
#define packet_set_nonblocking			ssh_packet_set_nonblocking
#define packet_set_protocol_flags		ssh_packet_set_protocol_flags
#define packet_set_rekey_limit			ssh_packet_set_rekey_limit
#define packet_set_server			ssh_packet_set_server
#define packet_set_state			ssh_packet_set_state
#define packet_set_timeout			ssh_packet_set_timeout
#define packet_start				ssh_packet_start
#define packet_start_compression		ssh_packet_start_compression
#define packet_write_poll			ssh_packet_write_poll
#define packet_write_wait			ssh_packet_write_wait
#define percent_expand				ssh_percent_expand
#define permanently_drop_suid			ssh_permanently_drop_suid
#define permanently_set_uid			ssh_permanently_set_uid
#define prime_test				ssh_prime_test
#define proto_spec				ssh_proto_spec
#define put_host_port				ssh_put_host_port
#define put_u16					ssh_put_u16
#define put_u32					ssh_put_u32
#define put_u64					ssh_put_u64
#define pwcopy					ssh_pwcopy
#define read_keyfile_line			ssh_read_keyfile_line
#define read_passphrase				ssh_read_passphrase
#define refresh_progress_meter			ssh_refresh_progress_meter
#define replacearg				ssh_replacearg
#define restore_uid				ssh_restore_uid
#define resume_in_progress			ssh_resume_in_progress
#define resume_kex				ssh_resume_kex
#define rijndael_decrypt			ssh_rijndael_decrypt
#define rijndael_encrypt			ssh_rijndael_encrypt
#define rijndael_set_key			ssh_rijndael_set_key
#define roaming_read				ssh_roaming_read
#define roaming_write				ssh_roaming_write
#define rsa_generate_additional_parameters	ssh_rsa_generate_additional_parameters
#define rsa_private_decrypt			ssh_rsa_private_decrypt
#define rsa_public_encrypt			ssh_rsa_public_encrypt
#define sanitise_stdfd				ssh_sanitise_stdfd
#define scan_scaled				ssh_scan_scaled
#define schnorr_sign				ssh_schnorr_sign
#define schnorr_verify				ssh_schnorr_verify
#define seed_rng				ssh_seed_rng
#define set_newkeys				ssh_set_newkeys
#define set_nodelay				ssh_set_nodelay
#define set_nonblock				ssh_set_nonblock
#define shadow_pw				ssh_shadow_pw
#define sigdie					ssh_sigdie
#define ssh1_3des_iv				ssh_ssh1_3des_iv
#define start_progress_meter			ssh_start_progress_meter
#define stop_progress_meter			ssh_stop_progress_meter
#define strdelim				ssh_strdelim
#define strnvis					ssh_strnvis
#define strvis					ssh_strvis
#define strvisx					ssh_strvisx
#define sys_tun_open				ssh_sys_tun_open
#define temporarily_use_uid			ssh_temporarily_use_uid
#define tilde_expand_filename			ssh_tilde_expand_filename
#define tohex					ssh_tohex
#define tty_make_modes				ssh_tty_make_modes
#define tty_parse_modes				ssh_tty_parse_modes
#define tun_open				ssh_tun_open
#define umac_ctx				ssh_umac_ctx
#define umac_delete				ssh_umac_delete
#define umac_final				ssh_umac_final
#define umac_new				ssh_umac_new
#define umac_update				ssh_umac_update
#define unset_nonblock				ssh_unset_nonblock
#define uudecode				ssh_uudecode
#define uuencode				ssh_uuencode
#define verbose					ssh_verbose
#define verbose					ssh_verbose
#define verify_host_key_dns			ssh_verify_host_key_dns
#define vis					ssh_vis
#define x11_connect_display			ssh_x11_connect_display
#define x11_create_display_inet			ssh_x11_create_display_inet
#define x11_input_open				ssh_x11_input_open
#define x11_request_forwarding_with_spoofing	ssh_x11_request_forwarding_with_spoofing
#define xasprintf				ssh_xasprintf
#define xcalloc					ssh_xcalloc
#define xcrypt					ssh_xcrypt
#define xfree					ssh_xfree
#define xmalloc					ssh_xmalloc
#define xmmap					ssh_xmmap
#define xrealloc				ssh_xrealloc
#define xstrdup					ssh_xstrdup
