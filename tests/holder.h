#pragma once

#include "testf.h"

#include "../src/holder.h"

#include <iostream>

namespace vmpl_tests
{
	void test_holder()
	{
		std::cout << "== make_holder tests ==" << std::endl;

		// Make holder algorithm
		tests::assert_equal<
			vmpl::holder<>,
			vmpl::make_holder<>::type
		>(std::cout, "vmpl::make_holder<>");

		tests::assert_equal<
			vmpl::holder<int, float>,
			vmpl::make_holder<int, float>::type
		>(std::cout, "make_holder<int, float>");

		tests::assert_equal<
			vmpl::holder<int, float>,
			vmpl::make_holder<vmpl::holder<int>, vmpl::holder<float>>::type
		>(std::cout, "make_holder<holder<int>, holder<float>>");

		tests::assert_equal<
			vmpl::holder<int, float>,
			vmpl::make_holder<vmpl::holder<int>, vmpl::holder<>, vmpl::holder<float>>::type
		>(std::cout, "make_holder<holder<int>, holder<>, holder<float>>");

		tests::assert_equal<
			vmpl::holder<int, float>,
			vmpl::make_holder<vmpl::holder<>, vmpl::holder<int>, vmpl::holder<>, vmpl::holder<float>, vmpl::holder<>>::type
		>(std::cout, "make_holder<holder<>, holder<int>, holder<>, holder<float>, holder<>>");

		tests::assert_equal<
			vmpl::holder<double, int, char, bool, float, double>,
			vmpl::make_holder<double, vmpl::holder<int, char>, vmpl::holder<bool, float>, double>::type
		>(std::cout, "make_holder<double, holder<int, char>, holder<bool, float>, double>");

		// From function signature
		tests::assert_equal<
			vmpl::holder<int, float>,
			vmpl::make_holder<void(int, float)>::type
		>(std::cout, "make_holder<void(int, float)>");

		tests::assert_equal<
			vmpl::holder<int, float>,
			vmpl::make_holder<void(*)(int, float)>::type
		>(std::cout, "make_holder<void(*)(int, float)>");
	}
}