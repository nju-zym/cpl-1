cmake_minimum_required(VERSION 3.28)
project(cpl_1 C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(homework)
add_subdirectory(luogu)
add_subdirectory(personal)
add_executable(test test.c)