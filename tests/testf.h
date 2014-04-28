#pragma once

#include <vmpl/holder.h>

#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <string>

namespace tests
{
	namespace
	{
		template<typename T>
		struct print_type
		{
			static void print(std::ostream& stream)
			{
				stream << typeid(T).name();
			}
		};

		template<>
		struct print_type<unsigned int>
		{
			static void print(std::ostream& stream)
			{
				stream << "uint";
			}
		};

		template<>
		struct print_type<unsigned short>
		{
			static void print(std::ostream& stream)
			{
				stream << "ushort";
			}
		};

		template<typename T, T N>
		struct print_type<std::integral_constant<T, N>>
		{
			static void print(std::ostream& stream)
			{
				print_type<T>::print(stream);
				stream << "(" << N << ")";
			}
		};

		template<typename ...Args>
		struct print_helper;

		template<typename Arg, typename ...Args>
		struct print_helper<Arg, Args...>
		{
			static void print(std::ostream& stream)
			{
				print_type<Arg>::print(stream);
				stream << ", ";
				print_helper<Args...>::print(stream);
			}
		};

		template<typename Arg>
		struct print_helper<Arg>
		{
			static void print(std::ostream& stream)
			{
				print_type<Arg>::print(stream);
				print_helper<>::print(stream);
			}
		};

		template<>
		struct print_helper<>
		{
			static void print(std::ostream& stream)
			{
				stream << ">" << std::endl;
			}
		};

		template<typename ...Args>
		struct print_helper<vmpl::holder<Args...>>
		{
			static void print(std::ostream& stream)
			{
				print_helper<Args...>::print(stream);
			}
		};

		template<typename ...Args>
		struct print_helper2
		{
			static void print(std::ostream& stream)
			{
				stream << "<";
				print_helper<Args...>::print(stream);
			}
		};

		template<typename ...Args>
		struct print_helper2<vmpl::holder<Args...>>
		{
			static void print(std::ostream& stream)
			{
				stream << "holder<";
				print_helper<Args...>::print(stream);
			}
		};
	}

	template<typename ...Args>
	void print_list(std::ostream& stream)
	{
		print_helper2<Args...>::print(stream);
	}

	template<typename T1, typename T2>
	void assert_equal(std::ostream& stream, const std::string& text)
	{
		typedef std::is_same<T1, T2> same;
		print_result<same>(stream);
		stream << " " << text << std::endl;
		if (same::value == false)
		{
			std::cout << "       first  - "; print_list<T1>(stream);
			std::cout << "       second - "; print_list<T2>(stream);
		}
	};

	template<typename T>
	void print_result(std::ostream& stream)
	{
		stream << (T::value ? "[ Ok ]" : "[Fail]");
	}
}
