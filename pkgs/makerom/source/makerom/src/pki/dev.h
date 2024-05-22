#pragma once
#include "rsa_key.h"

#ifdef PKI_LEGACY
#include "pki/dev_legacy.h"
#endif

// AES KEYS
static const unsigned char dev_unfixed_ncch_keyX[4][16] =
{
	{ 0x51, 0x02, 0x07, 0x51, 0x55, 0x07, 0xcb, 0xb1, 0x8e, 0x24, 0x3d, 0xcb, 0x85, 0xe2, 0x3a, 0x1d }, // Regular
	{ 0x81, 0x90, 0x7a, 0x4b, 0x6f, 0x1b, 0x47, 0x32, 0x3a, 0x67, 0x79, 0x74, 0xce, 0x4a, 0xd7, 0x1b }, // >=7.0
	{ 0x30, 0x4b, 0xf1, 0x46, 0x83, 0x72, 0xee, 0x64, 0x11, 0x5e, 0xbd, 0x40, 0x93, 0xd8, 0x42, 0x76 }, // >=9.3 (New3DS)
	{ 0x6c, 0x8b, 0x29, 0x44, 0xa0, 0x72, 0x60, 0x35, 0xf9, 0x41, 0xdf, 0xc0, 0x18, 0x52, 0x4f, 0xb6 }  // >=9.6 (New3DS)
};

static const unsigned char dev_fixed_ncch_key[2][16] =
{
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // Normal FixedKey
	{0x52, 0x7C, 0xE6, 0x30, 0xA9, 0xCA, 0x30, 0x5F, 0x36, 0x96, 0xF3, 0xCD, 0xE9, 0x54, 0x19, 0x4B}  // System FixedKey
};

static const unsigned char ctr_common_etd_key_dpki[6][16] =
{
	{ 0x55, 0xA3, 0xF8, 0x72, 0xBD, 0xC8, 0x0C, 0x55, 0x5A, 0x65, 0x43, 0x81, 0x13, 0x9E, 0x15, 0x3B }, // 0 - eShop Titles
	{ 0x44, 0x34, 0xED, 0x14, 0x82, 0x0C, 0xA1, 0xEB, 0xAB, 0x82, 0xC1, 0x6E, 0x7B, 0xEF, 0x0C, 0x25 }, // 1 - System Titles
	{ 0xF6, 0x2E, 0x3F, 0x95, 0x8E, 0x28, 0xA2, 0x1F, 0x28, 0x9E, 0xEC, 0x71, 0xA8, 0x66, 0x29, 0xDC },
	{ 0x2B, 0x49, 0xCB, 0x6F, 0x99, 0x98, 0xD9, 0xAD, 0x94, 0xF2, 0xED, 0xE7, 0xB5, 0xDA, 0x3E, 0x27 },
	{ 0x75, 0x05, 0x52, 0xBF, 0xAA, 0x1C, 0x04, 0x07, 0x55, 0xC8, 0xD5, 0x9A, 0x55, 0xF9, 0xAD, 0x1F },
	{ 0xAA, 0xDA, 0x4C, 0xA8, 0xF6, 0xE5, 0xA9, 0x77, 0xE0, 0xA0, 0xF9, 0xE4, 0x76, 0xCF, 0x0D, 0x63 }
};

static const unsigned char dev_initial_data_keyx[16] =
{
	0x5C, 0x3D, 0x38, 0xAC, 0x17, 0x40, 0x99, 0x4E, 0xFC, 0x8F, 0xD0, 0xBE, 0x8D, 0x80, 0x97, 0xB3
};

//RSA Keys
static const CtrRsa4096Key root_dpki_rsa =
{
	.modulus = { 0xD0, 0x1F, 0xE1, 0x00, 0xD4, 0x35, 0x56, 0xB2, 0x4B, 0x56, 0xDA, 0xE9, 0x71, 0xB5, 0xA5, 0xD3, 0x84, 0xB9, 0x30, 0x03, 0xBE, 0x1B, 0xBF, 0x28, 0xA2, 0x30, 0x5B, 0x06, 0x06, 0x45, 0x46, 0x7D, 0x5B, 0x02, 0x51, 0xD2, 0x56, 0x1A, 0x27, 0x4F, 0x9E, 0x9F, 0x9C, 0xEC, 0x64, 0x61, 0x50, 0xAB, 0x3D, 0x2A, 0xE3, 0x36, 0x68, 0x66, 0xAC, 0xA4, 0xBA, 0xE8, 0x1A, 0xE3, 0xD7, 0x9A, 0xA6, 0xB0, 0x4A, 0x8B, 0xCB, 0xA7, 0xE6, 0xFB, 0x64, 0x89, 0x45, 0xEB, 0xDF, 0xDB, 0x85, 0xBA, 0x09, 0x1F, 0xD7, 0xD1, 0x14, 0xB5, 0xA3, 0xA7, 0x80, 0xE3, 0xA2, 0x2E, 0x6E, 0xCD, 0x87, 0xB5, 0xA4, 0xC6, 0xF9, 0x10, 0xE4, 0x03, 0x22, 0x08, 0x81, 0x4B, 0x0C, 0xEE, 0xA1, 0xA1, 0x7D, 0xF7, 0x39, 0x69, 0x5F, 0x61, 0x7E, 0xF6, 0x35, 0x28, 0xDB, 0x94, 0x96, 0x37, 0xA0, 0x56, 0x03, 0x7F, 0x7B, 0x32, 0x41, 0x38, 0x95, 0xC0, 0xA8, 0xF1, 0x98, 0x2E, 0x15, 0x65, 0xE3, 0x8E, 0xED, 0xC2, 0x2E, 0x59, 0x0E, 0xE2, 0x67, 0x7B, 0x86, 0x09, 0xF4, 0x8C, 0x2E, 0x30, 0x3F, 0xBC, 0x40, 0x5C, 0xAC, 0x18, 0x04, 0x2F, 0x82, 0x20, 0x84, 0xE4, 0x93, 0x68, 0x03, 0xDA, 0x7F, 0x41, 0x34, 0x92, 0x48, 0x56, 0x2B, 0x8E, 0xE1, 0x2F, 0x78, 0xF8, 0x03, 0x24, 0x63, 0x30, 0xBC, 0x7B, 0xE7, 0xEE, 0x72, 0x4A, 0xF4, 0x58, 0xA4, 0x72, 0xE7, 0xAB, 0x46, 0xA1, 0xA7, 0xC1, 0x0C, 0x2F, 0x18, 0xFA, 0x07, 0xC3, 0xDD, 0xD8, 0x98, 0x06, 0xA1, 0x1C, 0x9C, 0xC1, 0x30, 0xB2, 0x47, 0xA3, 0x3C, 0x8D, 0x47, 0xDE, 0x67, 0xF2, 0x9E, 0x55, 0x77, 0xB1, 0x1C, 0x43, 0x49, 0x3D, 0x5B, 0xBA, 0x76, 0x34, 0xA7, 0xE4, 0xE7, 0x15, 0x31, 0xB7, 0xDF, 0x59, 0x81, 0xFE, 0x24, 0xA1, 0x14, 0x55, 0x4C, 0xBD, 0x8F, 0x00, 0x5C, 0xE1, 0xDB, 0x35, 0x08, 0x5C, 0xCF, 0xC7, 0x78, 0x06, 0xB6, 0xDE, 0x25, 0x40, 0x68, 0xA2, 0x6C, 0xB5, 0x49, 0x2D, 0x45, 0x80, 0x43, 0x8F, 0xE1, 0xE5, 0xA9, 0xED, 0x75, 0xC5, 0xED, 0x45, 0x1D, 0xCE, 0x78, 0x94, 0x39, 0xCC, 0xC3, 0xBA, 0x28, 0xA2, 0x31, 0x2A, 0x1B, 0x87, 0x19, 0xEF, 0x0F, 0x73, 0xB7, 0x13, 0x95, 0x0C, 0x02, 0x59, 0x1A, 0x74, 0x62, 0xA6, 0x07, 0xF3, 0x7C, 0x0A, 0xA7, 0xA1, 0x8F, 0xA9, 0x43, 0xA3, 0x6D, 0x75, 0x2A, 0x5F, 0x41, 0x92, 0xF0, 0x13, 0x61, 0x00, 0xAA, 0x9C, 0xB4, 0x1B, 0xBE, 0x14, 0xBE, 0xB1, 0xF9, 0xFC, 0x69, 0x2F, 0xDF, 0xA0, 0x94, 0x46, 0xDE, 0x5A, 0x9D, 0xDE, 0x2C, 0xA5, 0xF6, 0x8C, 0x1C, 0x0C, 0x21, 0x42, 0x92, 0x87, 0xCB, 0x2D, 0xAA, 0xA3, 0xD2, 0x63, 0x75, 0x2F, 0x73, 0xE0, 0x9F, 0xAF, 0x44, 0x79, 0xD2, 0x81, 0x74, 0x29, 0xF6, 0x98, 0x00, 0xAF, 0xDE, 0x6B, 0x59, 0x2D, 0xC1, 0x98, 0x82, 0xBD, 0xF5, 0x81, 0xCC, 0xAB, 0xF2, 0xCB, 0x91, 0x02, 0x9E, 0xF3, 0x5C, 0x4C, 0xFD, 0xBB, 0xFF, 0x49, 0xC1, 0xFA, 0x1B, 0x2F, 0xE3, 0x1D, 0xE7, 0xA5, 0x60, 0xEC, 0xB4, 0x7E, 0xBC, 0xFE, 0x32, 0x42, 0x5B, 0x95, 0x6F, 0x81, 0xB6, 0x99, 0x17, 0x48, 0x7E, 0x3B, 0x78, 0x91, 0x51, 0xDB, 0x2E, 0x78, 0xB1, 0xFD, 0x2E, 0xBE, 0x7E, 0x62, 0x6B, 0x3E, 0xA1, 0x65, 0xB4, 0xFB, 0x00, 0xCC, 0xB7, 0x51, 0xAF, 0x50, 0x73, 0x29, 0xC4, 0xA3, 0x93, 0x9E, 0xA6, 0xDD, 0x9C, 0x50, 0xA0, 0xE7, 0x38, 0x6B, 0x01, 0x45, 0x79, 0x6B, 0x41, 0xAF, 0x61, 0xF7, 0x85, 0x55, 0x94, 0x4F, 0x3B, 0xC2, 0x2D, 0xC3, 0xBD, 0x0D, 0x00, 0xF8, 0x79, 0x8A, 0x42, 0xB1, 0xAA, 0xA0, 0x83, 0x20, 0x65, 0x9A, 0xC7, 0x39, 0x5A, 0xB4, 0xF3, 0x29 },
	.priv_exponent = {0}
};

static const CtrRsa2048Key cpA_dpki_rsa = 
{
	.modulus = { 0xAA, 0x7F, 0x93, 0x80, 0x28, 0x9B, 0xE8, 0x98, 0x63, 0x10, 0x7A, 0xE1, 0x0C, 0x59, 0x2C, 0x2F, 0x7C, 0xFF, 0xBD, 0xAA, 0xDD, 0x74, 0xF4, 0xA2, 0xFB, 0xAC, 0xD7, 0x6F, 0x00, 0x93, 0x42, 0x06, 0x34, 0x71, 0x56, 0xD8, 0x40, 0x49, 0x72, 0x9F, 0x3E, 0x24, 0xFA, 0x5E, 0x19, 0xD1, 0x5B, 0x63, 0x5C, 0xD2, 0xEF, 0x09, 0xDE, 0x32, 0xEE, 0x6B, 0x6F, 0xC8, 0xFA, 0x32, 0x8E, 0x2E, 0x96, 0xB9, 0x94, 0x41, 0x04, 0x7D, 0x07, 0x62, 0x95, 0xDA, 0x0D, 0x91, 0xD8, 0x09, 0x35, 0xD0, 0xDE, 0x8E, 0x6B, 0xC6, 0xAB, 0x14, 0x27, 0x01, 0x9C, 0xFE, 0x49, 0x96, 0xFC, 0x9B, 0x54, 0x79, 0x4D, 0xEB, 0xD7, 0xC6, 0x66, 0x73, 0xA6, 0xDD, 0x3A, 0x77, 0x65, 0x47, 0x94, 0xEC, 0x1C, 0x87, 0xAA, 0x46, 0xD9, 0x78, 0xA9, 0x7D, 0xDB, 0x11, 0x22, 0x6E, 0xD4, 0x12, 0xC2, 0x78, 0x4B, 0x21, 0x83, 0x92, 0xC7, 0x10, 0xC7, 0x74, 0x19, 0xFF, 0xAA, 0xF6, 0x0B, 0x75, 0xD8, 0x23, 0xDD, 0x33, 0xC3, 0xA1, 0x5B, 0xA7, 0x2D, 0x30, 0xA5, 0xA4, 0xD8, 0xF8, 0x0F, 0xD6, 0x73, 0xFD, 0x26, 0xCB, 0x29, 0xA6, 0xEF, 0x50, 0x39, 0xE2, 0x5F, 0x59, 0x61, 0x84, 0x6B, 0xDA, 0x2E, 0xC7, 0xCB, 0xE4, 0x38, 0x4B, 0x28, 0xFB, 0x0D, 0xD5, 0x8E, 0x7C, 0xAA, 0x7D, 0x4B, 0x37, 0x3A, 0xD7, 0x81, 0xDD, 0x73, 0xE3, 0x09, 0x93, 0xBD, 0xBD, 0x7E, 0x08, 0x55, 0x4A, 0x8C, 0xA5, 0xC9, 0x84, 0x2D, 0x71, 0x01, 0xA2, 0x2A, 0x01, 0xB0, 0x15, 0xFB, 0x30, 0x78, 0xB9, 0x13, 0xF4, 0xC7, 0x3F, 0xB5, 0xA6, 0xF1, 0xA2, 0x5E, 0x22, 0xB0, 0x02, 0xB6, 0xE0, 0x09, 0x54, 0x7F, 0x0F, 0xBD, 0xF0, 0xFE, 0xA5, 0x50, 0x1D, 0x93, 0x15, 0xF9, 0x3D, 0x83, 0x0F, 0x0F, 0x0E, 0x3D, 0xE2, 0x3D, 0x96, 0xE7, 0x09, 0xD9, 0x77 },
	.priv_exponent = { 0x28, 0xCE, 0xDC, 0x39, 0x02, 0x7F, 0x3E, 0x8E, 0xAA, 0xB7, 0x59, 0x11, 0xE0, 0x68, 0xBF, 0x80, 0xA6, 0x44, 0x77, 0xDB, 0x1B, 0xA2, 0x50, 0xA3, 0x69, 0xE5, 0x96, 0xB2, 0xC4, 0xCA, 0x7A, 0x35, 0x0D, 0xFC, 0x4A, 0xB2, 0xFB, 0xC0, 0x18, 0xA5, 0x30, 0xB4, 0x9D, 0x10, 0x44, 0xD1, 0xAD, 0x33, 0xFD, 0x15, 0xA7, 0x8D, 0x0F, 0x17, 0xD5, 0xA4, 0xF5, 0x5E, 0x7F, 0x33, 0xF6, 0x80, 0x04, 0x27, 0x6A, 0xEA, 0x9C, 0xEE, 0x68, 0x04, 0x1A, 0xA5, 0xD4, 0x35, 0xA2, 0x25, 0xA2, 0x31, 0xD9, 0xF2, 0xF0, 0xAC, 0xDE, 0x69, 0xB6, 0x64, 0x56, 0x75, 0x2E, 0x9B, 0xEA, 0xDE, 0x2A, 0xBB, 0xD6, 0x00, 0xAA, 0xE6, 0x9B, 0xC2, 0xF6, 0x9F, 0x60, 0xCD, 0x0E, 0xFA, 0xB1, 0x14, 0x4A, 0x47, 0xD6, 0x63, 0x9A, 0xCD, 0x9C, 0x93, 0xB9, 0x09, 0x42, 0xDA, 0x8F, 0xFB, 0xE5, 0x7B, 0xF1, 0x4F, 0x96, 0x33, 0xF9, 0x45, 0x5B, 0xCC, 0x84, 0xAB, 0xC2, 0xD8, 0xC4, 0x0C, 0x85, 0xFA, 0x51, 0x28, 0xB9, 0x97, 0x95, 0x23, 0x8C, 0xB3, 0x1D, 0x4E, 0xB6, 0x1C, 0xCC, 0x60, 0x41, 0xFB, 0x26, 0xC7, 0xD6, 0xCB, 0x77, 0x18, 0xF7, 0xEA, 0xCD, 0x10, 0x3C, 0x5B, 0xA3, 0xC0, 0x77, 0x4C, 0x11, 0xF3, 0x74, 0x50, 0xEE, 0x23, 0x80, 0xC4, 0x5D, 0xDD, 0x57, 0xF5, 0x7D, 0x49, 0x57, 0x4A, 0xBA, 0x62, 0xBF, 0x06, 0xD9, 0xD1, 0x7F, 0x91, 0x10, 0x89, 0x6F, 0x49, 0x09, 0xD7, 0xE9, 0xAF, 0x4C, 0x9F, 0x67, 0x9D, 0x89, 0x82, 0xE4, 0xD5, 0xC1, 0x9A, 0xDC, 0x55, 0x79, 0xE7, 0xE9, 0x2D, 0x81, 0x42, 0x14, 0x55, 0x61, 0x47, 0x9B, 0xED, 0x76, 0x92, 0x1D, 0x2F, 0xB5, 0x7C, 0x28, 0x4B, 0xFF, 0x7B, 0xC2, 0x3B, 0x36, 0x73, 0x99, 0xA6, 0x21, 0x43, 0x0E, 0xA1, 0x1F, 0x82, 0xB8, 0x91, 0x71, 0x11, 0xB2, 0xC1 }
};

static const CtrRsa2048Key xs9_dpki_rsa =
{
	.modulus = { 0xC0, 0x84, 0x4C, 0xEB, 0x7E, 0xB0, 0xCF, 0xF0, 0xAE, 0xB7, 0x77, 0x69, 0x85, 0x93, 0xE4, 0x99, 0x5A, 0x95, 0x4E, 0x58, 0x17, 0x38, 0xCE, 0xD6, 0x81, 0xB0, 0xBD, 0x77, 0x09, 0xE7, 0xF8, 0x9A, 0xDF, 0xAD, 0x05, 0x48, 0x83, 0xF6, 0xC3, 0xFD, 0xDF, 0x7B, 0x83, 0xE0, 0x0C, 0x26, 0x81, 0x54, 0x43, 0x29, 0xEA, 0x82, 0x6C, 0x89, 0xF0, 0xA6, 0x74, 0x42, 0x86, 0x4D, 0x32, 0x60, 0x32, 0x7D, 0xA7, 0x7A, 0x13, 0x40, 0x66, 0x59, 0xDA, 0x3E, 0x41, 0x6B, 0x27, 0x94, 0x03, 0x4F, 0xAA, 0x22, 0x9D, 0xD5, 0x54, 0x52, 0xDB, 0x27, 0x0A, 0x6A, 0xA2, 0x3D, 0x19, 0xB1, 0x66, 0x1B, 0x19, 0x7D, 0xAB, 0xC7, 0x0E, 0x88, 0x17, 0x91, 0xA1, 0x2A, 0xB4, 0x3C, 0x6C, 0xCB, 0xF5, 0xAA, 0x7C, 0x3A, 0xDD, 0x36, 0xFB, 0x35, 0x71, 0x7B, 0x20, 0x01, 0x59, 0x00, 0xD6, 0xF6, 0x90, 0x39, 0x35, 0x41, 0x31, 0xF8, 0xC1, 0xC0, 0x57, 0x3A, 0x35, 0x18, 0x58, 0x90, 0xB1, 0xAD, 0x9A, 0x0E, 0xEC, 0xE0, 0xF4, 0x7A, 0x7D, 0xA5, 0x27, 0x48, 0xC9, 0x72, 0xAB, 0x0D, 0x08, 0x7B, 0x62, 0x35, 0x40, 0x91, 0x14, 0x2B, 0xB1, 0x1D, 0x1A, 0xFA, 0xF9, 0xCD, 0x5C, 0x17, 0x13, 0x53, 0x52, 0x71, 0xCA, 0xE2, 0x2A, 0x78, 0xB1, 0x7F, 0x4A, 0xCD, 0x59, 0xD8, 0xBA, 0x1D, 0x7D, 0x70, 0x5F, 0x78, 0x1B, 0x9F, 0x9D, 0x37, 0x18, 0x8E, 0xD7, 0xCD, 0x0D, 0x49, 0x57, 0x74, 0x69, 0x88, 0x3A, 0x6B, 0x8E, 0x4E, 0x1B, 0x85, 0xDD, 0xBE, 0x39, 0x45, 0x05, 0x89, 0x56, 0x12, 0x97, 0x59, 0x9A, 0x09, 0xA4, 0xC8, 0x2D, 0x2F, 0xF5, 0xCF, 0xB4, 0x73, 0x70, 0xDB, 0x58, 0x1E, 0xB2, 0x4E, 0x77, 0x6F, 0xA4, 0x7E, 0x62, 0xDF, 0xB7, 0x05, 0xE8, 0x80, 0x42, 0x5C, 0xB8, 0x78, 0x87, 0x97, 0x7F, 0x66, 0x2C, 0x5F },
	.priv_exponent = { 0x74, 0xCB, 0xCF, 0x1E, 0xD0, 0x2D, 0xD4, 0xF9, 0xE0, 0x05, 0xCE, 0x9C, 0x66, 0x3D, 0xE3, 0x62, 0x66, 0x62, 0x4E, 0xB5, 0x82, 0xE1, 0x24, 0x1B, 0x5F, 0x73, 0x2A, 0x7F, 0x1D, 0xB3, 0x6E, 0x50, 0x07, 0x83, 0xA0, 0xC0, 0xED, 0xCE, 0xB7, 0xF9, 0x3D, 0xAC, 0x61, 0xC5, 0x7B, 0x99, 0xA0, 0xBC, 0xCE, 0x42, 0x8F, 0xD3, 0xB0, 0xA5, 0xBF, 0x2A, 0x3D, 0x3E, 0x5E, 0xDC, 0x56, 0xC3, 0xA5, 0xDE, 0x35, 0xCD, 0x0A, 0x00, 0xF8, 0x17, 0x6B, 0x20, 0x79, 0xEF, 0xD8, 0x83, 0x23, 0xBF, 0x21, 0x28, 0xFF, 0x38, 0x7D, 0x80, 0x07, 0x15, 0x18, 0x6C, 0xB9, 0x20, 0xF8, 0x85, 0x77, 0xBC, 0xD9, 0x2A, 0x35, 0x1C, 0xFE, 0xE3, 0xF1, 0xE8, 0x98, 0x2E, 0xA0, 0x4A, 0x48, 0x77, 0x35, 0x03, 0xC9, 0x7A, 0xAC, 0xDA, 0xBE, 0x6D, 0x1D, 0xFB, 0xE4, 0xDE, 0xEC, 0x70, 0x65, 0xFA, 0x10, 0x65, 0xA4, 0xB8, 0x6A, 0xDF, 0x32, 0x6B, 0x8E, 0x28, 0x79, 0x25, 0x87, 0x72, 0xC0, 0x7C, 0x5B, 0x81, 0xBC, 0x81, 0x92, 0x44, 0x7D, 0xEA, 0x61, 0xBD, 0x3C, 0x48, 0xF3, 0x0E, 0x18, 0xDC, 0x8D, 0x89, 0xA0, 0x34, 0xC3, 0xAE, 0x9C, 0x57, 0x72, 0xA6, 0xD7, 0x7C, 0x79, 0xF7, 0xE9, 0x14, 0x6E, 0x15, 0xAC, 0x01, 0xFA, 0xFF, 0xC8, 0xA2, 0x2A, 0x3A, 0xAB, 0x24, 0x3C, 0x7E, 0x2E, 0xC5, 0xDA, 0x83, 0xD5, 0x9D, 0x24, 0x10, 0x83, 0x7A, 0xF4, 0xBB, 0xA3, 0x6F, 0x88, 0xCE, 0xEC, 0x24, 0x1B, 0xF4, 0x36, 0x2E, 0x96, 0xC9, 0x6D, 0x19, 0x02, 0xFE, 0xAA, 0x21, 0x3E, 0x95, 0xA7, 0xFE, 0x83, 0xC8, 0x99, 0x7F, 0xD1, 0xCB, 0x7C, 0x1F, 0x91, 0x30, 0xDB, 0xA4, 0xD3, 0xDD, 0xDA, 0x9B, 0x12, 0x4E, 0x24, 0xD1, 0xA5, 0x6F, 0x15, 0xFC, 0x2C, 0x72, 0x98, 0x2C, 0x89, 0xC5, 0x7D, 0x89, 0xDE, 0x2B, 0x4E, 0x01 }
};

static const CtrRsa2048Key dev_ncsd_cfa_rsa =
{
	.modulus = { 0xB9, 0x0C, 0xC4, 0xC6, 0x78, 0xF8, 0x6E, 0x30, 0x05, 0x28, 0xC1, 0xCB, 0xD2, 0xCF, 0xA7, 0x80, 0x5C, 0x57, 0x4D, 0x16, 0x9C, 0xAF, 0xA6, 0xCD, 0x01, 0xBB, 0x83, 0x33, 0xAD, 0x03, 0xBB, 0x06, 0x63, 0xD8, 0x17, 0xF5, 0xE3, 0xDF, 0xDA, 0x0D, 0x3B, 0x86, 0x0E, 0xA2, 0x80, 0x47, 0x94, 0x44, 0x6F, 0xD9, 0x97, 0x7E, 0x78, 0x6A, 0xC3, 0x93, 0x93, 0xEF, 0x02, 0xFC, 0x22, 0x9F, 0x80, 0x77, 0x8C, 0x70, 0x92, 0x1C, 0x43, 0xB1, 0x37, 0x4C, 0x76, 0xE0, 0x57, 0x3B, 0xAB, 0x89, 0xFF, 0xEF, 0xE5, 0xBB, 0x3E, 0xAB, 0x91, 0x39, 0xB8, 0xD9, 0x66, 0x0B, 0x64, 0x28, 0x91, 0x92, 0xE9, 0xD0, 0xB3, 0xDF, 0xD1, 0x4B, 0xC1, 0x73, 0xB5, 0x3F, 0x56, 0xA0, 0x40, 0x10, 0xFE, 0x15, 0x2B, 0x1F, 0xA2, 0x7A, 0xDE, 0x31, 0xB0, 0x26, 0x40, 0xC3, 0x57, 0xFD, 0x35, 0xCB, 0xF0, 0xFA, 0xFF, 0xFB, 0x6F, 0xDB, 0xCD, 0x34, 0x1D, 0x51, 0x2D, 0x2D, 0x81, 0x18, 0xFF, 0x0C, 0x08, 0x51, 0xD5, 0xB4, 0x4B, 0x56, 0x16, 0x02, 0x9F, 0x4E, 0x6A, 0xDF, 0x06, 0x6E, 0xCB, 0x72, 0x85, 0xE9, 0x2E, 0x43, 0xA2, 0x08, 0x78, 0x0C, 0x38, 0x9C, 0x19, 0xBD, 0x7B, 0x74, 0x74, 0x68, 0xC4, 0x2D, 0xC1, 0x35, 0x9E, 0x65, 0x3B, 0xD8, 0x99, 0x04, 0x1C, 0x8B, 0x93, 0x8E, 0x7E, 0x92, 0x7C, 0xBB, 0xDD, 0x60, 0xEC, 0xE7, 0xFE, 0x0E, 0x9D, 0x4F, 0x36, 0x46, 0xE6, 0xF1, 0x5C, 0x94, 0x70, 0xEE, 0x67, 0x5F, 0x36, 0x2B, 0x70, 0x44, 0x8D, 0xCA, 0x09, 0xB9, 0x58, 0x67, 0xD2, 0x9F, 0xAD, 0x1F, 0x13, 0x54, 0x74, 0xAD, 0xA6, 0x84, 0x44, 0x28, 0xF3, 0xDE, 0x7E, 0x4C, 0x20, 0x2B, 0xC5, 0xE9, 0x12, 0xE9, 0x5E, 0xFB, 0x8D, 0x77, 0xA9, 0xA4, 0xD2, 0x0D, 0x3C, 0x38, 0x24, 0xBE, 0xF5, 0x8A, 0xB5, 0xF5 },
	.priv_exponent = { 0x32, 0x36, 0x43, 0xC2, 0xB3, 0x1A, 0x7E, 0x13, 0xAB, 0xA2, 0xB6, 0x8B, 0x4F, 0x05, 0xA7, 0xA6, 0xCD, 0xE7, 0xA6, 0x74, 0x47, 0x49, 0xE6, 0x51, 0xE4, 0x71, 0x74, 0x15, 0x76, 0x91, 0xF7, 0x92, 0xB1, 0x4E, 0xF6, 0x99, 0x73, 0x1E, 0xCF, 0xB5, 0x1D, 0x7C, 0xAF, 0xC5, 0xEA, 0x57, 0x01, 0xE5, 0x5C, 0x10, 0x47, 0xEA, 0x3A, 0x54, 0x86, 0x03, 0x2A, 0x76, 0x05, 0x72, 0x53, 0x16, 0xC2, 0xAE, 0x2D, 0xBE, 0x71, 0xF7, 0x17, 0x6B, 0x23, 0xDD, 0x2C, 0xB8, 0x8D, 0x13, 0x14, 0xE5, 0xDA, 0x3B, 0xC7, 0x33, 0x7A, 0xBA, 0xE5, 0x2A, 0x2B, 0x7D, 0x5A, 0x12, 0x27, 0x38, 0x56, 0xDF, 0xED, 0x70, 0x03, 0x0E, 0xED, 0x64, 0xC7, 0xF6, 0x54, 0xAC, 0xFE, 0x1D, 0x77, 0xA4, 0xE4, 0xBC, 0xEB, 0xB9, 0xA6, 0xC5, 0xFE, 0x3A, 0xAF, 0x58, 0x81, 0xE4, 0x3F, 0xA0, 0xE6, 0x93, 0x13, 0x2D, 0x98, 0x7D, 0xB3, 0xE2, 0xC9, 0xC8, 0xD6, 0x31, 0x91, 0x73, 0x9D, 0xCA, 0xC9, 0x44, 0xEF, 0xD0, 0x39, 0xBF, 0x38, 0xFD, 0x1C, 0x91, 0x72, 0x93, 0x40, 0xA9, 0x8A, 0x0D, 0x3E, 0x32, 0xC4, 0x59, 0x4B, 0x0C, 0xC7, 0xEA, 0x50, 0x41, 0x9F, 0xF5, 0xE2, 0xB7, 0x50, 0x7C, 0xE3, 0xC9, 0xEC, 0x46, 0x18, 0xAC, 0xB4, 0x91, 0x2A, 0x32, 0xE0, 0xD8, 0x10, 0x6F, 0xFC, 0x81, 0xB3, 0x95, 0xF3, 0xFC, 0x78, 0xC0, 0xEF, 0xE5, 0x7B, 0x8D, 0x14, 0xD4, 0x36, 0x26, 0x5F, 0xC6, 0x32, 0xC0, 0x19, 0x87, 0x5C, 0x77, 0x26, 0x37, 0xD8, 0xAE, 0x66, 0xD6, 0x0B, 0x28, 0x26, 0x43, 0x7C, 0x25, 0xDB, 0x6D, 0x5C, 0xE8, 0x94, 0x8F, 0xA9, 0x77, 0x07, 0xB2, 0xC0, 0x85, 0xCD, 0x41, 0xBA, 0x48, 0x88, 0x73, 0x34, 0xD5, 0x20, 0x8A, 0x0F, 0xE3, 0x9E, 0x99, 0xF0, 0xC8, 0xE8, 0xD9, 0x2C, 0x2A, 0x21, 0x69, 0xE4, 0xC1 }
};

static const CtrRsa2048Key dev_accessdesc_rsa =
{
	.modulus = { 0xF4, 0x3C, 0x45, 0x82, 0xFB, 0xF8, 0x90, 0x5D, 0x07, 0x02, 0x9F, 0x2A, 0x98, 0x8B, 0x63, 0xB7, 0xD3, 0x8F, 0x3C, 0xE2, 0xE0, 0xE0, 0x93, 0xBF, 0xDF, 0x32, 0x43, 0x4D, 0xBE, 0xF4, 0xD1, 0x7A, 0x3A, 0x4E, 0x54, 0x31, 0xD7, 0x73, 0xAE, 0x99, 0x4C, 0xC4, 0x1F, 0x3C, 0x3E, 0xF0, 0x57, 0x05, 0xA3, 0x8A, 0x45, 0x54, 0x60, 0xD8, 0x8F, 0xD9, 0x1D, 0x68, 0x0D, 0x0E, 0x2E, 0xEF, 0xC8, 0xE8, 0x3D, 0xC9, 0x19, 0xF3, 0x73, 0x1E, 0x2D, 0xDA, 0x77, 0x88, 0x3E, 0xCA, 0x5E, 0x25, 0x70, 0x4B, 0xF7, 0x70, 0x95, 0x83, 0x54, 0x24, 0xE0, 0xC3, 0x1A, 0x75, 0xDF, 0x61, 0x3D, 0xD1, 0x42, 0xEC, 0x35, 0x1B, 0x38, 0xD6, 0xC1, 0xF6, 0x7E, 0x18, 0x2A, 0x84, 0x85, 0xDD, 0x57, 0x74, 0x1F, 0x0A, 0x2E, 0xF6, 0xB2, 0x94, 0xA2, 0x3E, 0xE9, 0xA1, 0xD0, 0x09, 0xF7, 0x3A, 0x99, 0x80, 0x05, 0xAF, 0x57, 0x55, 0xEF, 0x52, 0xFA, 0x24, 0x3E, 0x7F, 0xD4, 0x7C, 0x41, 0x44, 0x7B, 0x06, 0x7F, 0xB9, 0x5B, 0x2E, 0x8E, 0x96, 0xAE, 0x46, 0x12, 0x4D, 0x64, 0x21, 0xE5, 0x0F, 0x85, 0xCC, 0xEB, 0x92, 0xE5, 0xF0, 0xF5, 0xA7, 0x42, 0x27, 0x3B, 0xEC, 0xF8, 0xE7, 0x81, 0x75, 0x6F, 0x63, 0x0A, 0x8B, 0x0D, 0x77, 0x38, 0x51, 0xE6, 0x66, 0x33, 0xBA, 0x79, 0xDC, 0x2F, 0x2C, 0x8F, 0xC3, 0x28, 0x06, 0xBB, 0x03, 0x9C, 0xDB, 0xD1, 0x64, 0x0A, 0x66, 0xF0, 0xF8, 0xC1, 0x2A, 0x49, 0x1D, 0x0C, 0x6E, 0x35, 0xBB, 0xEA, 0xB3, 0x5C, 0x0D, 0xE9, 0x95, 0x7C, 0x67, 0xBE, 0x65, 0x77, 0xEC, 0x07, 0xC0, 0x23, 0x05, 0x0A, 0x72, 0x48, 0x86, 0xE9, 0x9E, 0xFC, 0x25, 0x15, 0xE7, 0xC8, 0x21, 0x65, 0xE0, 0x1B, 0xD5, 0xD5, 0x0E, 0xD3, 0x11, 0x54, 0xBB, 0x29, 0x78, 0xBF, 0x2A, 0x3C, 0x3B, 0xB6, 0xB1 },
	.priv_exponent = {0}
};

static const CtrRsa2048Key dev_crr_rsa =
{
	.modulus = { 0xC5, 0xF7, 0x09, 0x80, 0x5F, 0xDA, 0xDC, 0xBD, 0x46, 0x07, 0x52, 0xAA, 0x6D, 0xCD, 0x72, 0xB2, 0x50, 0x09, 0x77, 0x47, 0x8A, 0x4F, 0x09, 0x2A, 0xE2, 0x91, 0xB4, 0x5F, 0x04, 0x97, 0x51, 0x75, 0xC9, 0x19, 0x6F, 0x95, 0xBB, 0x23, 0x14, 0x7D, 0x34, 0xDF, 0x77, 0x78, 0x07, 0xE8, 0xD1, 0x10, 0x11, 0xAF, 0xCE, 0x02, 0xB8, 0x73, 0xA9, 0xFB, 0x64, 0xB7, 0x65, 0x87, 0xE5, 0x67, 0xDD, 0x67, 0x37, 0x75, 0xFD, 0x0F, 0xE2, 0x97, 0xBC, 0x79, 0xA8, 0xCC, 0xF9, 0xFA, 0x18, 0xB2, 0x62, 0x4D, 0xF7, 0x53, 0x6B, 0x9C, 0x0E, 0x1A, 0xAB, 0x90, 0xE6, 0x52, 0x86, 0xC8, 0x1C, 0x92, 0x2C, 0x61, 0x53, 0xA9, 0x01, 0xDA, 0x43, 0x93, 0xD0, 0x42, 0x2E, 0xDD, 0xD5, 0x4C, 0x8C, 0x4C, 0xE8, 0x91, 0x56, 0xEC, 0xEE, 0x12, 0x70, 0x0B, 0x64, 0xF0, 0x0A, 0xD6, 0xAF, 0xF8, 0x60, 0xC2, 0xA8, 0x26, 0x7A, 0xC8, 0xBA, 0x55, 0x9A, 0xA1, 0x44, 0xFD, 0x09, 0x47, 0x26, 0xA0, 0xC1, 0x99, 0x9E, 0xF1, 0x24, 0xDF, 0xA3, 0xC2, 0xBB, 0xFF, 0x07, 0x45, 0xD9, 0xD6, 0xA4, 0xC0, 0xFF, 0x6C, 0x6C, 0x78, 0x7B, 0x6D, 0x70, 0x8C, 0x74, 0x44, 0xB0, 0x95, 0xE6, 0xC6, 0x66, 0x5E, 0x7E, 0xBE, 0x71, 0xC5, 0x91, 0x34, 0x73, 0xA7, 0xD4, 0x4C, 0x0D, 0xFC, 0xA9, 0x21, 0x49, 0x94, 0x92, 0xA1, 0x6A, 0x4D, 0x30, 0xA3, 0xD6, 0x9F, 0x6C, 0x60, 0x40, 0x0C, 0xEE, 0xEB, 0xF8, 0x99, 0x22, 0xE1, 0x6F, 0xFC, 0x3C, 0x96, 0x23, 0xAA, 0x11, 0x34, 0x00, 0x4E, 0xFC, 0x2D, 0x60, 0x41, 0x45, 0xE3, 0x5D, 0x78, 0x06, 0xB1, 0xF1, 0xC3, 0x07, 0xB9, 0xD3, 0x47, 0xD0, 0xF1, 0x8C, 0x26, 0x33, 0x1F, 0x6B, 0x46, 0xDD, 0xF3, 0xE3, 0x84, 0x64, 0xA7, 0xF1, 0x53, 0x11, 0xE1, 0x53, 0x4E, 0x99, 0xDB, 0xAC, 0x53 },
	.priv_exponent = {0}
};

static const unsigned char dev_crr_sign[0x100] = // signature over dev_crr_presigned_rsa.modulus + some other data in CRR header
{
	0x96, 0x5C, 0xBE, 0x5E, 0xEF, 0x08, 0x0B, 0x29, 0xEF, 0x95, 0x12, 0xA4, 0x80, 0x36, 0x47, 0xD5, 0x8F, 0xEC, 0xD0, 0xCB, 0x00, 0x4C, 0x29, 0xDC, 0x5E, 0x87, 0xCF, 0x87, 0x66, 0x4B, 0x94, 0xDE, 0xF0, 0xF6, 0x95, 0x19, 0x13, 0xF4, 0x29, 0xC7, 0x89, 0x55, 0x91, 0x2E, 0x3B, 0x17, 0x1C, 0x86, 0x61, 0x03, 0x03, 0xDC, 0x6A, 0x3E, 0x33, 0xD4, 0x7A, 0xEA, 0xF9, 0x14, 0x82, 0x50, 0xF9, 0x3F, 0xAD, 0xCF, 0x9F, 0xB8, 0xE0, 0xAD, 0xF6, 0x40, 0x0F, 0xE6, 0x41, 0x7D, 0x18, 0xB4, 0xC2, 0x1A, 0x1F, 0xA6, 0x2F, 0x51, 0x40, 0x5F, 0x0A, 0x4B, 0x57, 0x4B, 0x73, 0xC2, 0x6A, 0xB9, 0x73, 0x18, 0x5A, 0x9E, 0xC3, 0x90, 0x7D, 0xCC, 0x5B, 0xEC, 0x46, 0x6D, 0x93, 0x09, 0xB6, 0xF0, 0x84, 0x64, 0x46, 0x12, 0x77, 0x7C, 0x87, 0x25, 0xEB, 0x4C, 0xAE, 0x83, 0xB8, 0x25, 0x6E, 0xF7, 0x7D, 0x45, 0xDF, 0xF6, 0x4A, 0x32, 0x9B, 0x8E, 0x32, 0xC6, 0xCF, 0x63, 0x37, 0x92, 0x7D, 0x01, 0xDD, 0xE9, 0x71, 0x37, 0x0C, 0x2E, 0xB7, 0x83, 0xB7, 0x7C, 0x43, 0x37, 0x20, 0x34, 0xF1, 0xAF, 0x78, 0x4A, 0xB0, 0x84, 0xE0, 0x4C, 0x67, 0x54, 0xA8, 0x75, 0x12, 0xE5, 0x27, 0x38, 0x45, 0xFF, 0x49, 0x9D, 0xF3, 0xFC, 0x3F, 0xCE, 0x73, 0x44, 0xE3, 0x28, 0xD0, 0xD6, 0x00, 0x1F, 0x46, 0xF9, 0x64, 0x3B, 0xDC, 0xEE, 0x30, 0xA8, 0x63, 0x05, 0xB0, 0xF1, 0xA6, 0x4B, 0x21, 0x34, 0x2A, 0xEE, 0xBA, 0x1C, 0x89, 0x0B, 0x80, 0xB8, 0x00, 0xC7, 0x40, 0xCB, 0x66, 0x69, 0x44, 0x27, 0x01, 0xAC, 0x08, 0xC3, 0x97, 0xC5, 0x37, 0xE4, 0x8B, 0xAA, 0x41, 0xB1, 0xEE, 0x48, 0xE0, 0xA7, 0xD6, 0x6F, 0x8A, 0xF5, 0x40, 0x90, 0xD4, 0x2D, 0x81, 0xD4, 0xED, 0x9D, 0xCA, 0x03, 0xFE, 0x35, 0xB3, 0x66, 0xAF, 0x82
};

static const CtrRsa2048Key dev_crr_presigned_rsa = // pre signed rsakey
{
	.modulus = { 0xE2, 0xAD, 0xA6, 0xEA, 0xCA, 0xA3, 0xE8, 0xCC, 0xA9, 0x70, 0x1D, 0x2E, 0x23, 0x4B, 0xC6, 0x55, 0xCE, 0x13, 0xD9, 0xA7, 0x58, 0xB4, 0xC7, 0x73, 0x96, 0x1D, 0xE8, 0xC3, 0x09, 0x4D, 0x9B, 0xC3, 0xEB, 0x69, 0xA2, 0x37, 0x83, 0x5D, 0xD8, 0x37, 0x04, 0x72, 0x7A, 0x4F, 0xEA, 0x53, 0x98, 0x9D, 0x0E, 0x01, 0x34, 0x70, 0x9A, 0x82, 0x06, 0xE7, 0x6A, 0xC9, 0xF8, 0x0E, 0x49, 0x5A, 0xA4, 0xE7, 0x0E, 0xFA, 0xD4, 0xAB, 0x3B, 0xC5, 0xD7, 0xF1, 0xA4, 0xFC, 0x92, 0x7F, 0xD0, 0xF3, 0xCD, 0xD5, 0xB9, 0x2A, 0x1A, 0x41, 0x62, 0xB3, 0x7B, 0x3E, 0x1E, 0x35, 0x46, 0x41, 0x8E, 0xB2, 0x53, 0x1A, 0x60, 0xF8, 0xC2, 0xD1, 0x94, 0xB3, 0x9D, 0x76, 0x9F, 0x1D, 0x98, 0xAC, 0xF0, 0xCF, 0xE3, 0xA9, 0x05, 0x85, 0xF2, 0xBF, 0x55, 0x76, 0x1B, 0x89, 0x1C, 0xC3, 0x19, 0x2E, 0xEE, 0x94, 0xBE, 0x75, 0x0F, 0xA3, 0x76, 0x8B, 0x24, 0x24, 0x97, 0xFA, 0xC0, 0x53, 0x24, 0xF5, 0x85, 0x02, 0x19, 0x9D, 0xC5, 0x11, 0x2E, 0x6B, 0xA3, 0x26, 0xFE, 0xF7, 0x55, 0xD4, 0x23, 0x0A, 0x73, 0x3F, 0x37, 0x53, 0xEA, 0xC2, 0xB7, 0xC1, 0xC9, 0xD8, 0xF3, 0x2F, 0x78, 0x76, 0x4A, 0xA0, 0x69, 0x60, 0x91, 0xC2, 0x7D, 0x11, 0x74, 0xEF, 0x96, 0xD9, 0x74, 0x53, 0xB1, 0x1C, 0xB0, 0xC4, 0x32, 0x16, 0x82, 0x3B, 0xAF, 0x61, 0xB2, 0xDE, 0x38, 0x87, 0x3E, 0x37, 0x4B, 0xA3, 0x95, 0x88, 0x8E, 0xE0, 0x27, 0x9A, 0x1F, 0x7D, 0xB8, 0x23, 0xC3, 0x63, 0xE8, 0x68, 0x51, 0xD9, 0x8C, 0x4C, 0xC2, 0x59, 0x86, 0x49, 0xF7, 0x46, 0x9E, 0x3C, 0xD7, 0x9F, 0x89, 0x23, 0xB4, 0x73, 0x35, 0x2F, 0x18, 0x23, 0x76, 0xA3, 0x9F, 0x40, 0x0B, 0x76, 0x90, 0x85, 0xC8, 0x89, 0xDA, 0x65, 0xE7, 0x6E, 0xEF, 0x2E, 0xF5, 0x67 },
	.priv_exponent = { 0x8D, 0x27, 0x29, 0x6B, 0xC7, 0xA7, 0xED, 0xCD, 0x94, 0x2D, 0x36, 0x5E, 0x86, 0xA8, 0x26, 0xE7, 0x43, 0x9E, 0x64, 0xC8, 0xAA, 0x9A, 0x58, 0x21, 0x07, 0xF7, 0xB3, 0xFB, 0xCF, 0x8D, 0x3E, 0x53, 0xF0, 0x02, 0x25, 0x7B, 0x80, 0x18, 0x2E, 0x0D, 0x84, 0x7D, 0x6C, 0xE0, 0xDA, 0xC0, 0x17, 0xA6, 0xA5, 0x13, 0xE6, 0xFD, 0xBF, 0x98, 0xFC, 0x87, 0x9A, 0x9E, 0x0E, 0x13, 0x87, 0x66, 0x24, 0x8D, 0xA5, 0x6C, 0x58, 0x86, 0x10, 0x80, 0x90, 0x89, 0xEE, 0xFD, 0x40, 0x94, 0xCB, 0x1F, 0x26, 0xAB, 0xD1, 0xD3, 0xFF, 0xE9, 0x7B, 0x76, 0xDC, 0x65, 0xC0, 0x15, 0xD8, 0x9B, 0xF6, 0x29, 0xE1, 0x49, 0xE9, 0xDC, 0xBE, 0x24, 0x17, 0xFF, 0x09, 0x2C, 0xD6, 0xC4, 0x6D, 0x50, 0x33, 0xDC, 0xA0, 0x9D, 0x9D, 0xCC, 0xDD, 0x6E, 0x7B, 0xDF, 0x42, 0x22, 0x4D, 0x80, 0xC7, 0xEB, 0xCB, 0xB1, 0x60, 0x2F, 0x04, 0xEE, 0x04, 0x0E, 0x4C, 0x76, 0x49, 0x55, 0x92, 0xA5, 0xC1, 0x13, 0x60, 0x0A, 0x80, 0x15, 0x3D, 0x1C, 0xC6, 0x46, 0x57, 0x2E, 0x7C, 0xB0, 0x3D, 0x87, 0x06, 0x87, 0xFD, 0x31, 0xF8, 0xE7, 0x14, 0x97, 0x2A, 0x57, 0x40, 0xAC, 0x94, 0x61, 0xCD, 0xCF, 0xDE, 0x8C, 0x40, 0x46, 0x95, 0xA0, 0xD6, 0xF9, 0x2C, 0x08, 0x9B, 0x12, 0xBF, 0xF1, 0x88, 0x9C, 0x5D, 0x40, 0x32, 0x6D, 0x9D, 0x99, 0xA4, 0x80, 0xA6, 0xC2, 0x45, 0x5A, 0xD3, 0x22, 0xFE, 0xFA, 0x17, 0x54, 0x11, 0xEA, 0x41, 0xB4, 0xBD, 0x68, 0x1E, 0xDD, 0x3F, 0xE5, 0x92, 0xCB, 0x9E, 0xF8, 0xC0, 0x0A, 0x8B, 0xF5, 0x89, 0xA4, 0x03, 0x68, 0xF8, 0xF8, 0x99, 0x7C, 0xFE, 0xAD, 0x32, 0xDD, 0x5C, 0xB4, 0x06, 0x29, 0xDA, 0x96, 0x8B, 0xBA, 0xCB, 0x15, 0xDE, 0x38, 0x0D, 0xCA, 0xF7, 0x01, 0x65, 0xF6, 0x2D, 0x36, 0x6E, 0x71 }
};

static const CtrRsa2048Key dev_firm_rsa =
{
	.modulus = {0xC1, 0x1E, 0x84, 0xE4, 0xDA, 0xD7, 0xED, 0xC8, 0xA5, 0xD9, 0xCB, 0x0B, 0xE9, 0x3B, 0x9D, 0xBC, 0x15, 0x69, 0xF7, 0x95, 0xF6, 0x8F, 0xB7, 0x91, 0x24, 0x19, 0xBE, 0x8F, 0xFE, 0xBB, 0xC1, 0x1D, 0x09, 0xF0, 0xE3, 0x78, 0xA2, 0x0C, 0xC0, 0x0B, 0x8E, 0xCD, 0xBA, 0x0E, 0x69, 0x4C, 0x61, 0x4A, 0xBD, 0x13, 0xEA, 0xE2, 0x23, 0xE4, 0x0B, 0x62, 0x1F, 0x9B, 0x63, 0x1B, 0x31, 0x34, 0xB7, 0x12, 0x73, 0x64, 0x6B, 0x4E, 0x60, 0x41, 0x0A, 0x3D, 0x54, 0x86, 0xFA, 0x49, 0xEC, 0x2D, 0x77, 0xAD, 0x1D, 0xBC, 0x48, 0xE7, 0xFB, 0x07, 0xEF, 0x48, 0xC3, 0xBE, 0xC3, 0xD6, 0xE1, 0x5B, 0x3D, 0xCD, 0x5E, 0x6B, 0x46, 0x08, 0x6A, 0x3A, 0x0E, 0xAE, 0x25, 0x49, 0x44, 0xA5, 0x40, 0x0D, 0x94, 0x53, 0x18, 0xA4, 0x8F, 0x57, 0x8E, 0xF4, 0xCD, 0xB4, 0xD3, 0x4E, 0xE7, 0x15, 0x9B, 0x11, 0x95, 0x85, 0x00, 0xC4, 0x92, 0x94, 0xB8, 0xBE, 0xFE, 0xCB, 0xB7, 0x50, 0xA0, 0xBE, 0x8A, 0xF5, 0xFD, 0xC8, 0x0E, 0x4B, 0xA9, 0x41, 0x13, 0x62, 0x48, 0xCD, 0x1A, 0xF3, 0xC8, 0x6B, 0xA5, 0xA0, 0xDF, 0xF1, 0x9D, 0x3D, 0xFD, 0xE4, 0xD1, 0x7C, 0x1F, 0x00, 0x0D, 0x99, 0x72, 0x6B, 0xA3, 0x05, 0x7F, 0x86, 0x38, 0xBE, 0x4D, 0x5E, 0xAB, 0x93, 0xDF, 0xF3, 0xEE, 0xA1, 0x9F, 0x22, 0x50, 0xA8, 0x7F, 0x31, 0xAA, 0x2B, 0x03, 0x71, 0x9B, 0x14, 0xC4, 0x30, 0x88, 0x42, 0x6F, 0xD5, 0x2C, 0x7B, 0x03, 0x64, 0x3B, 0x14, 0xEC, 0x46, 0x33, 0xCC, 0x2C, 0x95, 0x9F, 0x5C, 0x7B, 0x83, 0xC5, 0x67, 0xDD, 0x7C, 0xA1, 0x2D, 0xD6, 0xEC, 0x17, 0x0B, 0x23, 0xC7, 0xB1, 0x9A, 0x72, 0xBA, 0x78, 0xCB, 0x39, 0x68, 0x5C, 0xB6, 0xB4, 0x61, 0xE1, 0x98, 0xCF, 0x1D, 0x69, 0xF9, 0xD7, 0xB0, 0xA0, 0x5E, 0x9C, 0xEB },
	.priv_exponent = {0}
};

//Certificates
static const unsigned char ca4_dpki_cert[0x400] = 
{
	0x00, 0x01, 0x00, 0x03, 0x19, 0x49, 0x42, 0x9D,  0x1E, 0x58, 0xA6, 0x2E, 0x7E, 0x8B, 0x56, 0xD1,  0xB7, 0x6A, 0xE3, 0x02, 0xFD, 0x8B, 0x97, 0x49,  0x1F, 0x77, 0x87, 0x45, 0xF7, 0x53, 0x88, 0xC4,  0xDD, 0x0B, 0xEB, 0x1D, 0xF1, 0x22, 0xFB, 0x96,  0x42, 0x15, 0x14, 0x97, 0x76, 0x4A, 0x53, 0xCF,  0x78, 0x15, 0x18, 0x45, 0xE4, 0x2C, 0xA8, 0xFD,  0xE4, 0x86, 0xFD, 0x2A, 0x4F, 0x53, 0xF8, 0xA1,  0xBA, 0x00, 0x8A, 0x74, 0x85, 0xFF, 0x73, 0xB3,  0xBF, 0x7E, 0x3C, 0x98, 0x07, 0x29, 0xD0, 0x65,  0x6B, 0x69, 0x32, 0x19, 0xAD, 0xE8, 0x35, 0xEB,  0x5F, 0xFF, 0xFC, 0xCB, 0x7C, 0xBB, 0x5E, 0x30,  0x7F, 0xE0, 0x68, 0x8B, 0x88, 0x8E, 0xF2, 0xD2,  0x05, 0x3F, 0xB7, 0xE7, 0x91, 0xE9, 0x85, 0xFD,  0x15, 0xEF, 0x10, 0xD7, 0x9C, 0xCA, 0x88, 0xD6,  0xBB, 0x15, 0xE8, 0xE4, 0x71, 0x4A, 0x98, 0xEE,  0x09, 0xBF, 0x7B, 0x8A, 0xF0, 0x53, 0x23, 0x2B,  0x64, 0x50, 0xE6, 0xD5, 0xFD, 0xFF, 0xC2, 0x0A,  0x6D, 0x1E, 0xA6, 0xA2, 0x38, 0x12, 0xE1, 0x01,  0x45, 0x25, 0xD5, 0x6D, 0x40, 0x82, 0x70, 0x3B,  0x86, 0x98, 0x69, 0x59, 0xA7, 0x3C, 0xD1, 0xA1,  0x43, 0x64, 0xD2, 0xC2, 0xDA, 0xEA, 0x96, 0xB0,  0x95, 0xF7, 0x6C, 0x46, 0xE4, 0xFF, 0x41, 0x55,  0x46, 0x5E, 0x70, 0xEF, 0x1E, 0xD3, 0x10, 0x53,  0xD9, 0x70, 0x11, 0xE0, 0x10, 0xCC, 0x93, 0xE7,  0x91, 0x40, 0x13, 0x68, 0x7F, 0xA3, 0xA8, 0x02,  0x99, 0x6D, 0x1E, 0x55, 0x7B, 0x1C, 0xCC, 0x7A,  0x7E, 0x8F, 0x58, 0x65, 0xC1, 0x74, 0x2E, 0x28,  0xE2, 0x6D, 0xEF, 0x38, 0xA9, 0x3A, 0xB5, 0xD8,  0x2D, 0x43, 0xEC, 0xCC, 0xBF, 0x0B, 0xEF, 0x22,  0xE1, 0xFD, 0x57, 0xE2, 0x86, 0x43, 0x33, 0x58,  0x2F, 0xED, 0xEA, 0xBC, 0x01, 0x2F, 0x98, 0x6D,  0xDF, 0xC3, 0xE9, 0x44, 0x79, 0x73, 0x47, 0x03,  0x08, 0x45, 0x5B, 0xDC, 0x57, 0xAA, 0x17, 0x0B,  0x84, 0x42, 0x7F, 0x73, 0xA2, 0x9B, 0x48, 0xF6,  0xDA, 0x13, 0x5F, 0x66, 0xC7, 0x45, 0xC1, 0x42,  0xA8, 0x4A, 0xFB, 0x0E, 0x6A, 0x5E, 0xED, 0x85,  0xD7, 0xB9, 0x71, 0x99, 0x36, 0xF8, 0xCE, 0x2B,  0x62, 0x1F, 0x39, 0x5F, 0x40, 0xDC, 0x03, 0xBE,  0xF8, 0x85, 0x4C, 0x11, 0x17, 0xFF, 0x0C, 0x12,  0x86, 0x41, 0xCC, 0x78, 0x43, 0xB9, 0x7B, 0x43,  0x46, 0xDB, 0x22, 0x6F, 0x60, 0x26, 0xAC, 0xB5,  0x6C, 0x27, 0x8B, 0x8E, 0x0E, 0xA7, 0x9A, 0x2D,  0x65, 0xEF, 0x79, 0x8E, 0x10, 0x78, 0xAD, 0x80,  0xED, 0x4B, 0x96, 0x04, 0xD2, 0xF0, 0x8B, 0x2C,  0xD6, 0x4A, 0x23, 0xA3, 0xDB, 0x27, 0x08, 0x33,  0xB4, 0x02, 0xF8, 0x08, 0x51, 0xF3, 0x5B, 0xED,  0x3E, 0xE4, 0x57, 0x7C, 0x66, 0x60, 0xFB, 0xF1,  0x6D, 0x94, 0x13, 0xE0, 0x9C, 0x91, 0x7A, 0x49,  0xD4, 0x2C, 0x6D, 0xA3, 0x75, 0xBC, 0x27, 0xF0,  0x23, 0x0D, 0xB9, 0x8F, 0x89, 0x73, 0xAB, 0x02,  0x7B, 0x52, 0x2C, 0xD5, 0x7E, 0xC0, 0x3D, 0x25,  0xE8, 0xB3, 0xFC, 0x34, 0x94, 0xC9, 0x7F, 0xB1,  0x08, 0xFE, 0x18, 0xC6, 0x8A, 0x43, 0x36, 0xE4,  0x6C, 0x26, 0xB6, 0xF2, 0x80, 0xD2, 0x7E, 0x34,  0xBE, 0x28, 0x7C, 0x3E, 0x46, 0x87, 0xBC, 0x9D,  0x77, 0x6B, 0x76, 0xD9, 0x28, 0xD1, 0xB6, 0x35,  0x2E, 0xC0, 0x34, 0x7D, 0x72, 0x94, 0xAA, 0x93,  0x60, 0x26, 0x8D, 0x26, 0xF5, 0xF6, 0x52, 0x06,  0x4A, 0xF2, 0x40, 0xD7, 0xD0, 0x0C, 0x7C, 0x5E,  0xA3, 0xC3, 0x2D, 0xE6, 0x2D, 0x9B, 0x5C, 0x4B,  0x4C, 0xAB, 0x6F, 0xD7, 0xBD, 0x37, 0x1D, 0x57,  0xC2, 0x16, 0x60, 0x95, 0x91, 0x0E, 0x4A, 0xD8,  0xE9, 0xED, 0x18, 0x1E, 0xF7, 0x61, 0x93, 0x61,  0x53, 0x89, 0x2D, 0x77, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x52, 0x6F, 0x6F, 0x74, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x01, 0x43, 0x41, 0x30, 0x30,  0x30, 0x30, 0x30, 0x30, 0x30, 0x34, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x81, 0x12, 0x2A, 0x46,  0xC9, 0xCC, 0x2D, 0xC4, 0xDF, 0x29, 0x30, 0xE4,  0xDF, 0x3F, 0x8C, 0x70, 0xA0, 0x78, 0x94, 0x87,  0x75, 0xAD, 0x5E, 0x9A, 0xA6, 0x04, 0xC5, 0xB4,  0xD8, 0xEA, 0xFF, 0x2A, 0xA1, 0xD2, 0x14, 0x67,  0x65, 0x64, 0xEF, 0xCA, 0x28, 0xCC, 0x00, 0x15,  0x45, 0x54, 0xA1, 0xA3, 0xEA, 0x13, 0x79, 0xE9,  0xE6, 0xCA, 0xAC, 0xED, 0x15, 0x93, 0xFE, 0x88,  0xD8, 0x9A, 0xC6, 0xB8, 0xAC, 0xCC, 0xAB, 0x6E,  0x20, 0x7C, 0xEB, 0x7C, 0xCA, 0x29, 0x80, 0x9E,  0x29, 0x80, 0x44, 0x06, 0x62, 0xB7, 0xD4, 0x38,  0x2A, 0x15, 0xDA, 0x43, 0x08, 0x57, 0x45, 0xA9,  0xAA, 0xE5, 0x9A, 0xA0, 0x5B, 0xDB, 0x32, 0xF6,  0x68, 0x69, 0xA2, 0xDD, 0x42, 0x95, 0x38, 0x6C,  0x87, 0xEC, 0xDD, 0x35, 0x08, 0xA2, 0xCF, 0x60,  0xD0, 0x1E, 0x23, 0xEC, 0x2F, 0xE6, 0x98, 0xF4,  0x70, 0xD6, 0x00, 0x15, 0x49, 0xA2, 0xF0, 0x67,  0x59, 0x13, 0x1E, 0x53, 0x4C, 0x70, 0x06, 0x05,  0x7D, 0xEF, 0x1D, 0x18, 0xA8, 0x3F, 0x0A, 0xC7, 0x9C, 0xFE, 0x80, 0xFF, 0x5A, 0x91, 0xF2, 0xBE,  0xD4, 0xA0, 0x83, 0x70, 0x61, 0x19, 0x0A, 0x03,  0x29, 0x90, 0x21, 0x65, 0x40, 0x3C, 0x9A, 0x90,  0x8F, 0xB6, 0x15, 0x73, 0x9F, 0x3C, 0xE3, 0x3B,  0xF1, 0xBA, 0xEA, 0x16, 0xC2, 0x5B, 0xCE, 0xD7,  0x96, 0x3F, 0xAC, 0xC9, 0xD2, 0x4D, 0x9C, 0x0A,  0xD7, 0x6F, 0xC0, 0x20, 0xB2, 0xC4, 0xB8, 0x4C,  0x10, 0xA7, 0x41, 0xA2, 0xCC, 0x7D, 0x9B, 0xAC,  0x3A, 0xAC, 0xCC, 0xA3, 0x52, 0x9B, 0xAC, 0x31,  0x6A, 0x9A, 0xA7, 0x5D, 0x2A, 0x26, 0xC7, 0xD7,  0xD2, 0x88, 0xCB, 0xA4, 0x66, 0xC5, 0xFE, 0x5F,  0x45, 0x4A, 0xE6, 0x79, 0x74, 0x4A, 0x90, 0xA1,  0x57, 0x72, 0xDB, 0x3B, 0x0E, 0x47, 0xA4, 0x9A, 0xF0, 0x31, 0xD1, 0x6D, 0xBE, 0xAB, 0x33, 0x2B, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char xs9_dpki_cert[0x300] = 
{
	0x00, 0x01, 0x00, 0x04, 0x63, 0x80, 0x5A, 0x35, 0x1A, 0x43, 0x7B, 0xA2, 0x43, 0x19, 0xBB, 0x3A, 0x77, 0x7B, 0x7A, 0xF3, 0x5E, 0x72, 0x4B, 0x15, 0x0A, 0x06, 0x39, 0x6C, 0x5F, 0xEC, 0x38, 0x45, 0xB1, 0x88, 0x76, 0x26, 0x8D, 0x5E, 0xDA, 0xE6, 0x2F, 0x14, 0xBA, 0x02, 0xFA, 0xD6, 0xFC, 0x3B, 0x2B, 0xBE, 0x87, 0x07, 0x63, 0x8E, 0x55, 0xBF, 0x05, 0x5A, 0xFC, 0xFC, 0xB3, 0x47, 0x69, 0x11, 0x89, 0xDB, 0x1C, 0xAF, 0x4B, 0x43, 0x76, 0x62, 0x3E, 0x30, 0x89, 0x0A, 0x9D, 0x3B, 0xBB, 0x3E, 0x50, 0xBD, 0xF7, 0xA6, 0xC0, 0xF7, 0xF8, 0xBB, 0x0D, 0xB5, 0x6A, 0xBB, 0xC6, 0xC3, 0x50, 0xC8, 0x88, 0xBB, 0x9D, 0xF0, 0x9B, 0xD1, 0x30, 0x64, 0x60, 0x69, 0xDD, 0x34, 0x67, 0xA7, 0x00, 0xEB, 0xDC, 0xF9, 0x8C, 0xB0, 0xF7, 0x93, 0x0E, 0x81, 0xFE, 0x98, 0xD9, 0x72, 0x45, 0x8B, 0x94, 0x7E, 0x59, 0xE2, 0xBE, 0x4E, 0x91, 0x2D, 0x75, 0xCA, 0x1B, 0x8E, 0x2E, 0xF4, 0x6D, 0x73, 0xB1, 0x6B, 0x35, 0xB5, 0x67, 0x0D, 0x63, 0x2D, 0x51, 0x38, 0x53, 0x28, 0x19, 0x1D, 0x9D, 0xAE, 0x8D, 0xC6, 0x61, 0xCC, 0xEF, 0xA4, 0xAB, 0xE2, 0xF3, 0xB0, 0x4C, 0x7B, 0xE2, 0x71, 0xB5, 0xF9, 0x2C, 0xFA, 0x55, 0xCD, 0x88, 0x8B, 0x72, 0xCC, 0xBE, 0x67, 0xFA, 0xDF, 0xEF, 0x6B, 0x53, 0x3C, 0x45, 0xD8, 0xCB, 0xDF, 0xB2, 0x76, 0x41, 0x46, 0xD6, 0xC2, 0x6F, 0x27, 0x16, 0xC5, 0x07, 0xF3, 0xF4, 0x44, 0x66, 0xA3, 0x15, 0xD2, 0x77, 0xF2, 0x89, 0xDA, 0xFD, 0xD5, 0x50, 0xCF, 0xA4, 0x9B, 0xEA, 0xCA, 0xC9, 0x7B, 0xE5, 0x46, 0x0E, 0xED, 0x9B, 0xFB, 0x04, 0xA9, 0xDA, 0x19, 0x58, 0xD9, 0x2A, 0x20, 0x8A, 0xAC, 0xC1, 0xF4, 0x8E, 0xE9, 0x14, 0xD8, 0x8A, 0xD7, 0x41, 0xD5, 0x5B, 0x9B, 0x64, 0x22, 0xD8, 0xAF, 0xAE, 0xC7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x6F, 0x6F, 0x74, 0x2D, 0x43, 0x41, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x58, 0x53, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xA3, 0x47, 0xA4, 0xC0, 0x84, 0x4C, 0xEB, 0x7E, 0xB0, 0xCF, 0xF0, 0xAE, 0xB7, 0x77, 0x69, 0x85, 0x93, 0xE4, 0x99, 0x5A, 0x95, 0x4E, 0x58, 0x17, 0x38, 0xCE, 0xD6, 0x81, 0xB0, 0xBD, 0x77, 0x09, 0xE7, 0xF8, 0x9A, 0xDF, 0xAD, 0x05, 0x48, 0x83, 0xF6, 0xC3, 0xFD, 0xDF, 0x7B, 0x83, 0xE0, 0x0C, 0x26, 0x81, 0x54, 0x43, 0x29, 0xEA, 0x82, 0x6C, 0x89, 0xF0, 0xA6, 0x74, 0x42, 0x86, 0x4D, 0x32, 0x60, 0x32, 0x7D, 0xA7, 0x7A, 0x13, 0x40, 0x66, 0x59, 0xDA, 0x3E, 0x41, 0x6B, 0x27, 0x94, 0x03, 0x4F, 0xAA, 0x22, 0x9D, 0xD5, 0x54, 0x52, 0xDB, 0x27, 0x0A, 0x6A, 0xA2, 0x3D, 0x19, 0xB1, 0x66, 0x1B, 0x19, 0x7D, 0xAB, 0xC7, 0x0E, 0x88, 0x17, 0x91, 0xA1, 0x2A, 0xB4, 0x3C, 0x6C, 0xCB, 0xF5, 0xAA, 0x7C, 0x3A, 0xDD, 0x36, 0xFB, 0x35, 0x71, 0x7B, 0x20, 0x01, 0x59, 0x00, 0xD6, 0xF6, 0x90, 0x39, 0x35, 0x41, 0x31, 0xF8, 0xC1, 0xC0, 0x57, 0x3A, 0x35, 0x18, 0x58, 0x90, 0xB1, 0xAD, 0x9A, 0x0E, 0xEC, 0xE0, 0xF4, 0x7A, 0x7D, 0xA5, 0x27, 0x48, 0xC9, 0x72, 0xAB, 0x0D, 0x08, 0x7B, 0x62, 0x35, 0x40, 0x91, 0x14, 0x2B, 0xB1, 0x1D, 0x1A, 0xFA, 0xF9, 0xCD, 0x5C, 0x17, 0x13, 0x53, 0x52, 0x71, 0xCA, 0xE2, 0x2A, 0x78, 0xB1, 0x7F, 0x4A, 0xCD, 0x59, 0xD8, 0xBA, 0x1D, 0x7D, 0x70, 0x5F, 0x78, 0x1B, 0x9F, 0x9D, 0x37, 0x18, 0x8E, 0xD7, 0xCD, 0x0D, 0x49, 0x57, 0x74, 0x69, 0x88, 0x3A, 0x6B, 0x8E, 0x4E, 0x1B, 0x85, 0xDD, 0xBE, 0x39, 0x45, 0x05, 0x89, 0x56, 0x12, 0x97, 0x59, 0x9A, 0x09, 0xA4, 0xC8, 0x2D, 0x2F, 0xF5, 0xCF, 0xB4, 0x73, 0x70, 0xDB, 0x58, 0x1E, 0xB2, 0x4E, 0x77, 0x6F, 0xA4, 0x7E, 0x62, 0xDF, 0xB7, 0x05, 0xE8, 0x80, 0x42, 0x5C, 0xB8, 0x78, 0x87, 0x97, 0x7F, 0x66, 0x2C, 0x5F, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char cpA_dpki_cert[0x300] = 
{
	0x00, 0x01, 0x00, 0x04, 0x50, 0x05, 0xD7, 0x5E, 0x6D, 0xDE, 0xB8, 0x78, 0x3C, 0x81, 0xE9, 0xEF, 0x0D, 0x17, 0xCD, 0x58, 0xF5, 0x94, 0x26, 0xA3, 0xFD, 0x6F, 0x69, 0x90, 0xE8, 0xF8, 0x32, 0x87, 0x12, 0x2E, 0xC2, 0x5C, 0xA1, 0x4B, 0x99, 0x24, 0x23, 0x37, 0xBA, 0x91, 0xA7, 0x5B, 0x0F, 0x7C, 0x59, 0xFB, 0xF7, 0xD1, 0x89, 0x27, 0x22, 0xC4, 0xE6, 0xAF, 0xC7, 0xDE, 0xC7, 0x4A, 0x6E, 0x00, 0x7F, 0x43, 0x4A, 0x88, 0x8A, 0x82, 0x15, 0xE8, 0xDF, 0x2B, 0x52, 0xED, 0x42, 0x00, 0xBC, 0x69, 0xB4, 0xDA, 0x7F, 0xEB, 0x74, 0x6C, 0x7A, 0x2D, 0x96, 0x56, 0x5B, 0x45, 0x59, 0x7B, 0x8F, 0xAE, 0xB1, 0x6B, 0xDC, 0x76, 0xC1, 0xC8, 0x0C, 0x47, 0xF5, 0x0D, 0xA9, 0xC3, 0xE1, 0xFE, 0x28, 0x50, 0x1C, 0x26, 0xA2, 0xD1, 0x54, 0x4B, 0xD1, 0x60, 0x4A, 0x9E, 0x8F, 0x32, 0x2A, 0xEF, 0x31, 0x5F, 0xEA, 0x48, 0x22, 0x67, 0x22, 0xB7, 0xCB, 0x37, 0x2F, 0xF3, 0x5F, 0x5E, 0x61, 0x6A, 0x53, 0x44, 0xA5, 0x85, 0xE5, 0xA0, 0x8A, 0x2E, 0x17, 0x77, 0x57, 0x2B, 0x7A, 0x9A, 0xF7, 0xD2, 0xD8, 0xC4, 0x9C, 0xD0, 0xA0, 0x54, 0xBF, 0x8A, 0x9D, 0xB4, 0x9F, 0xC6, 0x60, 0x61, 0x7C, 0xB8, 0x35, 0x4E, 0x25, 0x7F, 0x68, 0x68, 0x2F, 0x94, 0xB3, 0xCC, 0x53, 0x8C, 0x42, 0x6F, 0x88, 0xC5, 0x48, 0x5C, 0xBE, 0xC1, 0xD0, 0x48, 0x04, 0x74, 0x96, 0x5A, 0x7E, 0x82, 0x59, 0xAA, 0x9F, 0xB6, 0x61, 0x46, 0xCE, 0x59, 0x21, 0xC6, 0xF0, 0xC1, 0x75, 0x1F, 0x21, 0x91, 0x7F, 0x24, 0x96, 0xCB, 0x0C, 0x70, 0x15, 0x7A, 0xB7, 0xBB, 0x3A, 0x9F, 0x57, 0x56, 0x56, 0x5C, 0x38, 0x92, 0x2E, 0xFD, 0xC8, 0xF1, 0x70, 0xB9, 0xAE, 0xA1, 0xAE, 0x36, 0xF5, 0x5E, 0x35, 0x26, 0x63, 0x0A, 0xBA, 0xB2, 0x05, 0x0F, 0xF0, 0x0C, 0xDC, 0xBB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x6F, 0x6F, 0x74, 0x2D, 0x43, 0x41, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x43, 0x50, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xA3, 0x4D, 0x5B, 0xAA, 0x7F, 0x93, 0x80, 0x28, 0x9B, 0xE8, 0x98, 0x63, 0x10, 0x7A, 0xE1, 0x0C, 0x59, 0x2C, 0x2F, 0x7C, 0xFF, 0xBD, 0xAA, 0xDD, 0x74, 0xF4, 0xA2, 0xFB, 0xAC, 0xD7, 0x6F, 0x00, 0x93, 0x42, 0x06, 0x34, 0x71, 0x56, 0xD8, 0x40, 0x49, 0x72, 0x9F, 0x3E, 0x24, 0xFA, 0x5E, 0x19, 0xD1, 0x5B, 0x63, 0x5C, 0xD2, 0xEF, 0x09, 0xDE, 0x32, 0xEE, 0x6B, 0x6F, 0xC8, 0xFA, 0x32, 0x8E, 0x2E, 0x96, 0xB9, 0x94, 0x41, 0x04, 0x7D, 0x07, 0x62, 0x95, 0xDA, 0x0D, 0x91, 0xD8, 0x09, 0x35, 0xD0, 0xDE, 0x8E, 0x6B, 0xC6, 0xAB, 0x14, 0x27, 0x01, 0x9C, 0xFE, 0x49, 0x96, 0xFC, 0x9B, 0x54, 0x79, 0x4D, 0xEB, 0xD7, 0xC6, 0x66, 0x73, 0xA6, 0xDD, 0x3A, 0x77, 0x65, 0x47, 0x94, 0xEC, 0x1C, 0x87, 0xAA, 0x46, 0xD9, 0x78, 0xA9, 0x7D, 0xDB, 0x11, 0x22, 0x6E, 0xD4, 0x12, 0xC2, 0x78, 0x4B, 0x21, 0x83, 0x92, 0xC7, 0x10, 0xC7, 0x74, 0x19, 0xFF, 0xAA, 0xF6, 0x0B, 0x75, 0xD8, 0x23, 0xDD, 0x33, 0xC3, 0xA1, 0x5B, 0xA7, 0x2D, 0x30, 0xA5, 0xA4, 0xD8, 0xF8, 0x0F, 0xD6, 0x73, 0xFD, 0x26, 0xCB, 0x29, 0xA6, 0xEF, 0x50, 0x39, 0xE2, 0x5F, 0x59, 0x61, 0x84, 0x6B, 0xDA, 0x2E, 0xC7, 0xCB, 0xE4, 0x38, 0x4B, 0x28, 0xFB, 0x0D, 0xD5, 0x8E, 0x7C, 0xAA, 0x7D, 0x4B, 0x37, 0x3A, 0xD7, 0x81, 0xDD, 0x73, 0xE3, 0x09, 0x93, 0xBD, 0xBD, 0x7E, 0x08, 0x55, 0x4A, 0x8C, 0xA5, 0xC9, 0x84, 0x2D, 0x71, 0x01, 0xA2, 0x2A, 0x01, 0xB0, 0x15, 0xFB, 0x30, 0x78, 0xB9, 0x13, 0xF4, 0xC7, 0x3F, 0xB5, 0xA6, 0xF1, 0xA2, 0x5E, 0x22, 0xB0, 0x02, 0xB6, 0xE0, 0x09, 0x54, 0x7F, 0x0F, 0xBD, 0xF0, 0xFE, 0xA5, 0x50, 0x1D, 0x93, 0x15, 0xF9, 0x3D, 0x83, 0x0F, 0x0F, 0x0E, 0x3D, 0xE2, 0x3D, 0x96, 0xE7, 0x09, 0xD9, 0x77, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
