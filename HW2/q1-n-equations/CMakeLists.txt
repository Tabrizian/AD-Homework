cmake_minimum_required(VERSION 3.3)
project(q1_n_equations)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp equation.cpp equation.h lib.cpp lib.h)
add_executable(q1_n_equations ${SOURCE_FILES})