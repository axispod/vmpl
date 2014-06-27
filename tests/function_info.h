#pragma once

#include <vmpl/function_info.h>
#include <functional>

#include "testf.h"

namespace vmpl_tests
{
	namespace
	{
		double func1(int a, char b) 
		{
			return 0.0f;
		}

		struct foo
		{
			char func2(double, int)
			{
				return 'a';
			}
		};

		struct foo2
		{
			int operator()(float, char)
			{
				return 0;
			}
		};
	}

	void test_function_info()
	{
		std::cout << "== function_info tests ==" << std::endl;

		typedef vmpl::function_info<int(char, float)> function_t1;

		tests::assert_equal<
			int(char, float),
			typename function_t1::function_type
		>(std::cout, "function type of int(char, float)");

		tests::assert_equal<
			int(*)(char, float),
			typename function_t1::callable_type
		>(std::cout, "callable type of int(char, float)");

		tests::assert_equal<
			int,
			typename function_t1::return_type
		>(std::cout, "return type of int(char, float)");

		tests::assert_equal<
			vmpl::holder<char, float>,
			typename function_t1::arguments_type
		>(std::cout, "arguments types of int(char, float)");

		tests::assert_equal<
			void,
			typename function_t1::object_type
		>(std::cout, "object type of int(char, float)");


		typedef vmpl::function_info<decltype(func1)> function_t2;

		tests::assert_equal<
			double (int, char),
			typename function_t2::function_type
		>(std::cout, "function type of decltype(double (int, char) {})");

		tests::assert_equal<
			double(*)(int, char),
			typename function_t2::callable_type
		>(std::cout, "callable type of decltype(double (int, char) {})");

		tests::assert_equal<
			double,
			typename function_t2::return_type
		>(std::cout, "return type of decltype(double (int, char) {})");

		tests::assert_equal<
			vmpl::holder<int, char>,
			typename function_t2::arguments_type
		>(std::cout, "arguments types of decltype(double (int, char) {})");

		tests::assert_equal<
			void,
			typename function_t2::object_type
		>(std::cout, "object type of decltype(double func1(int a, char b) {} )");


		typedef vmpl::function_info<decltype(&foo::func2)> function_t3;

		tests::assert_equal<
			char (double, int),
			typename function_t3::function_type
		>(std::cout, "function type of decltype(struct foo{char (double, int) {}})");

		tests::assert_equal<
			char (foo::*)(double, int),
			typename function_t3::callable_type
		>(std::cout, "callable type of decltype(struct foo{char (double, int) {}})");

		tests::assert_equal<
			char,
			typename function_t3::return_type
		>(std::cout, "return type of decltype(struct foo{char (double, int) {}})");

		tests::assert_equal<
			vmpl::holder<double, int>,
			typename function_t3::arguments_type
		>(std::cout, "arguments types of decltype(struct foo{char (double, int) {}})");

		tests::assert_equal<
			foo,
			typename function_t3::object_type
		>(std::cout, "object type of decltype(struct foo{char (double, int) {}})");


		typedef std::function<char(int, float)> functor_type;
		typedef vmpl::function_info<functor_type> function_t4;

		tests::assert_equal<
			char(int, float),
			typename function_t4::function_type
		>(std::cout, "function type of std::function<char(int, float)>");

		typedef decltype (&functor_type::operator()) callable_type1;
		tests::assert_equal<
			callable_type1,
			typename function_t4::callable_type
		>(std::cout, "callable type of std::function<char(int, float)>");

		tests::assert_equal<
			char,
			typename function_t4::return_type
		>(std::cout, "return type of std::function<char(int, float)>");

		tests::assert_equal<
			vmpl::holder<int, float>,
			typename function_t4::arguments_type
		>(std::cout, "arguments types of std::function<char(int, float)>");

		tests::assert_equal<
			functor_type,
			typename function_t4::object_type
		>(std::cout, "object type of std::function<char(int, float)>");

		typedef vmpl::function_info<foo2> function_t5;

		tests::assert_equal<
			int(float, char),
			typename function_t5::function_type
		>(std::cout, "function type of struct foo2{int operator(float, char){}}");

		tests::assert_equal<
			int(foo2::*)(float, char),
			typename function_t5::callable_type
		>(std::cout, "callable type of foo2{int operator(float, char){}}");

		tests::assert_equal<
			int,
			typename function_t5::return_type
		>(std::cout, "return type of foo2{int operator(float, char){}}");

		tests::assert_equal<
			vmpl::holder<float, char>,
			typename function_t5::arguments_type
		>(std::cout, "arguments types of foo2{int operator(float, char){}}");

		tests::assert_equal<
			foo2,
			typename function_t5::object_type
		>(std::cout, "object type of foo2{int operator(float, char){}}");

		auto l = [](int, char){ };
		typedef vmpl::function_info<decltype(l)> function_t6;

		tests::assert_equal<
			void(int, char),
			typename function_t6::function_type
		>(std::cout, "function type of [](int, char)->void{}");

		typedef decltype(l) lmb1;
		tests::assert_equal<
			decltype(&lmb1::operator()),
			typename function_t6::callable_type
		>(std::cout, "callable type of [](int, char)->void{}");

		tests::assert_equal<
			void,
			typename function_t6::return_type
		>(std::cout, "return type of [](int, char)->void{}");

		tests::assert_equal<
			vmpl::holder<int, char>,
			typename function_t6::arguments_type
		>(std::cout, "arguments types of [](int, char)->void{}");

		tests::assert_equal<
			lmb1,
			typename function_t6::object_type
		>(std::cout, "object type of [](int, char)->void{}");

		int a = 5;
		auto l2 = [&](int, char, int)->float{ return 0.0f; };
		typedef vmpl::function_info<decltype(l2)> function_t7;

		tests::assert_equal<
			float(int, char, int),
			typename function_t7::function_type
		>(std::cout, "function type of [&](int, char, int)->float{}");

		typedef decltype(l2) lmb2;
		tests::assert_equal<
			decltype(&lmb2::operator()),
			typename function_t7::callable_type
		>(std::cout, "callable type of [&](int, char, int)->float{}");

		tests::assert_equal<
			float,
			typename function_t7::return_type
		>(std::cout, "return type of [&](int, char, int)->float{}");

		tests::assert_equal<
			vmpl::holder<int, char, int>,
			typename function_t7::arguments_type
		>(std::cout, "arguments types of [&](int, char, int)->float{}");

		tests::assert_equal<
			lmb2,
			typename function_t7::object_type
		>(std::cout, "object type of [&](int, char, int)->float{}");
	}
}