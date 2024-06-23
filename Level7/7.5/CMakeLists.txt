cmake_minimum_required(VERSION 2.8)

project(project5)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++17)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(Level75 Level7_Section5_Exercise1.cpp Circle.cpp Line.cpp  Point.cpp  )
