cmake_minimum_required(VERSION 3.10)
project(MusicPlayerTest LANGUAGES CXX)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/mock 
)

file(GLOB_RECURSE MUSICPLAYER_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

list(FILTER MUSICPLAYER_SOURCES EXCLUDE REGEX ".*/main\\.cpp$")

add_library(MusicPlayerLib STATIC ${MUSICPLAYER_SOURCES})

find_package(SFML 2.5 COMPONENTS audio system REQUIRED)

target_link_libraries(MusicPlayerLib PRIVATE sfml-audio sfml-system)

find_package(GTest REQUIRED)

file(GLOB TEST_FILES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

add_executable(RunAllTests ${TEST_FILES})

target_link_libraries(RunAllTests
    MusicPlayerLib
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
    sfml-audio
    sfml-system
)

target_include_directories(RunAllTests PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/mock
)

enable_testing()
add_test(NAME RunAllTests COMMAND RunAllTests)

