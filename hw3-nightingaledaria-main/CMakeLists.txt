cmake_minimum_required(VERSION 3.20)
project(laba3 C)

set(CMAKE_C_STANDARD 99)

MATH(EXPR stack_size "64 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
add_executable(laba3 main.c)
