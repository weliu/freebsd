/*-
 * Downloadable microcode for Advanced Systems Inc. SCSI controllers
 *
 *
 * Obtained from:
 * advansys.c - Linux Host Driver for AdvanSys SCSI Adapters
 *
 * Copyright (c) 1995-1999 Advanced System Products, Inc.
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that redistributions of source
 * code retain the above copyright notice and this comment without
 * modification.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/param.h>

u_int8_t adv_mcode[] =
{
	0x01, 0x03, 0x01, 0x19, 0x0F, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x12, 0x0D, 0x05,
	0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xFF, 0x80, 0xFF, 0xFF, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xE4, 0x88, 0x00, 0x00,
	0x00, 0x00, 0x80, 0x73, 0x48, 0x04, 0x36, 0x00, 0x00,
	0xA2, 0xC2, 0x00, 0x80, 0x73, 0x03, 0x23, 0x36, 0x40,
	0xB6, 0x00, 0x36, 0x00, 0x05, 0xD6, 0x0C, 0xD2, 0x12,
	0xDA, 0x00, 0xA2, 0xC2, 0x00, 0x92, 0x80, 0x1E, 0x98,
	0x50, 0x00, 0xF5, 0x00, 0x48, 0x98, 0xDF, 0x23, 0x36,
	0x60, 0xB6, 0x00, 0x92, 0x80, 0x4F, 0x00, 0xF5, 0x00,
	0x48, 0x98, 0xEF, 0x23, 0x36, 0x60, 0xB6, 0x00, 0x92,
	0x80, 0x80, 0x62, 0x92, 0x80, 0x00, 0x46, 0x15, 0xEE,
	0x13, 0xEA, 0x02, 0x01, 0x09, 0xD8, 0xCD, 0x04, 0x4D,
	0x00, 0x00, 0xA3, 0xD6, 0x00, 0xA6, 0x97, 0x7F, 0x23,
	0x04, 0x61, 0x84, 0x01, 0xE6, 0x84, 0xD2, 0xC1, 0x80,
	0x73, 0xCD, 0x04, 0x4D, 0x00, 0x00, 0xA3, 0xDA, 0x01,
	0xA6, 0x97, 0xC6, 0x81, 0xC2, 0x88, 0x80, 0x73, 0x80,
	0x77, 0x00, 0x01, 0x01, 0xA1, 0xFE, 0x00, 0x4F, 0x00,
	0x84, 0x97, 0x07, 0xA6, 0x08, 0x01, 0x00, 0x33, 0x03,
	0x00, 0xC2, 0x88, 0x03, 0x03, 0x01, 0xDE, 0xC2, 0x88,
	0xCE, 0x00, 0x69, 0x60, 0xCE, 0x00, 0x02, 0x03, 0x4A,
	0x60, 0x00, 0xA2, 0x78, 0x01, 0x80, 0x63, 0x07, 0xA6,
	0x24, 0x01, 0x78, 0x81, 0x03, 0x03, 0x80, 0x63, 0xE2,
	0x00, 0x07, 0xA6, 0x34, 0x01, 0x00, 0x33, 0x04, 0x00,
	0xC2, 0x88, 0x03, 0x07, 0x02, 0x01, 0x04, 0xCA, 0x0D,
	0x23, 0x68, 0x98, 0x4D, 0x04, 0x04, 0x85, 0x05, 0xD8,
	0x0D, 0x23, 0x68, 0x98, 0xCD, 0x04, 0x15, 0x23, 0xF8,
	0x88, 0xFB, 0x23, 0x02, 0x61, 0x82, 0x01, 0x80, 0x63,
	0x02, 0x03, 0x06, 0xA3, 0x62, 0x01, 0x00, 0x33, 0x0A,
	0x00, 0xC2, 0x88, 0x4E, 0x00, 0x07, 0xA3, 0x6E, 0x01,
	0x00, 0x33, 0x0B, 0x00, 0xC2, 0x88, 0xCD, 0x04, 0x36,
	0x2D, 0x00, 0x33, 0x1A, 0x00, 0xC2, 0x88, 0x50, 0x04,
	0x88, 0x81, 0x06, 0xAB, 0x82, 0x01, 0x88, 0x81, 0x4E,
	0x00, 0x07, 0xA3, 0x92, 0x01, 0x50, 0x00, 0x00, 0xA3,
	0x3C, 0x01, 0x00, 0x05, 0x7C, 0x81, 0x46, 0x97, 0x02,
	0x01, 0x05, 0xC6, 0x04, 0x23, 0xA0, 0x01, 0x15, 0x23,
	0xA1, 0x01, 0xBE, 0x81, 0xFD, 0x23, 0x02, 0x61, 0x82,
	0x01, 0x0A, 0xDA, 0x4A, 0x00, 0x06, 0x61, 0x00, 0xA0,
	0xB4, 0x01, 0x80, 0x63, 0xCD, 0x04, 0x36, 0x2D, 0x00,
	0x33, 0x1B, 0x00, 0xC2, 0x88, 0x06, 0x23, 0x68, 0x98,
	0xCD, 0x04, 0xE6, 0x84, 0x06, 0x01, 0x00, 0xA2, 0xD4,
	0x01, 0x57, 0x60, 0x00, 0xA0, 0xDA, 0x01, 0xE6, 0x84,
	0x80, 0x23, 0xA0, 0x01, 0xE6, 0x84, 0x80, 0x73, 0x4B,
	0x00, 0x06, 0x61, 0x00, 0xA2, 0x00, 0x02, 0x04, 0x01,
	0x0C, 0xDE, 0x02, 0x01, 0x03, 0xCC, 0x4F, 0x00, 0x84,
	0x97, 0xFC, 0x81, 0x08, 0x23, 0x02, 0x41, 0x82, 0x01,
	0x4F, 0x00, 0x62, 0x97, 0x48, 0x04, 0x84, 0x80, 0xF0,
	0x97, 0x00, 0x46, 0x56, 0x00, 0x03, 0xC0, 0x01, 0x23,
	0xE8, 0x00, 0x81, 0x73, 0x06, 0x29, 0x03, 0x42, 0x06,
	0xE2, 0x03, 0xEE, 0x6B, 0xEB, 0x11, 0x23, 0xF8, 0x88,
	0x04, 0x98, 0xF0, 0x80, 0x80, 0x73, 0x80, 0x77, 0x07,
	0xA4, 0x2A, 0x02, 0x7C, 0x95, 0x06, 0xA6, 0x34, 0x02,
	0x03, 0xA6, 0x4C, 0x04, 0x46, 0x82, 0x04, 0x01, 0x03,
	0xD8, 0xB4, 0x98, 0x6A, 0x96, 0x46, 0x82, 0xFE, 0x95,
	0x80, 0x67, 0x83, 0x03, 0x80, 0x63, 0xB6, 0x2D, 0x02,
	0xA6, 0x6C, 0x02, 0x07, 0xA6, 0x5A, 0x02, 0x06, 0xA6,
	0x5E, 0x02, 0x03, 0xA6, 0x62, 0x02, 0xC2, 0x88, 0x7C,
	0x95, 0x48, 0x82, 0x60, 0x96, 0x48, 0x82, 0x04, 0x23,
	0xA0, 0x01, 0x14, 0x23, 0xA1, 0x01, 0x3C, 0x84, 0x04,
	0x01, 0x0C, 0xDC, 0xE0, 0x23, 0x25, 0x61, 0xEF, 0x00,
	0x14, 0x01, 0x4F, 0x04, 0xA8, 0x01, 0x6F, 0x00, 0xA5,
	0x01, 0x03, 0x23, 0xA4, 0x01, 0x06, 0x23, 0x9C, 0x01,
	0x24, 0x2B, 0x1C, 0x01, 0x02, 0xA6, 0xAA, 0x02, 0x07,
	0xA6, 0x5A, 0x02, 0x06, 0xA6, 0x5E, 0x02, 0x03, 0xA6,
	0x20, 0x04, 0x01, 0xA6, 0xB4, 0x02, 0x00, 0xA6, 0xB4,
	0x02, 0x00, 0x33, 0x12, 0x00, 0xC2, 0x88, 0x00, 0x0E,
	0x80, 0x63, 0x00, 0x43, 0x00, 0xA0, 0x8C, 0x02, 0x4D,
	0x04, 0x04, 0x01, 0x0B, 0xDC, 0xE7, 0x23, 0x04, 0x61,
	0x84, 0x01, 0x10, 0x31, 0x12, 0x35, 0x14, 0x01, 0xEC,
	0x00, 0x6C, 0x38, 0x00, 0x3F, 0x00, 0x00, 0xEA, 0x82,
	0x18, 0x23, 0x04, 0x61, 0x18, 0xA0, 0xE2, 0x02, 0x04,
	0x01, 0xA2, 0xC8, 0x00, 0x33, 0x1F, 0x00, 0xC2, 0x88,
	0x08, 0x31, 0x0A, 0x35, 0x0C, 0x39, 0x0E, 0x3D, 0x7E,
	0x98, 0xB6, 0x2D, 0x01, 0xA6, 0x14, 0x03, 0x00, 0xA6,
	0x14, 0x03, 0x07, 0xA6, 0x0C, 0x03, 0x06, 0xA6, 0x10,
	0x03, 0x03, 0xA6, 0x20, 0x04, 0x02, 0xA6, 0x6C, 0x02,
	0x00, 0x33, 0x33, 0x00, 0xC2, 0x88, 0x7C, 0x95, 0xEE,
	0x82, 0x60, 0x96, 0xEE, 0x82, 0x82, 0x98, 0x80, 0x42,
	0x7E, 0x98, 0x64, 0xE4, 0x04, 0x01, 0x2D, 0xC8, 0x31,
	0x05, 0x07, 0x01, 0x00, 0xA2, 0x54, 0x03, 0x00, 0x43,
	0x87, 0x01, 0x05, 0x05, 0x86, 0x98, 0x7E, 0x98, 0x00,
	0xA6, 0x16, 0x03, 0x07, 0xA6, 0x4C, 0x03, 0x03, 0xA6,
	0x3C, 0x04, 0x06, 0xA6, 0x50, 0x03, 0x01, 0xA6, 0x16,
	0x03, 0x00, 0x33, 0x25, 0x00, 0xC2, 0x88, 0x7C, 0x95,
	0x32, 0x83, 0x60, 0x96, 0x32, 0x83, 0x04, 0x01, 0x10,
	0xCE, 0x07, 0xC8, 0x05, 0x05, 0xEB, 0x04, 0x00, 0x33,
	0x00, 0x20, 0xC0, 0x20, 0x81, 0x62, 0x72, 0x83, 0x00,
	0x01, 0x05, 0x05, 0xFF, 0xA2, 0x7A, 0x03, 0xB1, 0x01,
	0x08, 0x23, 0xB2, 0x01, 0x2E, 0x83, 0x05, 0x05, 0x15,
	0x01, 0x00, 0xA2, 0x9A, 0x03, 0xEC, 0x00, 0x6E, 0x00,
	0x95, 0x01, 0x6C, 0x38, 0x00, 0x3F, 0x00, 0x00, 0x01,
	0xA6, 0x96, 0x03, 0x00, 0xA6, 0x96, 0x03, 0x10, 0x84,
	0x80, 0x42, 0x7E, 0x98, 0x01, 0xA6, 0xA4, 0x03, 0x00,
	0xA6, 0xBC, 0x03, 0x10, 0x84, 0xA8, 0x98, 0x80, 0x42,
	0x01, 0xA6, 0xA4, 0x03, 0x07, 0xA6, 0xB2, 0x03, 0xD4,
	0x83, 0x7C, 0x95, 0xA8, 0x83, 0x00, 0x33, 0x2F, 0x00,
	0xC2, 0x88, 0xA8, 0x98, 0x80, 0x42, 0x00, 0xA6, 0xBC,
	0x03, 0x07, 0xA6, 0xCA, 0x03, 0xD4, 0x83, 0x7C, 0x95,
	0xC0, 0x83, 0x00, 0x33, 0x26, 0x00, 0xC2, 0x88, 0x38,
	0x2B, 0x80, 0x32, 0x80, 0x36, 0x04, 0x23, 0xA0, 0x01,
	0x12, 0x23, 0xA1, 0x01, 0x10, 0x84, 0x07, 0xF0, 0x06,
	0xA4, 0xF4, 0x03, 0x80, 0x6B, 0x80, 0x67, 0x05, 0x23,
	0x83, 0x03, 0x80, 0x63, 0x03, 0xA6, 0x0E, 0x04, 0x07,
	0xA6, 0x06, 0x04, 0x06, 0xA6, 0x0A, 0x04, 0x00, 0x33,
	0x17, 0x00, 0xC2, 0x88, 0x7C, 0x95, 0xF4, 0x83, 0x60,
	0x96, 0xF4, 0x83, 0x20, 0x84, 0x07, 0xF0, 0x06, 0xA4,
	0x20, 0x04, 0x80, 0x6B, 0x80, 0x67, 0x05, 0x23, 0x83,
	0x03, 0x80, 0x63, 0xB6, 0x2D, 0x03, 0xA6, 0x3C, 0x04,
	0x07, 0xA6, 0x34, 0x04, 0x06, 0xA6, 0x38, 0x04, 0x00,
	0x33, 0x30, 0x00, 0xC2, 0x88, 0x7C, 0x95, 0x20, 0x84,
	0x60, 0x96, 0x20, 0x84, 0x1D, 0x01, 0x06, 0xCC, 0x00,
	0x33, 0x00, 0x84, 0xC0, 0x20, 0x00, 0x23, 0xEA, 0x00,
	0x81, 0x62, 0xA2, 0x0D, 0x80, 0x63, 0x07, 0xA6, 0x5A,
	0x04, 0x00, 0x33, 0x18, 0x00, 0xC2, 0x88, 0x03, 0x03,
	0x80, 0x63, 0xA3, 0x01, 0x07, 0xA4, 0x64, 0x04, 0x23,
	0x01, 0x00, 0xA2, 0x86, 0x04, 0x0A, 0xA0, 0x76, 0x04,
	0xE0, 0x00, 0x00, 0x33, 0x1D, 0x00, 0xC2, 0x88, 0x0B,
	0xA0, 0x82, 0x04, 0xE0, 0x00, 0x00, 0x33, 0x1E, 0x00,
	0xC2, 0x88, 0x42, 0x23, 0xF8, 0x88, 0x00, 0x23, 0x22,
	0xA3, 0xE6, 0x04, 0x08, 0x23, 0x22, 0xA3, 0xA2, 0x04,
	0x28, 0x23, 0x22, 0xA3, 0xAE, 0x04, 0x02, 0x23, 0x22,
	0xA3, 0xC4, 0x04, 0x42, 0x23, 0xF8, 0x88, 0x4A, 0x00,
	0x06, 0x61, 0x00, 0xA0, 0xAE, 0x04, 0x45, 0x23, 0xF8,
	0x88, 0x04, 0x98, 0x00, 0xA2, 0xC0, 0x04, 0xB4, 0x98,
	0x00, 0x33, 0x00, 0x82, 0xC0, 0x20, 0x81, 0x62, 0xE8,
	0x81, 0x47, 0x23, 0xF8, 0x88, 0x04, 0x01, 0x0B, 0xDE,
	0x04, 0x98, 0xB4, 0x98, 0x00, 0x33, 0x00, 0x81, 0xC0,
	0x20, 0x81, 0x62, 0x14, 0x01, 0x00, 0xA0, 0x00, 0x02,
	0x43, 0x23, 0xF8, 0x88, 0x04, 0x23, 0xA0, 0x01, 0x44,
	0x23, 0xA1, 0x01, 0x80, 0x73, 0x4D, 0x00, 0x03, 0xA3,
	0xF4, 0x04, 0x00, 0x33, 0x27, 0x00, 0xC2, 0x88, 0x04,
	0x01, 0x04, 0xDC, 0x02, 0x23, 0xA2, 0x01, 0x04, 0x23,
	0xA0, 0x01, 0x04, 0x98, 0x26, 0x95, 0x4B, 0x00, 0xF6,
	0x00, 0x4F, 0x04, 0x4F, 0x00, 0x00, 0xA3, 0x22, 0x05,
	0x00, 0x05, 0x76, 0x00, 0x06, 0x61, 0x00, 0xA2, 0x1C,
	0x05, 0x0A, 0x85, 0x46, 0x97, 0xCD, 0x04, 0x24, 0x85,
	0x48, 0x04, 0x84, 0x80, 0x02, 0x01, 0x03, 0xDA, 0x80,
	0x23, 0x82, 0x01, 0x34, 0x85, 0x02, 0x23, 0xA0, 0x01,
	0x4A, 0x00, 0x06, 0x61, 0x00, 0xA2, 0x40, 0x05, 0x1D,
	0x01, 0x04, 0xD6, 0xFF, 0x23, 0x86, 0x41, 0x4B, 0x60,
	0xCB, 0x00, 0xFF, 0x23, 0x80, 0x01, 0x49, 0x00, 0x81,
	0x01, 0x04, 0x01, 0x02, 0xC8, 0x30, 0x01, 0x80, 0x01,
	0xF7, 0x04, 0x03, 0x01, 0x49, 0x04, 0x80, 0x01, 0xC9,
	0x00, 0x00, 0x05, 0x00, 0x01, 0xFF, 0xA0, 0x60, 0x05,
	0x77, 0x04, 0x01, 0x23, 0xEA, 0x00, 0x5D, 0x00, 0xFE,
	0xC7, 0x00, 0x62, 0x00, 0x23, 0xEA, 0x00, 0x00, 0x63,
	0x07, 0xA4, 0xF8, 0x05, 0x03, 0x03, 0x02, 0xA0, 0x8E,
	0x05, 0xF4, 0x85, 0x00, 0x33, 0x2D, 0x00, 0xC2, 0x88,
	0x04, 0xA0, 0xB8, 0x05, 0x80, 0x63, 0x00, 0x23, 0xDF,
	0x00, 0x4A, 0x00, 0x06, 0x61, 0x00, 0xA2, 0xA4, 0x05,
	0x1D, 0x01, 0x06, 0xD6, 0x02, 0x23, 0x02, 0x41, 0x82,
	0x01, 0x50, 0x00, 0x62, 0x97, 0x04, 0x85, 0x04, 0x23,
	0x02, 0x41, 0x82, 0x01, 0x04, 0x85, 0x08, 0xA0, 0xBE,
	0x05, 0xF4, 0x85, 0x03, 0xA0, 0xC4, 0x05, 0xF4, 0x85,
	0x01, 0xA0, 0xCE, 0x05, 0x88, 0x00, 0x80, 0x63, 0xCC,
	0x86, 0x07, 0xA0, 0xEE, 0x05, 0x5F, 0x00, 0x00, 0x2B,
	0xDF, 0x08, 0x00, 0xA2, 0xE6, 0x05, 0x80, 0x67, 0x80,
	0x63, 0x01, 0xA2, 0x7A, 0x06, 0x7C, 0x85, 0x06, 0x23,
	0x68, 0x98, 0x48, 0x23, 0xF8, 0x88, 0x07, 0x23, 0x80,
	0x00, 0x06, 0x87, 0x80, 0x63, 0x7C, 0x85, 0x00, 0x23,
	0xDF, 0x00, 0x00, 0x63, 0x4A, 0x00, 0x06, 0x61, 0x00,
	0xA2, 0x36, 0x06, 0x1D, 0x01, 0x16, 0xD4, 0xC0, 0x23,
	0x07, 0x41, 0x83, 0x03, 0x80, 0x63, 0x06, 0xA6, 0x1C,
	0x06, 0x00, 0x33, 0x37, 0x00, 0xC2, 0x88, 0x1D, 0x01,
	0x01, 0xD6, 0x20, 0x23, 0x63, 0x60, 0x83, 0x03, 0x80,
	0x63, 0x02, 0x23, 0xDF, 0x00, 0x07, 0xA6, 0x7C, 0x05,
	0xEF, 0x04, 0x6F, 0x00, 0x00, 0x63, 0x4B, 0x00, 0x06,
	0x41, 0xCB, 0x00, 0x52, 0x00, 0x06, 0x61, 0x00, 0xA2,
	0x4E, 0x06, 0x1D, 0x01, 0x03, 0xCA, 0xC0, 0x23, 0x07,
	0x41, 0x00, 0x63, 0x1D, 0x01, 0x04, 0xCC, 0x00, 0x33,
	0x00, 0x83, 0xC0, 0x20, 0x81, 0x62, 0x80, 0x23, 0x07,
	0x41, 0x00, 0x63, 0x80, 0x67, 0x08, 0x23, 0x83, 0x03,
	0x80, 0x63, 0x00, 0x63, 0x01, 0x23, 0xDF, 0x00, 0x06,
	0xA6, 0x84, 0x06, 0x07, 0xA6, 0x7C, 0x05, 0x80, 0x67,
	0x80, 0x63, 0x00, 0x33, 0x00, 0x40, 0xC0, 0x20, 0x81,
	0x62, 0x00, 0x63, 0x00, 0x00, 0xFE, 0x95, 0x83, 0x03,
	0x80, 0x63, 0x06, 0xA6, 0x94, 0x06, 0x07, 0xA6, 0x7C,
	0x05, 0x00, 0x00, 0x01, 0xA0, 0x14, 0x07, 0x00, 0x2B,
	0x40, 0x0E, 0x80, 0x63, 0x01, 0x00, 0x06, 0xA6, 0xAA,
	0x06, 0x07, 0xA6, 0x7C, 0x05, 0x40, 0x0E, 0x80, 0x63,
	0x00, 0x43, 0x00, 0xA0, 0xA2, 0x06, 0x06, 0xA6, 0xBC,
	0x06, 0x07, 0xA6, 0x7C, 0x05, 0x80, 0x67, 0x40, 0x0E,
	0x80, 0x63, 0x07, 0xA6, 0x7C, 0x05, 0x00, 0x23, 0xDF,
	0x00, 0x00, 0x63, 0x07, 0xA6, 0xD6, 0x06, 0x00, 0x33,
	0x2A, 0x00, 0xC2, 0x88, 0x03, 0x03, 0x80, 0x63, 0x89,
	0x00, 0x0A, 0x2B, 0x07, 0xA6, 0xE8, 0x06, 0x00, 0x33,
	0x29, 0x00, 0xC2, 0x88, 0x00, 0x43, 0x00, 0xA2, 0xF4,
	0x06, 0xC0, 0x0E, 0x80, 0x63, 0xDE, 0x86, 0xC0, 0x0E,
	0x00, 0x33, 0x00, 0x80, 0xC0, 0x20, 0x81, 0x62, 0x04,
	0x01, 0x02, 0xDA, 0x80, 0x63, 0x7C, 0x85, 0x80, 0x7B,
	0x80, 0x63, 0x06, 0xA6, 0x8C, 0x06, 0x00, 0x33, 0x2C,
	0x00, 0xC2, 0x88, 0x0C, 0xA2, 0x2E, 0x07, 0xFE, 0x95,
	0x83, 0x03, 0x80, 0x63, 0x06, 0xA6, 0x2C, 0x07, 0x07,
	0xA6, 0x7C, 0x05, 0x00, 0x33, 0x3D, 0x00, 0xC2, 0x88,
	0x00, 0x00, 0x80, 0x67, 0x83, 0x03, 0x80, 0x63, 0x0C,
	0xA0, 0x44, 0x07, 0x07, 0xA6, 0x7C, 0x05, 0xBF, 0x23,
	0x04, 0x61, 0x84, 0x01, 0xE6, 0x84, 0x00, 0x63, 0xF0,
	0x04, 0x01, 0x01, 0xF1, 0x00, 0x00, 0x01, 0xF2, 0x00,
	0x01, 0x05, 0x80, 0x01, 0x72, 0x04, 0x71, 0x00, 0x81,
	0x01, 0x70, 0x04, 0x80, 0x05, 0x81, 0x05, 0x00, 0x63,
	0xF0, 0x04, 0xF2, 0x00, 0x72, 0x04, 0x01, 0x01, 0xF1,
	0x00, 0x70, 0x00, 0x81, 0x01, 0x70, 0x04, 0x71, 0x00,
	0x81, 0x01, 0x72, 0x00, 0x80, 0x01, 0x71, 0x04, 0x70,
	0x00, 0x80, 0x01, 0x70, 0x04, 0x00, 0x63, 0xF0, 0x04,
	0xF2, 0x00, 0x72, 0x04, 0x00, 0x01, 0xF1, 0x00, 0x70,
	0x00, 0x80, 0x01, 0x70, 0x04, 0x71, 0x00, 0x80, 0x01,
	0x72, 0x00, 0x81, 0x01, 0x71, 0x04, 0x70, 0x00, 0x81,
	0x01, 0x70, 0x04, 0x00, 0x63, 0x00, 0x23, 0xB3, 0x01,
	0x83, 0x05, 0xA3, 0x01, 0xA2, 0x01, 0xA1, 0x01, 0x01,
	0x23, 0xA0, 0x01, 0x00, 0x01, 0xC8, 0x00, 0x03, 0xA1,
	0xC4, 0x07, 0x00, 0x33, 0x07, 0x00, 0xC2, 0x88, 0x80,
	0x05, 0x81, 0x05, 0x04, 0x01, 0x11, 0xC8, 0x48, 0x00,
	0xB0, 0x01, 0xB1, 0x01, 0x08, 0x23, 0xB2, 0x01, 0x05,
	0x01, 0x48, 0x04, 0x00, 0x43, 0x00, 0xA2, 0xE4, 0x07,
	0x00, 0x05, 0xDA, 0x87, 0x00, 0x01, 0xC8, 0x00, 0xFF,
	0x23, 0x80, 0x01, 0x05, 0x05, 0x00, 0x63, 0xF7, 0x04,
	0x1A, 0x09, 0xF6, 0x08, 0x6E, 0x04, 0x00, 0x02, 0x80,
	0x43, 0x76, 0x08, 0x80, 0x02, 0x77, 0x04, 0x00, 0x63,
	0xF7, 0x04, 0x1A, 0x09, 0xF6, 0x08, 0x6E, 0x04, 0x00,
	0x02, 0x00, 0xA0, 0x14, 0x08, 0x16, 0x88, 0x00, 0x43,
	0x76, 0x08, 0x80, 0x02, 0x77, 0x04, 0x00, 0x63, 0xF3,
	0x04, 0x00, 0x23, 0xF4, 0x00, 0x74, 0x00, 0x80, 0x43,
	0xF4, 0x00, 0xCF, 0x40, 0x00, 0xA2, 0x44, 0x08, 0x74,
	0x04, 0x02, 0x01, 0xF7, 0xC9, 0xF6, 0xD9, 0x00, 0x01,
	0x01, 0xA1, 0x24, 0x08, 0x04, 0x98, 0x26, 0x95, 0x24,
	0x88, 0x73, 0x04, 0x00, 0x63, 0xF3, 0x04, 0x75, 0x04,
	0x5A, 0x88, 0x02, 0x01, 0x04, 0xD8, 0x46, 0x97, 0x04,
	0x98, 0x26, 0x95, 0x4A, 0x88, 0x75, 0x00, 0x00, 0xA3,
	0x64, 0x08, 0x00, 0x05, 0x4E, 0x88, 0x73, 0x04, 0x00,
	0x63, 0x80, 0x7B, 0x80, 0x63, 0x06, 0xA6, 0x76, 0x08,
	0x00, 0x33, 0x3E, 0x00, 0xC2, 0x88, 0x80, 0x67, 0x83,
	0x03, 0x80, 0x63, 0x00, 0x63, 0x38, 0x2B, 0x9C, 0x88,
	0x38, 0x2B, 0x92, 0x88, 0x32, 0x09, 0x31, 0x05, 0x92,
	0x98, 0x05, 0x05, 0xB2, 0x09, 0x00, 0x63, 0x00, 0x32,
	0x00, 0x36, 0x00, 0x3A, 0x00, 0x3E, 0x00, 0x63, 0x80,
	0x32, 0x80, 0x36, 0x80, 0x3A, 0x80, 0x3E, 0xB4, 0x3D,
	0x00, 0x63, 0x38, 0x2B, 0x40, 0x32, 0x40, 0x36, 0x40,
	0x3A, 0x40, 0x3E, 0x00, 0x63, 0x5A, 0x20, 0xC9, 0x40,
	0x00, 0xA0, 0xB4, 0x08, 0x5D, 0x00, 0xFE, 0xC3, 0x00,
	0x63, 0x80, 0x73, 0xE6, 0x20, 0x02, 0x23, 0xE8, 0x00,
	0x82, 0x73, 0xFF, 0xFD, 0x80, 0x73, 0x13, 0x23, 0xF8,
	0x88, 0x66, 0x20, 0xC0, 0x20, 0x04, 0x23, 0xA0, 0x01,
	0xA1, 0x23, 0xA1, 0x01, 0x81, 0x62, 0xE2, 0x88, 0x80,
	0x73, 0x80, 0x77, 0x68, 0x00, 0x00, 0xA2, 0x80, 0x00,
	0x03, 0xC2, 0xF1, 0xC7, 0x41, 0x23, 0xF8, 0x88, 0x11,
	0x23, 0xA1, 0x01, 0x04, 0x23, 0xA0, 0x01, 0xE6, 0x84
};

u_int16_t adv_mcode_size = sizeof(adv_mcode);
u_int32_t adv_mcode_chksum = 0x012C453F;
