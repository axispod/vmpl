#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<typename T, typename HT>
		struct push_back_helper;

		template<typename T, typename ...Args>
		struct push_back_helper<T, holder<Args...>>
		{
			typedef holder<Args..., T> type;
		};
	}

	template<typename HT, typename T>
	struct push_back
	{
		typedef typename push_back_helper<T, HT>::type type;
	};
}