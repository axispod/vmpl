#pragma once

namespace vmpl
{
	/**
	 * Container for list of variadic types.
	 */
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

	/**
	 * Create holder type.
	 *
	 * The function collapses all holders into one.
	 *
	 * @b Examples
     * @code{.cpp}
     * typedef make_holder<int, char, float>::type ht; // holder<int, char, float>
	 * typedef make_holder<int, holder<>, holder<char, float>>::type ht2; // holder<int, char, float>
	 * typedef make_holder<int, ht2>::type ht3; // holder<int, int, char, float>
	 * typedef make_holder<ht3, double>::type ht4; // holder<int, int, char, float, double>
     * @endcode
	 */
	template<typename ...Args>
	struct make_holder
	{
		typedef typename make_holder_helper<Args...>::type type;
	};	
}
