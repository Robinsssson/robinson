cmake_minimum_required(VERSION 3.26)
project(robinson)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(matrix)
add_subdirectory(point)
add_executable(robinson main.cpp)
target_link_libraries(robinson lib_matrix lib_point)

