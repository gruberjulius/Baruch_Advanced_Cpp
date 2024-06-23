cmake_minimum_required(VERSION 2.8)

project(project1)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++14)

add_executable(Level2 Level7_Section2_Exercise1.cpp Circle.cpp Line.cpp ConsoleShapeFactory.cpp  Point.cpp)
