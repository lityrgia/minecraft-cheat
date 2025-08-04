#pragma once

uint16_t TEA_ROUNDS = XOR_16(32);
uint32_t TEA_DELTA = XOR_32(0x9e5149b9);

#pragma optimize("", off)
uint64_t __cdecl tea_encrypt(uint64_t value, const uint32_t key[4]) {
    uint32_t v0 = static_cast<uint32_t>(value >> 32);
    uint32_t v1 = static_cast<uint32_t>(value & 0xFFFFFFFF);

    uint32_t sum = 0;
    for (uint32_t i = 0; i < TEA_ROUNDS; ++i) {
        sum += TEA_DELTA;
        v0 += ((v1 << 4) + key[0]) ^ (v1 + sum) ^ ((v1 >> 5) + key[1]);
        v1 += ((v0 << 4) + key[2]) ^ (v0 + sum) ^ ((v0 >> 5) + key[3]);
    }

    return (static_cast<uint64_t>(v0) << 32) | v1;
}

uint64_t tea_decrypt(uint64_t value, const uint32_t key[4]) {
    uint32_t v0 = static_cast<uint32_t>(value >> 32);
    uint32_t v1 = static_cast<uint32_t>(value & 0xFFFFFFFF);

    uint32_t sum = TEA_DELTA * TEA_ROUNDS;
    for (uint32_t i = 0; i < TEA_ROUNDS; ++i) {
        v1 -= ((v0 << 4) + key[2]) ^ (v0 + sum) ^ ((v0 >> 5) + key[3]);
        v0 -= ((v1 << 4) + key[0]) ^ (v1 + sum) ^ ((v1 >> 5) + key[1]);
        sum -= TEA_DELTA;
    }

    return (static_cast<uint64_t>(v0) << 32) | v1;
}