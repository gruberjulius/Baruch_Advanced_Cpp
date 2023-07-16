cmake_minimum_required(VERSION 2.8)

project(project8)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++14)

add_executable(Level Level6_Section8_Exercise1.cpp  Point.cpp)
