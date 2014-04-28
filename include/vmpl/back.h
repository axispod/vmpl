#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<typename ... Args>
		struct back_helper;

		template<typename T, typename ... Args>
		struct back_helper<T, Args...>
		{
			typedef typename back_helper<Args...>::type type;
		};

		template<typename T>
		struct back_helper<T>
		{
			typedef holder<T> type;
		};

		template<>
		struct back_helper<>
		{
			typedef holder<> type;
		};
	}

	template<typename ... Args>
	struct back : public back_helper<Args...> {};

	template<typename ... Args>
	struct back<holder<Args...>> : public back_helper<Args...>{};
}