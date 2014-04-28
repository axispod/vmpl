#pragma once

#include "holder.h"
#include "split.h"

namespace vmpl
{
	template<unsigned int Begin, unsigned int Length, typename ... Args>
	struct splice
	{
		typedef typename split<Length, typename split<Begin, Args...>::tail_type>::head_type type;
	};

	template<unsigned int Begin, unsigned int Length, typename ... Args>
	struct splice<Begin, Length, holder<Args...>>
	{
		typedef typename splice<Begin, Length, Args...>::type type;
	};
}