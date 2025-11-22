cmake_minimum_required(VERSION 3.10)
project(PaymentGatewayTest LANGUAGES CXX)

find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/inc)

find_package(GTest REQUIRED)

file(GLOB TEST_FILES tests/*.cpp)

add_executable(RunAllTests ${TEST_FILES}
src/userService.cpp)

target_link_libraries(RunAllTests
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
)

enable_testing()

add_test(NAME RunAllTests COMMAND RunAllTests)
