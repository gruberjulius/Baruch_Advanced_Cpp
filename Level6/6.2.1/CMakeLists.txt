cmake_minimum_required(VERSION 2.8)

project(project2)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++17)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(Level2 Level6_Section2_Exercise1.cpp   Point.cpp  Singleton.cpp)
