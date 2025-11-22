cmake_minimum_required(VERSION 3.10)
project(BankAccountTest LANGUAGES CXX)

enable_testing()

find_package(GTest REQUIRED)

add_executable(MyTests bankAccount.cpp)

target_link_libraries(MyTests GTest::gtest_main)

add_test(NAME RunBankAccountTests COMMAND MyTests)
