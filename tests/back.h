#pragma once

#include "testf.h"
#include "../src/back.h"

#include <iostream>

namespace vmpl_tests
{
	void test_back()
	{
		std::cout << "== at tests ==" << std::endl;

		typedef vmpl::holder<>				empty_holder;
		typedef vmpl::holder<int>			one_type_holder;
		typedef vmpl::holder<char, int>		two_types_holder;

		std::cout << "empty_holder - "; tests::print_list<empty_holder>(std::cout);
		std::cout << "one_type_holder - "; tests::print_list<one_type_holder>(std::cout);
		std::cout << "two_types_holder - "; tests::print_list<two_types_holder>(std::cout);

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::back<empty_holder>::type
		>(std::cout, "back<empty_holder>");

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::back<>::type
		>(std::cout, "back<>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::back<one_type_holder>::type
		>(std::cout, "back<one_type_holder>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::back<int>::type
		>(std::cout, "back<int>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::back<two_types_holder>::type
		>(std::cout, "back<two_types_holder>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::back<char, int>::type
		>(std::cout, "back<char, int>");
	}
}