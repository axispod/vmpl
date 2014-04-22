#pragma once

#include <iostream>
#include <type_traits>
#include "../src/holder.h"
#include "../src/at.h"

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
			stream << "}" << std::endl;
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
}

template<typename ...Args>
void print(std::ostream& stream)
{
	std::cout << "{";
	print_helper<Args...>::print(stream);
}