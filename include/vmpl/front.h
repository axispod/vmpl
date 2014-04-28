#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<typename ... Args>
		struct front_helper;

		template<typename T, typename ... Args>
		struct front_helper<T, Args...>
		{
			typedef holder<T> type;
		};

		template<>
		struct front_helper<>
		{
			typedef holder<> type;
		};
	}

	template<typename ... Args>
	struct front : public front_helper<Args...> {};

	template<typename ... Args>
	struct front<holder<Args...>> : public front_helper<Args...> {};
}