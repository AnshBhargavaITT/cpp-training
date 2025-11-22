cmake_minimum_required(VERSION 3.10)
project(BankProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/inc)

add_library(BankLib
    src/accountHolder.cpp
    src/bank.cpp
)

add_executable(BankTests
    test/accountHolderTest.cpp
    test/bankTest.cpp
)

find_package(GTest REQUIRED)
target_link_libraries(BankTests BankLib GTest::GTest GTest::Main pthread)

enable_testing()
add_test(NAME RunAllTests COMMAND BankTests)
