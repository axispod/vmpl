vmpl
====

VMPL is a C++ template metaprogramming library using variadic templates. The library don't use rudimentary type-lists.

The library contains:
* Containers
** holder - container for list of variadic types
* Acessors
** at - getting the element by position
* Modifiers
** split - is a base algorithm for splitting the list into two different lists by position
** insert - split-based algorithm for inserting an element by position
** push_back and push_front - are aliases for make_holder for inserting element to back or front of holder
** replace - is an algorithm for changing one type to another one
** reverse - reversing of the list
** splice - split-based algorithm for extract sublist from the list
** transform - transforming type list using apllier algortihm
* Information
** size - getting size of the list
** empty - check existing of any elements in the list