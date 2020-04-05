cmake_minimum_required(VERSION 3.0)
project(make_overloaded_function)

add_library(make_overloaded_function INTERFACE)
target_include_directories(make_overloaded_function INTERFACE "include")
target_compile_features(make_overloaded_function INTERFACE cxx_variadic_templates)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_executable(test_make_overloaded_function test/test_make_overloaded_function)
    target_link_libraries(test_make_overloaded_function make_overloaded_function)
endif()
