
#ifndef UTIL_VALUE_OBFUSCATION_H
#define UTIL_VALUE_OBFUSCATION_H

#include "tinyformat/tinyformat.h"
#include "random.h"

namespace util
{
	template <typename T, T A, T B> class xor_value
	{
	public:
		__forceinline static T get() { return value ^ cipher; }

	private:
		volatile static const inline T value{ A ^ B }, cipher{ B };
	};

	template <size_t N, char K> struct xor_str
	{
	private:
		static constexpr char enc(const char c) { return c ^ K; }

	public:
		template <size_t... s>
		constexpr __forceinline xor_str(const char* str, std::index_sequence<s...>) : encrypted{ enc(str[s])... }
		{
		}

		__forceinline std::string dec()
		{
			std::string dec;
			dec.resize(N);

			for (auto i = 0u; i < N; i++)
				dec[i] = encrypted[i] ^ K;

			return dec;
		}

		__forceinline std::string ot(bool decrypt = true)
		{
			std::string dec;
			dec.resize(N);

			for (auto i = 0u; i < N; i++)
			{
				dec[i] = decrypt ? (encrypted[i] ^ K) : encrypted[i];
				encrypted[i] = '\0';
			}

			return dec;
		}

		volatile char encrypted[N];
	};

	template <typename T = uintptr_t> class encrypted_ptr
	{
	public:
		__forceinline encrypted_ptr() { this->value = this->cipher = RANDOM_SEED; }

		__forceinline explicit encrypted_ptr(T* const value) { *this = encrypted_ptr(uintptr_t(value)); }

		__forceinline explicit encrypted_ptr(uintptr_t value)
		{
			this->cipher = RANDOM_SEED;
			this->value = uintptr_t(value) ^ this->cipher;
		}

		__forceinline T* operator()() const { return operator->(); }

		__forceinline T& operator*() const { return *reinterpret_cast<T*>(this->value ^ this->cipher); }

		__forceinline T* operator->() const { return reinterpret_cast<T*>(this->value ^ this->cipher); }

		__forceinline bool operator==(const encrypted_ptr& other) const { return this->operator->() == other.operator->(); }

		explicit __forceinline operator bool() const { return !this->operator!(); }

		__forceinline bool operator!() const { return this->operator->() == nullptr; }

		__forceinline uintptr_t at(ptrdiff_t rel) const { return uintptr_t(operator->()) + rel; }

		__forceinline encrypted_ptr<T>& deref(const size_t amnt)
		{
			for (auto i = 0u; i < amnt; i++)
				*this = encrypted_ptr<T>(*reinterpret_cast<T**>(this->value ^ this->cipher));
			return *this;
		}

	private:
		volatile uintptr_t value{};
		volatile uintptr_t cipher{};
	};

	template <typename t = int32_t> t __forceinline add(t a, t b, t c)
	{
		return (((a ^ b) + ((a & b) << 1)) | c) + (((a ^ b) + ((a & b) << 1)) & c);
	}
} // namespace util

#define XOR_16(val)                                                                                                    \
	(decltype(val))(::util::xor_value<uint16_t, (uint16_t)val,                                                         \
									  ::util::random::_uint<__COUNTER__, 0xFFFF>::value>::get())
#define XOR_32(val)                                                                                                    \
	(decltype(val))(::util::xor_value<uint32_t, (uint32_t)val,                                                         \
									  ::util::random::_uint<__COUNTER__, 0xFFFFFFFF>::value>::get())
#define XOR_STR_S(s)                                                                                                   \
	::util::xor_str<sizeof(s), ::util::random::_char<__COUNTER__>::value>(s, std::make_index_sequence<sizeof(s)>())
#define XOR_STR(s) XOR_STR_S(s).dec().c_str()
#define XOR_STR_OT(s) XOR_STR_S(s).ot().c_str()
#define XOR_FORMAT(s, ...) tfm::format(XOR_STR(s), __VA_ARGS__)
#define XOR_STR_STORE(s)                                                                                               \
	[]() -> std::pair<std::string, char>                                                                               \
	{                                                                                                                  \
		constexpr auto key = ::util::random::_char<__COUNTER__>::value;                                                \
		return std::make_pair(::util::xor_str<sizeof(s), key>(s, std::make_index_sequence<sizeof(s)>()).ot(false),     \
							  key);                                                                                    \
	}()
#define XOR_STR_STACK(n, s)                                                                                            \
	auto(n) = reinterpret_cast<char *>(alloca(((s).first.size() + 1) * sizeof(char)));                                 \
	for (size_t i = 0; i < (s).first.size(); i++)                                                                      \
		(n)[i] = (s).first[i] ^ (s).second;                                                                            \
	(n)[(s).first.size()] = '\0'
#define XOR_STR_STACK_WIDE(n, s)                                                                                       \
	auto(n) = reinterpret_cast<wchar_t *>(alloca(((s).first.size() + 1) * sizeof(wchar_t)));                           \
	for (size_t i = 0; i < (s).first.size(); i++)                                                                      \
		(n)[i] = (s).first[i] ^ (s).second;                                                                            \
	(n)[(s).first.size()] = '\0'

#define XOR(s) XOR_STR(s)

#endif // UTIL_VALUE_OBFUSCATION_H