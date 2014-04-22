#pragma once

#include "holder.h"
#include "split.h"

namespace vmpl
{
	namespace
	{
		template<typename T, unsigned Position, typename ... Args>
		struct insert_helper
		{
			typedef split<Position, Args...> split_type;
			typedef typename make_holder<typename split_type::head_type, T, typename split_type::tail_type>::type type;
		};
	}

	/**
	 * Insert type T into variadic list by Position.
	 * @b Examples
	 * @code{.cpp}
	 * typedef insert<double, 2, int, char, float>::type ht; // holder<int, char, double, float>
	 * @endcode
	 */
	template<typename T, unsigned Position, typename ... Args>
	struct insert
	{
		typedef typename insert_helper<T, Position, Args...>::type type;
	};

	/**
	* Insert type T into variadic holder by Position.
	* @b Examples
	* @code{.cpp}
	* typedef holder<int, char, float> ht; // holder<int, char, float>
	* typedef insert<double, 2, ht>::type ht2; // holder<int, char, double, float>
	* @endcode
	*/
	template<typename T, unsigned Position, typename ... Args>
	struct insert<T, Position, holder<Args...>>
	{
		typedef typename insert<T, Position, Args...>::type type;
	};
}