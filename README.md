# make_overloaded_function: A single-file header-only library that lets you easily combine lambdas for C++11 and later

[![Language](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17%2F20-blue)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization) [![License](https://img.shields.io/badge/license-BSL-blue.svg)](https://opensource.org/licenses/BSL-1.0) [![Latest download](https://img.shields.io/badge/latest-download-blue.svg)](https://raw.githubusercontent.com/ligfx/make_overloaded_function/master/include/make_overloaded_function.hpp)

A single-file header-only library that lets you easily combine lambdas for use with std::visit and polyfills. The [documentation for std::visit](https://en.cppreference.com/w/cpp/utility/variant/visit) gives an example type and function *overloaded*, but it has issues prior to C++17. This library works all the way back to C++11 (when lambdas were introduced), making it a great fit for std::variant polyfill libraries like [variant-lite](https://github.com/martinmoene/variant-lite).

## Example usage

```c++

#include <make_overloaded_function.hpp>
#include <nonstd/variant.hpp>
#include <vector>

// the variant to visit
using var_t = nonstd::variant<int, long, double, std::string>;

std::vector<var_t> vec = {var_t(10), var_t(15l), var_t(1.5), var_t("hello")};

for (auto& v: vec) {
    nonstd::visit(make_overloaded_function(
        [&](int arg) { out << arg << ' '; },
        [&](long arg) { out << arg << "l "; },
        [&](double arg) { out << std::fixed << arg << ' '; },
        [&](const std::string& arg) { out << arg << ' '; }
    ), v);
}
```
Output:
```
10 15l 1.500000 hello
```

## License

*make_overloaded_function* is distributed under the [Boost Software License](https://github.com/ligfx/make_overloaded_function/blob/master/LICENSE.txt).

## Dependencies

*make_overloaded_function* has no dependencies other than a C++11-compliant compiler.

[variant-lite](https://github.com/martinmoene/variant-lite) is recommended as a variant implementation for C++11 and C++14.

## API

template <typename ...Fs><br>
overloaded<Fs...> **make_overloaded_function**(Fs... args);
