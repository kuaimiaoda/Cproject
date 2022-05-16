cmake_minimum_required(VERSION 3.22)
project(calendar C)

set(CMAKE_C_STANDARD 99)

add_executable(calendar main.c time.h)
