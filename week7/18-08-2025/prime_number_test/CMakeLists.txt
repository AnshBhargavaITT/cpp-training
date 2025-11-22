cmake_minimum_required(VERSION 3.10)
project(PrimeNumberTest LANGUAGES CXX)

enable_testing()

find_package(GTest REQUIRED)

add_executable(MyTests primeNumber.cpp)

target_link_libraries(MyTests GTest::gtest_main)

add_test(NAME RunFactorialTests COMMAND MyTests)
