cmake_minimum_required(VERSION 2.8)

project(project76)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++14)

add_executable(Level Level7_Section6_Exercise1.cpp DoubleFormat.cpp LongFormat.cpp Subject.cpp)
