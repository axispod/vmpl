#pragma once

#include "holder.h"
#include "split.h"

namespace vmpl
{
	namespace
	{
		template<unsigned Position, unsigned Length, typename ...Args>
		struct erase_helper
		{
			typedef typename split<Position, Args...> split_type;
			typedef typename make_holder<typename split_type::head_type, typename split<Length, typename split_type::tail_type>::tail_type>::type type;
		};
	}

	/**
	* Erase type into variadic list by Position.
	* @b Examples
	* @code{.cpp}
	* typedef erase<1, int, char, float>::type ht; // holder<int, float>
	* @endcode
	*/
	template<unsigned Position, typename ...Args>
	struct erase
	{
		typedef typename erase_helper<Position, 1, Args...>::type type;
	};

	/**
	* Erase type into variadic holder by Position.
	* @b Examples
	* @code{.cpp}
	* typedef holder<int, char, float> ht; // holder<int, char, float>
	* typedef erase<1, ht>::type ht2; // holder<int, float>
	* @endcode
	*/
	template<unsigned Position, typename ...Args>
	struct erase<Position, holder<Args...>>
	{
		typedef typename erase_helper<Position, 1, Args...>::type type;
	};

	/**
	* Erase types into variadic list of Length by Position.
	* @b Examples
	* @code{.cpp}
	* typedef erase_length<1, 2, int, char, char, float>::type ht; // holder<int, float>
	* @endcode
	*/
	template<unsigned Position, unsigned Length, typename ...Args>
	struct erase_length
	{
		typedef typename erase_helper<Position, Length, Args...>::type type;
	};

	/**
	* Erase type into variadic holder of Length by Position.
	* @b Examples
	* @code{.cpp}
	* typedef holder<int, char, charm float> ht; // holder<int, char, float>
	* typedef erase_length<1, 2, ht>::type ht2; // holder<int, float>
	* @endcode
	*/
	template<unsigned Position, unsigned Length, typename ...Args>
	struct erase_length<Position, Length, holder<Args...>>
	{
		typedef typename erase_helper<Position, Length, Args...>::type type;
	};
}