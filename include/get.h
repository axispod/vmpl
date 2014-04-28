#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<typename ... Args>
		struct get_helper;

		template<typename T, typename ... Args>
		struct get_helper<T, Args...>
		{
			typedef T type;
		};

		template<typename DT, typename ... Args>
		struct safe_get_helper;

		template<typename DT, typename T, typename ... Args>
		struct safe_get_helper<DT, T, Args...>
		{
			typedef T type;
		};

		template<typename DT>
		struct safe_get_helper<DT>
		{
			typedef DT type;
		};
	}

	template<typename ... Args>
	struct get : public get_helper<Args...> {};

	template<typename ... Args>
	struct get<holder<Args...>> : public get_helper<Args...> {};

	template<typename DT, typename ... Args>
	struct safe_get : public safe_get_helper<DT, Args...> {};

	template<typename DT, typename ... Args>
	struct safe_get<DT, holder<Args...>> : public safe_get_helper<DT, Args...>{};
}