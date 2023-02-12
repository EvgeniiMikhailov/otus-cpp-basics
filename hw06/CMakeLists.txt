cmake_minimum_required(VERSION 3.21)
project(hw06)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(target hw06)

add_executable(${target} main.cpp mylist.h myvector.h)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${target} PRIVATE
            -g
            -Wall
            -Wextra
            -Werror
            -pedantic
            )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${target} PRIVATE
            /W4
            /WX
            )
endif()

enable_testing()

add_executable(
        hw_test
        vector_test.cc
)
target_link_libraries(
        hw_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hw_test)

add_test(hw_test hw_test)
