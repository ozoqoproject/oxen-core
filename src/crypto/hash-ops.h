// Copyright (c) 2014-2019, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#if !defined(__cplusplus)

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#pragma pack(push, 1)
union hash_state {
  uint8_t b[200];
  uint64_t w[25];
};
#pragma pack(pop)
static_assert(sizeof(union hash_state) == 200, "Invalid structure size");

void hash_permutation(union hash_state *state);
void hash_process(union hash_state *state, const uint8_t *buf, size_t count);

#endif

enum
{
  HASH_SIZE      = 32,
  HASH_DATA_AREA = 136
};

#define CN_TURTLE_PAGE_SIZE 262144
void cn_fast_hash(const void *data, size_t length, unsigned char *hash);
void cn_turtle_hash(const void *data, size_t length, unsigned char *hash, int light, int variant, int prehashed, uint32_t scratchpad, uint32_t iterations);
#ifdef ENABLE_MONERO_SLOW_HASH
void cn_monero_hash(const void *data, size_t length, unsigned char *hash, int variant, int prehashed);
#endif

void hash_extra_blake(const void *data, size_t length, unsigned char *hash);
void hash_extra_groestl(const void *data, size_t length, unsigned char *hash);
void hash_extra_jh(const void *data, size_t length, unsigned char *hash);
void hash_extra_skein(const void *data, size_t length, unsigned char *hash);

void tree_hash(const unsigned char (*hashes)[HASH_SIZE], size_t count, unsigned char *root_hash);

void rx_slow_hash_allocate_state(void);
void rx_slow_hash_free_state(void);
uint64_t rx_seedheight(const uint64_t height);
void rx_seedheights(const uint64_t height, uint64_t *seed_height, uint64_t *next_height);
void rx_slow_hash(const uint64_t mainheight, const uint64_t seedheight, const unsigned char *seedhash, const void *data, size_t length, unsigned char *hash, int miners, int is_alt);
void rx_reorg(const uint64_t split_height);
