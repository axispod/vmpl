#pragma once

#include "holder.h"

namespace vmpl
{
	template<typename T, typename ... Args>
	struct push_back : public make_holder<Args..., T> {};

	template<typename T, typename ... Args>
	struct push_front : public make_holder<T, Args...> {};
}