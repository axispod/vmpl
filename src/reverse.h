#pragma once

#include "holder.h"
#include "at.h"

namespace vmpl
{
	namespace
	{
		template<typename ... Args>
		struct reverse_helper;

		template<typename Head, typename ... Args>
		struct reverse_helper<Head, Args...>
		{
			typedef typename make_holder<typename reverse_helper<Args...>::type, Head>::type type;
		};

		template<typename Head>
		struct reverse_helper<Head>
		{
			typedef typename holder<Head> type;
		};
	}

	template<typename ... Args>
	struct reverse
	{
		typedef typename reverse_helper<Args...>::type type;
	};

	template<typename ... Args>
	struct reverse<holder<Args...>>
	{
		typedef typename reverse_helper<Args...>::type type;
	};
}
