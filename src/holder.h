#pragma once

namespace vmpl
{
	template<typename ...Args>
	struct holder;

	template<typename ...Args>
	struct make_holder
	{
		typedef holder<Args...> type;
	};

	template<typename ...Args>
	struct make_holder<holder<Args...>>
	{
		typedef holder<Args...> type;
	};

	template<typename RType, typename ...Args>
	struct make_holder<RType(Args...)>
	{
		typedef holder<Args...> type;
	};

	template<typename RType, typename ...Args>
	struct make_holder<RType(*)(Args...)>
	{
		typedef holder<Args...> type;
	};
}
