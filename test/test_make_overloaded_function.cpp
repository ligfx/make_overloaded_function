#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "nonstd/variant.hpp"

#include "make_overloaded_function.hpp"

using var_t = nonstd::variant<int, long, double, std::string>;

int main() {
  std::vector<var_t> vec = {var_t(10), var_t(15l), var_t(1.5), var_t("hello")};

  std::stringstream out;

  for (auto &v : vec) {
    nonstd::visit(make_overloaded_function(
                      [&](int arg) { out << arg << ' '; },
                      [&](long arg) { out << arg << "l "; },
                      [&](double arg) { out << std::fixed << arg << ' '; },
                      [&](const std::string &arg) { out << arg << ' '; }),
                  v);
  }

  std::cout << out.str() << std::endl;
  if (out.str() == "10 15l 1.500000 hello ") {
    std::cout << "SUCCESS" << std::endl;
    return 0;
  } else {
    std::cout << "FAILURE" << std::endl;
    return 1;
  }
}
