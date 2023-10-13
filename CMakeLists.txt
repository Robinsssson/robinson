cmake_minimum_required(VERSION 3.26)
project(matrix)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrix test.cpp matrix.cpp matrix.h)

