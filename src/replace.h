#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<typename From, typename To, typename Src>
		struct get_type
		{
			typedef Src type;
		};

		template<typename From, typename To>
		struct get_type<From, To, From>
		{
			typedef To type;
		};
	}

	template<typename From, typename To, typename ...Args>
	struct replace
	{
		typedef holder<typename get_type<From, To, Args>::type...> type;
	};

	template<typename From, typename To, typename ...Args>
	struct replace<From, To, holder<Args...>>
	{
		typedef typename replace<From, To, Args...>::type type;
	};
}