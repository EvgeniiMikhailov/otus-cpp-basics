cmake_minimum_required(VERSION 3.21)
project(hw06)

set(CMAKE_CXX_STANDARD 17)
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
