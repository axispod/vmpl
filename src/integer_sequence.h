#pragma once
#include <type_traits>
#include <cinttypes>

namespace vmpl
{
	// integer_sequence from C++14
	template<typename T, T ... indices> struct integer_sequence 
	{
		typedef T value_type;
		static T size() { return sizeof...(indices); }
	};

	template<typename T, typename currentIndex, T ...indices> struct make_integer_sequence_helper;

	template<typename T, T ...indices> struct make_integer_sequence_helper<T, std::integral_constant<T, 0>, indices...> 
	{
		typedef integer_sequence<T, indices...> type;
	};

	template<typename T, typename currentIndex, T ...indices> struct make_integer_sequence_helper 
	{
		typedef typename make_integer_sequence_helper<T, std::integral_constant<T, currentIndex::value - 1>, currentIndex::value - 1, indices...>::type type;
	};

	template<typename T, T length> struct make_integer_sequence : public make_integer_sequence_helper<T, std::integral_constant<T, length> > { };
	// end of integer_sequence

	template<std::size_t ... indices>
	using index_sequence = integer_sequence<std::size_t, indices...>;

	template<std::size_t length>
	using make_index_sequence = make_integer_sequence<std::size_t, length>;
}
