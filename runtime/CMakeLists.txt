cmake_minimum_required (VERSION 2.6)
project (debugging)
include_directories(/usr/include/eigen3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
add_executable(ex1 ex1.cpp)
add_executable(ex2 ex2.cpp)

