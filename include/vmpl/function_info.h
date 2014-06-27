#pragma once

#include <type_traits>
#include "holder.h"

namespace vmpl
{
    template<typename _Tr, typename _Ta>
    struct function_description
    {
        typedef _Tr return_type;
        typedef _Ta arguments_type;
    };

    template<typename _Tf, typename _Tr, bool _C, typename ..._Ta>
    struct make_function_type
    {
	private:
		typedef _Tr(_Tf::*const_callable_type)(_Ta...) const;
		typedef _Tr(_Tf::*nonconst_callable_type)(_Ta...);

	public:
        typedef _Tr(function_type)(_Ta...);
		typedef typename std::conditional<_C, const_callable_type, nonconst_callable_type>::type callable_type;
    };

    template<class _Tr, class _Tf, class ..._Ta>
    function_description<_Tr, holder<_Ta...>> type_detection_helper(_Tr (_Tf::*)(_Ta...) const);

    template<class _Tr, class _Tf, class ..._Ta>
    function_description<_Tr, holder<_Ta...>> type_detection_helper(_Tr (_Tf::*)(_Ta...));

    template<class _Tr, class _Tf, class ..._Ta>
    make_function_type<_Tf, _Tr, true, _Ta...> type_function_helper(_Tr (_Tf::*)(_Ta...) const);

    template<class _Tr, class _Tf, class ..._Ta>
	make_function_type<_Tf, _Tr, false, _Ta...> type_function_helper(_Tr(_Tf::*)(_Ta...));

	template<typename _T>
	struct function_info
	{
	private:
		typedef decltype(type_detection_helper(&_T::operator())) td_type;
		typedef decltype(type_function_helper(&_T::operator())) f_type;

	public:
		typedef typename td_type::return_type return_type;
		typedef typename td_type::arguments_type arguments_type;
		typedef typename f_type::function_type function_type;
		typedef typename f_type::callable_type callable_type;
		typedef _T object_type;
	};

	template<typename _Tr, typename ... _Ta>
	struct function_info < _Tr(_Ta...) >
	{
		typedef _Tr return_type;
		typedef holder<_Ta...> arguments_type;
		typedef _Tr(function_type)(_Ta...);
		typedef _Tr(*callable_type)(_Ta...);
		typedef void object_type;
	};

	template<typename _Tr, typename ... _Ta>
	struct function_info < _Tr(*)(_Ta...) >
	{
		typedef _Tr return_type;
		typedef holder<_Ta...> arguments_type;
		typedef _Tr(function_type)(_Ta...);
		typedef _Tr(*callable_type)(_Ta...);
		typedef void object_type;
	};

	template<typename _To, typename _Tr, typename ... _Ta>
	struct function_info < _Tr(_To::*)(_Ta...) >
	{
		typedef _Tr return_type;
		typedef holder<_Ta...> arguments_type;
		typedef _Tr(function_type)(_Ta...);
		typedef _Tr(_To::*callable_type)(_Ta...);
		typedef _To object_type;
	};
}