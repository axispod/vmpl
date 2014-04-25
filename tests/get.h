#pragma once

#include "testf.h"
#include "../src/get.h"

namespace vmpl_tests
{
	void test_get()
	{
		std::cout << "== get tests ==" << std::endl;

		typedef vmpl::holder<>				empty_holder;
		typedef vmpl::holder<int>			one_type_holder;
		typedef vmpl::holder<char, int>		two_types_holder;

		std::cout << "empty_holder - "; tests::print_list<empty_holder>(std::cout);
		std::cout << "one_type_holder - "; tests::print_list<one_type_holder>(std::cout);
		std::cout << "two_types_holder - "; tests::print_list<two_types_holder>(std::cout);

		// Get from empty holder, compiler error
		// tests::assert_equal<
		//	vmpl::holder<>,
		//	vmpl::get<empty_holder>::type
		// >(std::cout, "get<empty_holder>");

		// tests::assert_equal<
		//	vmpl::holder<>,
		//	vmpl::get<>::type
		// >(std::cout, "get<>");

		tests::assert_equal<
			int,
			vmpl::get<one_type_holder>::type
		>(std::cout, "get<one_type_holder>");

		tests::assert_equal<
			int,
			vmpl::get<int>::type
		>(std::cout, "get<int>");

		tests::assert_equal<
			char,
			vmpl::get<two_types_holder>::type
		>(std::cout, "get<two_types_holder>");

		tests::assert_equal<
			char,
			vmpl::get<char, int>::type
		>(std::cout, "get<char, int>");

		// safe_get
		tests::assert_equal<
			void,
			vmpl::safe_get<void, empty_holder>::type
		>(std::cout, "safe_get<void, empty_holder>");

		tests::assert_equal<
			void,
			vmpl::safe_get<void>::type
		>(std::cout, "safe_get<void>");

		tests::assert_equal<
			int,
			vmpl::safe_get<void, one_type_holder>::type
		>(std::cout, "safe_get<void, one_type_holder>");

		tests::assert_equal<
			int,
			vmpl::safe_get<void, int>::type
		>(std::cout, "safe_get<void, int>");

		tests::assert_equal<
			char,
			vmpl::safe_get<void, two_types_holder>::type
		>(std::cout, "safe_get<void, two_types_holder>");

		tests::assert_equal<
			char,
			vmpl::safe_get<void, char, int>::type
		>(std::cout, "safe_get<void, char, int>");
	}
}