#pragma once

#include "holder.h"

namespace vmpl
{
	template<typename ... Args>
	struct size
	{
		static const unsigned value = sizeof...(Args);
	};

	template<typename ... Args>
	struct size<holder<Args...>>
	{
		static const unsigned value = sizeof...(Args);
	};
}