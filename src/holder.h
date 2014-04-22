#pragma once

namespace vmpl
{
	template<typename ...Args>
	struct holder;

	namespace
	{
		template<typename ...Args>
		struct to_holder
		{
			typedef holder<Args...> type;
		};

		template<typename T>
		struct to_holder<T>
		{
			typedef holder<T> type;
		};

		template<typename T>
		struct to_holder<holder<T>>
		{
			typedef holder<T> type;
		};

		template<typename ...Args>
		struct to_holder<holder<Args...>>
		{
			typedef holder<Args...> type;
		};

		template<typename RType, typename ...Args>
		struct to_holder<RType(Args...)>
		{
			typedef holder<Args...> type;
		};

		template<typename RType, typename ...Args>
		struct to_holder<RType(*)(Args...)>
		{
			typedef holder<Args...> type;
		};

		template<typename ...Args>
		struct implode;

		template<typename ...Args>
		struct implode<holder<Args...>>
		{
			typedef holder<Args...> type;
		};

		template<typename ...Args, typename ...Args2>
		struct implode<holder<Args...>, holder<Args2...>>
		{
			typedef holder<Args..., Args2...> type;
		};

		template<typename ...Args, typename ...Args2, typename ...Args3>
		struct implode<holder<Args...>, holder<Args2...>, Args3...>
		{
			typedef typename implode<holder<Args..., Args2...>, Args3...>::type type;
		};

		template<typename ...Args>
		struct make_holder_helper
		{
			typedef typename implode<typename to_holder<Args>::type...>::type type;
		};
	}

	template<typename ...Args>
	struct make_holder
	{
		typedef typename make_holder_helper<Args...>::type type;
	};	
}
