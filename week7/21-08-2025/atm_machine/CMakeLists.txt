cmake_minimum_required(VERSION 3.10)
project(ATMMachineTest LANGUAGES CXX)

find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/inc)

add_executable(RunAllTests 
    atmMachine.cpp
    test.cpp
)

target_link_libraries(RunAllTests
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
)

enable_testing()

add_test(NAME RunAllTests COMMAND RunAllTests)
