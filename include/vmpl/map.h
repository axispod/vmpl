#pragma once

#include <type_traits>

#include "holder.h"
#include "pair.h"
#include "numrics.h"
#include "at.h"
#include "erase.h"
#include "insert.h"
#include "replace.h"

namespace vmpl
{
	namespace
	{
		template<int Pos, typename First, typename ... Args>
		struct map_index_helper;

		template<int Pos, typename First, typename Item, typename ... Args>
		struct map_index_helper<Pos, First, Item, Args...>
		{
			static const int value = std::is_same<First, typename Item::first_type>::value ? Pos : typename map_index_helper<Pos + 1, First, Args...>::value;
		};

		template<int Pos, typename First>
		struct map_index_helper<Pos, First>
		{
			static const int value = -1;
		};
	}

	template<typename First, typename ... Args>
	struct map_index
	{
		static const int value = map_index_helper<0, First, Args...>::value;
	};

	template<typename First, typename ... Args>
	struct map_index<First, holder<Args...>>
	{
		static const int value = map_index_helper<0, First, Args...>::value;
	};

	template<typename First, typename ... Args>
	struct map_find
	{
		typedef typename std::conditional <
			std::is_same<int_<-1>, int_<map_index<First, Args...>::value>>::value,
			void,
			typename get<typename at<map_index<First, Args...>::value, Args...>::type>::type
		>::type type;
	};

	template<typename First, typename ... Args>
	struct map_find<First, holder<Args...>>
	{
		typedef typename map_find<First, Args...>::type type;
	};	

	template<typename T, typename After, typename ... Args>
	struct map_insert
	{
		typedef int_<map_index<After, Args...>::value> pos;
		static_assert(!std::is_same<pos, int_<-1>>::value, "Item After not found");
		static_assert(is_pair<T>::value, "Type isn't pair");

		typedef typename insert<T, pos::value + 1, Args...>::type type;;
	};

	template<typename T, typename After, typename ... Args>
	struct map_insert<T, After, holder<Args...>>
	{
		typedef typename map_insert<T, After, Args...>::type type;
	};

	template<typename T, typename ... Args>
	struct map_erase
	{
		typedef int_<map_index<T, Args...>::value> pos;
		static_assert(!std::is_same<pos, int_<-1>>::value, "Item to erase not found");

		typedef typename erase<pos::value, Args...>::type type;;
	};

	template<typename T, typename ... Args>
	struct map_erase<T, holder<Args...>>
	{
		typedef typename map_erase<T, Args...>::type type;
	};

	template<typename From, typename To, typename ... Args>
	struct map_replace
	{
		typedef int_<map_index<From, Args...>::value> pos;
		static_assert(!std::is_same<pos, int_<-1>>::value, "Item From not found");
		static_assert(is_pair<To>::value, "Type To isn't pair");

		typedef typename replace<
			typename get<typename at<pos::value, Args...>::type>::type, 
			To, 
			Args...>::type type;;
	};

	template<typename From, typename To, typename ... Args>
	struct map_replace<From, To, holder<Args...>>
	{
		typedef typename map_replace<From, To, Args...>::type type;
	};
}