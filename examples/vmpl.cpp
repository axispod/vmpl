// vmpl.cpp : Defines the entry point for the console application.
//

#include "../vsspecific/stdafx.h"

#include "../tests/holder.h"
#include "../tests/at.h"
#include "../tests/get.h"
#include "../tests/back.h"
#include "../tests/front.h"
#include "../tests/function_info.h"

#include <vmpl/map.h>
#include <vmpl/numrics.h>

#include <iostream>
#include <typeinfo>
#include <type_traits>

using namespace vmpl;

/*template<std::size_t add>
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
};*/

template<typename T>
void print_map_result()
{
	std::cout << "found by index: " << T::first_type::value << " value: " << T::second_type::value << std::endl;
}

template<>
void print_map_result<void>()
{
	std::cout << "not found" << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*typedef make_holder<holder<int, const char*>, holder<>, char, holder<float, double>>::type ht_;					// int, const char*, char, float, double
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
	print<hf2>(std::cout);*/

	//vmpl_tests::test_holder();
	//vmpl_tests::test_get();
	//vmpl_tests::test_at();
	//vmpl_tests::test_back();
	//vmpl_tests::test_front();
	vmpl_tests::test_function_info();

	/*typedef holder<
		pair<int_<0>, int_<1>>,
		pair<int_<1>, int_<2>>,
		pair<int_<2>, int_<4>>,
		pair<int_<3>, int_<8>>,
		pair<int_<4>, int_<16>>,
		pair<int_<5>, int_<32>>,
		pair<int_<6>, int_<64>>,
		pair<int_<7>, int_<128>>
	> map_type;

	typedef map_find<int_<4>, map_type>::type type;

	print_map_result<type>();
	std::cout << "index: " << map_index<int_<5>, map_type>::value << std::endl;

	typedef map_insert<pair<int_<44>, int_<1616>>, int_<0>, map_type>::type map_type2;
	typedef map_erase<int_<4>, map_type2>::type map_type3;
	typedef map_replace<int_<5>, pair<int_<8>, int_<256>>, map_type3>::type map_type4;

	tests::print_list<map_type4>(std::cout);*/

	return 0;
}

