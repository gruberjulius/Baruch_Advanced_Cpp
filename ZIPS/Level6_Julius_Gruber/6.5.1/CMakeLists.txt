cmake_minimum_required(VERSION 2.8)

project(project5)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++11)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(Level5 Level6_Section5_Exercise1.cpp   ProtectedAccount.cpp          RealAccount.cpp)
