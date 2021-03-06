// Copyright (C) 2013, Ennio Barbaro.
//
// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://sbabbi.github.io/tinympl for documentation.
//
// You are welcome to contact the author at:
//  enniobarbaro@gmail.com
//

#ifndef TINYMPL_ALL_OF_HPP
#define TINYMPL_ALL_OF_HPP

#include <tinympl/variadic/all_of.hpp>
#include <tinympl/as_sequence.hpp>
#include <tinympl/sequence.hpp>

namespace tinympl {

/**
 * \ingroup SeqNonModAlgs
 * \class all_of
 * \brief Determines whether every element in the sequence satisfies the given
predicate
 * \param Sequence the input sequence
 * \param F the predicate, `F<T>::type::value` must be convertible to `bool`
 * \return `all_of<...>::type` is a `std::integral_constant<bool,v>` where `v`
is true iff all the elements in the sequence satisfy the predicate `F`
 * \sa variadic::all_of
 */
template< class Sequence, template<class ...> class F>
struct all_of : all_of<as_sequence_t<Sequence>, F> {};

template< template<class ...> class F, class ... Args>
struct all_of<sequence<Args...>, F > : variadic::all_of<F, Args...> {};

} // namespace tinympl

#endif // TINYMPL_ALL_OF_HPP
