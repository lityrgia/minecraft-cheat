
#ifndef UTIL_FNV1A_H
#define UTIL_FNV1A_H

#include <cstdint>
#include <cstring>

namespace util
{
	constexpr uint32_t fnv1a_seed = 0x37C4271F;
	constexpr uint32_t fnv1a_prime = 0x1000193;
	__declspec(dllexport) extern uint32_t runtime_basis;

	inline uint32_t fnv1a(const char* key)
	{
		const char* data = const_cast<char*>(key);
		auto hash = runtime_basis;

#if defined(CSGO_SECURE) && !defined(_DEBUG)
		hash ^= __readfsdword(0x20);
#endif

		for (size_t i = 0; i < strlen(key); ++i)
		{
			const uint8_t value = data[i];
			hash = hash ^ value;
			hash *= fnv1a_prime;
		}

		return hash;
	}

	constexpr uint32_t fnv1a_ct(const char* str, const uint32_t value = fnv1a_seed) noexcept
	{
		return !*str ? value
			: fnv1a_ct(str + 1, static_cast<unsigned>(1ull * (value ^ static_cast<uint8_t>(*str)) * fnv1a_prime));
	}
} // namespace util

#define FNV1A(s) (::util::fnv1a_ct(s))
#define FNV1A_CMP(a, b) (::util::fnv1a_ct(b)) == ::util::fnv1a(a))
#define FNV1A_CMP_IM(a, b) (b == ::util::fnv1a(a))

#endif // UTIL_FNV1A_H