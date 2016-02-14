cmake_minimum_required(VERSION 3.3)
project(q2_parish)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(q2_parish ${SOURCE_FILES})