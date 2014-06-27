#pragma once

#include <cstdint>

namespace vmpl
{
	template<std::size_t N>
	using size_t_ = std::integral_constant<std::size_t, N>;

	template<int N>
	using int_ = std::integral_constant<int, N>;

	template<unsigned int N>
	using uint_ = std::integral_constant<unsigned int, N>;
}