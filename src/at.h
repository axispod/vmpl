#pragma once

#include "holder.h"
#include <utility>

namespace vmpl
{
	namespace
	{
		template<unsigned Pos, typename ... Args>
		struct at_helper
		{
			typedef typename at_helper<Pos - 1, Args...>::type type;
		};

		template<unsigned Pos, typename Head, typename ... Args>
		struct at_helper<Pos, Head, Args...>
		{
			typedef typename at_helper<Pos - 1, Args...>::type type;
		};

		template<typename Head, typename ... Args>
		struct at_helper<0, Head, Args...>
		{
			typedef Head type;
		};

		template<>
		struct at_helper<0>;
	}

	/**
	 * Get type from variadic list by Position
	 * @b Examples
	 * @code{.cpp}
	 * typedef at<1, int, char, float>::type type; // char
	 * @endcode
	 */
	template<unsigned Position, typename ... Args>
	struct at : public at_helper<Position, Args...>{};

	/**
	* Get type from variadic holder by Position
	* @b Examples
	* @code{.cpp}
	* typedef holder<int, char, float> ht; // holder<int, char, float>
	* typedef at<1, ht>::type type; // char
	* @endcode
	*/
	template<unsigned Position, typename ... Args>
	struct at<Position, holder<Args...>> : public at_helper<Position, Args...>{};
}