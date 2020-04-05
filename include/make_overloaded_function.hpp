// Copyright 2020 by Michael Maltese
//
// https://github.com/ligfx/make_overloaded_function
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifndef MAKE_OVERLOADED_FUNCTION_HPP
#define MAKE_OVERLOADED_FUNCTION_HPP

template <class... Fs> struct overloaded;

template <class F1> struct overloaded<F1> : F1 {
  using F1::operator();
  overloaded(F1 f0) : F1(f0) {}
};

template <class F1, class... Fs>
struct overloaded<F1, Fs...> : F1, overloaded<Fs...> {
  using F1::operator();
  using overloaded<Fs...>::operator();
  overloaded(F1 f0, Fs... fs) : F1(f0), overloaded<Fs...>(fs...) {}
};

template <typename... Fs>
overloaded<Fs...> make_overloaded_function(Fs... fs) {
  return overloaded<Fs...>(fs...);
};

#endif
