#pragma once

#include <vmpl/front.h>
#include <iostream>

#include "testf.h"

namespace vmpl_tests
{
	void test_front()
	{
		std::cout << "== front tests ==" << std::endl;

		typedef vmpl::holder<>				empty_holder;
		typedef vmpl::holder<int>			one_type_holder;
		typedef vmpl::holder<char, int>		two_types_holder;

		std::cout << "empty_holder - "; tests::print_list<empty_holder>(std::cout);
		std::cout << "one_type_holder - "; tests::print_list<one_type_holder>(std::cout);
		std::cout << "two_types_holder - "; tests::print_list<two_types_holder>(std::cout);

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::front<empty_holder>::type
		>(std::cout, "front<empty_holder>");

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::front<>::type
		>(std::cout, "front<>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::front<one_type_holder>::type
		>(std::cout, "front<one_type_holder>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::front<int>::type
		>(std::cout, "front<int>");

		tests::assert_equal<
			vmpl::holder<char>,
			vmpl::front<two_types_holder>::type
		>(std::cout, "front<two_types_holder>");

		tests::assert_equal<
			vmpl::holder<char>,
			vmpl::front<char, int>::type
		>(std::cout, "front<char, int>");
	}
}