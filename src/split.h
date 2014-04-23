#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<unsigned int Position, typename ... Args>
		struct split_helper;

		template<unsigned int Position, typename T, typename ... Args>
		struct split_helper<Position, T, Args...>
		{
			typedef typename split_helper<Position - 1, Args...> recursive_type;
			typedef typename make_holder<T, typename recursive_type::head_type>::type head_type;
			typedef typename recursive_type::tail_type tail_type;
		};

		template<typename ... Args>
		struct split_helper<0, Args...>
		{
			typedef holder<> head_type;
			typedef holder<Args...> tail_type;
		};

		template<unsigned int Position>
		struct split_helper<Position>;

		template<>
		struct split_helper<0>;
	}

	template<unsigned int Position, typename ... Args>
	struct split : public split_helper<Position, Args...>{};

	template<unsigned int Position, typename ... Args>
	struct split<Position, holder<Args...>> : public split_helper<Position, Args...>{};
}