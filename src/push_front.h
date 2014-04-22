#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<typename T, typename ... Args>
		struct push_front_helper
		{
			typedef holder<T, Args...> type;
		};
	}

	template<typename T, typename ... Args>
	struct push_front
	{
		typedef typename push_front_helper<T, Args...>::type type;
	};

	template<typename T, typename ... Args>
	struct push_front<T, holder<Args...>>
	{
		typedef typename push_front_helper<T, Args...>::type type;
	};
}