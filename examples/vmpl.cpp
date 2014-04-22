// vmpl.cpp : Defines the entry point for the console application.
//

#include "../vsspecific/stdafx.h"

#include "../src/at.h"
#include "../src/integer_sequence.h"
#include "../src/reverse.h"
#include "../src/replace.h"
#include "../src/transform.h"

#include <iostream>
#include <typeinfo>
#include <type_traits>

#include "print.h"

using namespace vmpl;

template<std::size_t N>
using _int = std::integral_constant<std::size_t, N>;

template<std::size_t add>
struct add_const
{
	template<typename T>
	struct apply;

	template<std::size_t V>
	struct apply<_int<V>>
	{
		typedef _int<V+add> type;
	};
};

struct sqr
{
	template<typename T>
	struct apply;

	template<std::size_t V>
	struct apply<_int<V>>
	{
		typedef _int<V * V> type;
	};
};

namespace
{
	template<typename T>
	struct type_replacer_helper
	{
		typedef T type;
	};

	template<>
	struct type_replacer_helper<const char*>
	{
		typedef const std::string& type;
	};
}

struct type_replacer
{
	template<typename T>
	struct apply
	{
		typedef typename type_replacer_helper<T>::type type;
	};
};

struct type_decay
{
	template<typename T>
	struct apply
	{
		typedef typename std::decay<T>::type type;
	};
};


int _tmain(int argc, _TCHAR* argv[])
{
	typedef holder<int, char, double> ht_;
	typedef reverse<ht_>::type ht_2;
	typedef replace<int, unsigned int, ht_2>::type ht;
	typedef at<0, ht>::type t0;
	typedef at<1, ht>::type t1;
	typedef at<2, ht>::type t2;
	typedef at<3, ht>::type t3;

	print<t0>(std::cout);
	print<t1>(std::cout);
	print<t2>(std::cout);
	print<t3>(std::cout);

	typedef holder<_int<1>, _int<2>, _int<3>> hs;
	typedef transform<add_const<10>, hs>::type h1;
	typedef transform<sqr, hs>::type h2;

	print<h1>(std::cout);
	print<h2>(std::cout);

	typedef make_holder<void(int, const char*, const char*)>::type hf;
	typedef transform<type_replacer, hf>::type hf1;
	typedef transform<type_decay, hf>::type hf2;

	print<hf1>(std::cout);
	print<hf2>(std::cout);

	return 0;
}

