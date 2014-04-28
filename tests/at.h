#pragma once

#include <vmpl/at.h>
#include <iostream>

#include "testf.h"

namespace vmpl_tests
{
	void test_at()
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
			vmpl::at<0, empty_holder>::type
		>(std::cout, "at<0, empty_holder>");

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::at<0>::type
		>(std::cout, "at<0>");

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::at<10, empty_holder>::type
		>(std::cout, "at<10, empty_holder>");

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::at<10>::type
		>(std::cout, "at<10>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::at<0, one_type_holder>::type
		>(std::cout, "at<0, one_type_holder>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::at<0, int>::type
		>(std::cout, "at<0, int>");

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::at<1, one_type_holder>::type
		>(std::cout, "at<1, one_type_holder>");

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::at<1, int>::type
		>(std::cout, "at<1, int>");

		tests::assert_equal<
			vmpl::holder<char>,
			vmpl::at<0, two_types_holder>::type
		>(std::cout, "at<0, two_types_holder>");

		tests::assert_equal<
			vmpl::holder<char>,
			vmpl::at<0, char, int>::type
		>(std::cout, "at<0, char, int>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::at<1, two_types_holder>::type
		>(std::cout, "at<1, two_types_holder>");

		tests::assert_equal<
			vmpl::holder<int>,
			vmpl::at<1, char, int>::type
		>(std::cout, "at<1, char, int>");

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::at<10, two_types_holder>::type
		>(std::cout, "at<10, two_types_holder>");

		tests::assert_equal<
			vmpl::holder<>,
			vmpl::at<10, char, int>::type
		>(std::cout, "at<10, char, int>");
	}
}