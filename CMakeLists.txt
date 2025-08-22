cmake_minimum_required(VERSION 3.10)
project(BankLibTest LANGUAGES CXX)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/inc/UI  
    ${PROJECT_SOURCE_DIR}/mock
)

file(GLOB_RECURSE BANKLIB_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

list(FILTER BANKLIB_SOURCES EXCLUDE REGEX ".*/main\\.cpp$")

add_library(BankLib STATIC ${BANKLIB_SOURCES})

find_package(GTest REQUIRED)

file(GLOB TEST_FILES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

add_executable(RunAllTests ${TEST_FILES})

target_link_libraries(RunAllTests
    BankLib
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
)

file(GLOB_RECURSE APP_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(BankApp ${APP_SOURCES})

target_link_libraries(BankApp BankLib)

enable_testing()

add_test(NAME RunAllTests COMMAND RunAllTests)
