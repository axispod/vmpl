#pragma once

#include "holder.h"

namespace vmpl
{
	namespace
	{
		template<typename Applier, typename T>
		struct apply_helper
		{
			typedef typename Applier::template apply<T>::type type;
		};

		template<typename Applier, typename ... Args>
		struct transform_helper
		{
			typedef holder<typename apply_helper<Applier, Args>::type...> type;
		};
	}

	template<typename Applier, typename ... Args>
	struct transform
	{
		typedef typename transform_helper<Applier, Args...>::type type;
	};

	template<typename Applier, typename ... Args>
	struct transform<Applier, holder<Args...>>
	{
		typedef typename transform<Applier, Args...>::type type;
	};
}