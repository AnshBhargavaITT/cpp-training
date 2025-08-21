cmake_minimum_required(VERSION 3.10)
project(BankProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/inc)

file(GLOB_RECURSE BANKLIB_SOURCES "src/*.cpp")

add_library(BankLib ${BANKLIB_SOURCES})

find_package(GTest REQUIRED)

file(GLOB TEST_FILES tests/*.cpp)

add_executable(RunAllTests ${TEST_FILES})

target_link_libraries(RunAllTests
    BankingLib
    gtest
    gmock
    gtest_main
)

enable_testing()

add_test(NAME RunAllTests COMMAND BankTests)
