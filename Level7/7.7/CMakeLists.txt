cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE(Boost REQUIRED)

project(project1)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++14)

add_executable(Level1 Level7_Section7_Exercise1.cpp) 
