cmake_minimum_required(VERSION 2.8)

project(project9)

# use C++11
# setting warning compiler flags
add_compile_options(-Wall -std=c++14)

add_executable(Level9 Level6_Section9_Exercise1.cpp  EmptyState.cpp  FullState.cpp  NotFullNotEmptyState.cpp 
   Stack.cpp Singleton.cpp StackState.cpp )
