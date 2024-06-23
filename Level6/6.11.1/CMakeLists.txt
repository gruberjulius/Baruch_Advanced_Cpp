cmake_minimum_required(VERSION 2.8)

project(project11)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++14)

add_executable(Level Level6_Section11_Exercise1.cpp DoubleFormat.cpp LongFormat.cpp Subject.cpp)
