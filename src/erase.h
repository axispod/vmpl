#pragma once

#include "holder.h"
#include "split.h"

namespace vmpl
{
	namespace
	{
		template<unsigned int Position, unsigned int Length, typename ...Args>
		struct erase_helper
		{
			typedef typename split<Position, Args...> split_type;
			typedef typename make_holder<typename split_type::head_type, typename split<Length, typename split_type::tail_type>::tail_type>::type type;
		};
	}

	template<unsigned int Position, typename ...Args>
	struct erase
	{
		typedef typename erase_helper<Position, 1, Args...>::type type;
	};

	template<unsigned int Position, typename ...Args>
	struct erase<Position, holder<Args...>>
	{
		typedef typename erase_helper<Position, 1, Args...>::type type;
	};
}