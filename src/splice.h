#pragma once

#include "holder.h"
#include "push_front.h"

namespace vmpl
{
	namespace
	{
		template<unsigned int Length, typename ... Args>
		struct splice_push_helper;

		template<unsigned int Length, typename T, typename ... Args>
		struct splice_push_helper<Length, T, Args...>
		{
			typedef typename push_front<T, typename splice_push_helper<Length-1, Args...>::type>::type type;
		};

		template<typename T, typename ... Args>
		struct splice_push_helper<0, T, Args...>
		{
			typedef T type;
		};

		template<unsigned int Length>
		struct splice_push_helper<Length>
		{
			typedef holder<> type;
		};

		template<>
		struct splice_push_helper<0>
		{
			typedef holder<> type;
		};

		template<unsigned int Begin, unsigned int Length, typename ... Args>
		struct splice_helper;

		template<unsigned int Begin, unsigned int Length, typename T, typename ... Args>
		struct splice_helper<Begin, Length, T, Args...>
		{
			typedef typename splice_helper<Begin-1, Length, Args...>::type type;
		};

		template<unsigned int Length, typename ... Args>
		struct splice_helper<0, Length, Args...>
		{
			typedef typename splice_push_helper<Length-1, Args...>::type type;
		};
	}

	template<unsigned int Begin, unsigned int Length, typename ... Args>
	struct splice
	{
		typedef typename splice_helper<Begin, Length, Args...>::type type;
	};

	template<unsigned int Begin, unsigned int Length, typename ... Args>
	struct splice<Begin, Length, holder<Args...>>
	{
		typedef typename splice_helper<Begin, Length, Args...>::type type;
	};
}