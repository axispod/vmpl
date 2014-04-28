#pragma once

#include "holder.h"

namespace vmpl
{
	template<typename ... Args>
	struct empty
	{
		static const bool value = false;
	};

	template<typename ... Args>
	struct empty<holder<Args...>>
	{
		static const bool value = false;
	};

	template<>
	struct empty<>
	{
		static const bool value = true;
	};

	template<>
	struct empty<holder<>>
	{
		static const bool value = true;
	};
}