#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<unsigned int Position, typename ... Args>
		struct split_left_helper;

		template<unsigned int Position, typename T, typename ... Args>
		struct split_left_helper<Position, T, Args...>
		{
			typedef typename make_holder<T, typename split_left_helper<Position - 1, Args...>::type>::type type;
		};

		template<typename ... Args>
		struct split_left_helper<0, Args...>
		{
			typedef typename holder<> type;
		};

		template<unsigned int Position>
		struct split_left_helper<Position>;

		template<>
		struct split_left_helper<0>;

		template<unsigned int Position, typename ... Args>
		struct split_right_helper;

		template<unsigned int Position, typename T, typename ... Args>
		struct split_right_helper<Position, T, Args...>
		{
			typedef typename split_right_helper<Position - 1, Args...>::type type;
		};

		template<typename ... Args>
		struct split_right_helper<0, Args...>
		{
			typedef holder<Args...> type;
		};
	}

	template<unsigned int Position, typename ... Args>
	struct split
	{
		typedef typename split_left_helper<Position, Args...>::type head_type;
		typedef typename split_right_helper<Position, Args...>::type tail_type;
	};

	template<unsigned int Position, typename ... Args>
	struct split<Position, holder<Args...>>
	{
		typedef typename split_left_helper<Position, Args...>::type head_type;
		typedef typename split_right_helper<Position, Args...>::type tail_type;
	};
}