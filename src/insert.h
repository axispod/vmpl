#pragma once

#include "holder.h"
#include "split.h"

namespace vmpl
{
	namespace
	{
		template<typename T, unsigned int Position, typename ... Args>
		struct insert_helper
		{
			typedef split<Position, Args...> split_type;
			typedef typename make_holder<typename split_type::head_type, T, typename split_type::tail_type>::type type;
		};
	}

	template<typename T, unsigned int Position, typename ... Args>
	struct insert
	{
		typedef typename insert_helper<T, Position, Args...>::type type;
	};

	template<typename T, unsigned int Position, typename ... Args>
	struct insert<T, Position, holder<Args...>>
	{
		typedef typename insert<T, Position, Args...>::type type;
	};
}