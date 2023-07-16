cmake_minimum_required(VERSION 2.8)

project(project6)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++17)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(Level6 Level6_Section6_Exercise2.cpp Circle.cpp Line.cpp  Point.cpp ShapeComposite.cpp  )
