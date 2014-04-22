#pragma once

#include "holder.h"
#include <utility>

namespace vmpl
{
	struct not_found{};

	namespace
	{
		template<std::size_t Pos, typename ... Args>
		struct at_helper
		{
			typedef typename at_helper<Pos - 1, Args...>::type type;
		};

		template<std::size_t Pos, typename Head, typename ... Args>
		struct at_helper<Pos, Head, Args...>
		{
			typedef typename at_helper<Pos - 1, Args...>::type type;
		};

		template<typename Head, typename ... Args>
		struct at_helper<0, Head, Args...>
		{
			typedef Head type;
		};

		template<>
		struct at_helper<0>
		{
			typedef not_found type;
		};
	}

	template<std::size_t Pos, typename ... Args>
	struct at : public at_helper<Pos, Args...>{};

	template<std::size_t Pos, typename ... Args>
	struct at<Pos, holder<Args...>> : public at_helper<Pos, Args...>{};
}