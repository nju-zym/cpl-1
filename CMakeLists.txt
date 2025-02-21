cmake_minimum_required(VERSION 3.28)
project(cpl_1)

set(CMAKE_C_STANDARD 17)

add_subdirectory(homework)
add_subdirectory(luogu)
add_subdirectory(personal)
add_executable(test test.c)
add_subdirectory(final-test)
add_executable(cardboard cardboard.c)
add_executable(2024-maths-final 2024-maths-final.c)