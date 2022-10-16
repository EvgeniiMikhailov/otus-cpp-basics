cmake_minimum_required(VERSION 3.5)
project(03.homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(guess_the_number
        guess_the_number.cpp leader_board.cpp leader_board.h config.cpp config.h)
