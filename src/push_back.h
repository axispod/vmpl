#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<typename T, typename ... Args>
		struct push_back_helper
		{
			typedef holder<Args..., T> type;
		};
	}

	template<typename T, typename ... Args>
	struct push_back
	{
		typedef typename push_back_helper<T, Args...>::type type;
	};

	template<typename T, typename ... Args>
	struct push_back<T, holder<Args...>>
	{
		typedef typename push_back_helper<T, Args...>::type type;
	};
}