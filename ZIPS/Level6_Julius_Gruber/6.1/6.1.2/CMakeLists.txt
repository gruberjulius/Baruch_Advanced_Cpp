cmake_minimum_required(VERSION 2.8)

project(project12)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++17)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(Level12 Level6_Section1_Exercise2.cpp Circle.cpp Line.cpp  Point.cpp  )
