// vmpl.cpp : Defines the entry point for the console application.
//

#include "../vsspecific/stdafx.h"

#include "../src/at.h"
#include "../src/integer_sequence.h"
#include "../src/reverse.h"
#include "../src/replace.h"
#include "../src/transform.h"
#include "../src/splice.h"
#include "../src/split.h"
#include "../src/insert.h"
#include "../src/erase.h"
#include "../src/push.h"
#include "../src/size.h"
#include "../src/empty.h"
#include "../src/front.h"
#include "../src/back.h"
#include "../src/pop.h"
#include "../src/get.h"

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
	typedef make_holder<holder<int, const char*>, holder<>, char, holder<float, double>>::type ht_;					// int, const char*, char, float, double
	std::cout << "make_holder: "; print<ht_>(std::cout);
	typedef reverse<ht_>::type ht_2;						// double, float, char, const char*, int
	std::cout << "reverse: "; print<ht_2>(std::cout);
	typedef replace<int, unsigned int, ht_2>::type ht_3;	// double, float, char, const char*, uint
	std::cout << "replace<int, unsigned>: "; print<ht_3>(std::cout);
	typedef push_front<short, ht_3>::type ht_4;				// short, double, float, char, const char*, uint
	std::cout << "push_front<short>: "; print<ht_4>(std::cout);
	typedef insert<unsigned short, 2, ht_4>::type ht_5;		// short, double, ushort, float, char, const char*, uint
	std::cout << "insert<ushort, 2>: "; print<ht_5>(std::cout);
	typedef erase<3, ht_5>::type ht_6;						// short, double, ushort, char, const char*, uint
	std::cout << "erase<3>: "; print<ht_6>(std::cout);
	std::cout << "size: " << size<ht_6>::value << std::endl;
	std::cout << "size: " << size<int, char, bool>::value << std::endl;
	std::cout << "empty: " << empty<int>::value << std::endl;
	std::cout << "empty: " << empty<>::value << std::endl;
	typedef pop_back<ht_6>::type ht_7;
	std::cout << "pop_back: "; print<ht_7>(std::cout);
	typedef pop_front<ht_7>::type ht_8;
	std::cout << "pop_front: "; print<ht_8>(std::cout);
	std::cout << "front: "; print<front<ht_8>::type>(std::cout);
	std::cout << "back: "; print<back<ht_8>::type>(std::cout);

	std::cout << typeid(get<at<1, holder<int, char>>::type>::type).name() << std::endl;
	std::cout << typeid(safe_get<void, holder<>>::type).name() << std::endl;

	std::cout << std::endl;

	typedef splice<1, 2, ht_6>::type ht;					// double, ushort
	print<ht>(std::cout);

	std::cout << std::endl;

	typedef split<3, ht_6> hts;								// short, double, ushort  |  char, const char*, uint
	print<hts::head_type>(std::cout);
	print<hts::tail_type>(std::cout);

	std::cout << std::endl;

	typedef holder<_int<1>, _int<2>, _int<3>> hs;
	typedef transform<add_const<10>, hs>::type h1;
	typedef transform<sqr, hs>::type h2;

	print<h1>(std::cout);
	print<h2>(std::cout);

	std::cout << std::endl;

	typedef make_holder<void(int, const char*, const char*)>::type hf;
	typedef transform<type_replacer, hf>::type hf1;
	typedef transform<type_decay, hf>::type hf2;

	print<hf1>(std::cout);
	print<hf2>(std::cout);

	return 0;
}

