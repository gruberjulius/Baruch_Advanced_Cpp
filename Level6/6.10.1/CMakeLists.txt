cmake_minimum_required(VERSION 2.8)

project(project7)


# setting warning compiler flags
add_compile_options(-Wall -std=c++14)

add_executable(Level Level6_Section10_Exercise1.cpp Circle.cpp Line.cpp   Point.cpp)
