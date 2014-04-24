#pragma once

#include "holder.h"
#include "split.h"

namespace vmpl
{
	template<typename ... Args>
	struct pop_front
	{
		typedef typename split<1, Args...>::tail_type type;
	};

	template<typename ... Args>
	struct pop_front<holder<Args...>>
	{
		typedef typename split<1, Args...>::tail_type type;
	};

	template<typename ... Args>
	struct pop_back
	{
		typedef typename split<sizeof...(Args) - 1, Args...>::head_type type;
	};

	template<typename ... Args>
	struct pop_back<holder<Args...>>
	{
		typedef typename split<sizeof...(Args)-1, Args...>::head_type type;
	};
}