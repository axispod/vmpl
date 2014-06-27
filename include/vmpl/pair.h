#pragma once

namespace vmpl
{
	template<typename First, typename Second>
	struct pair
	{
		typedef First first_type;
		typedef Second second_type;
	};

	template<typename T>
	struct is_pair
	{
		static const bool value = false;
	};

	template<typename First, typename Second>
	struct is_pair < pair<First, Second> >
	{
		static const bool value = true;
	};
}