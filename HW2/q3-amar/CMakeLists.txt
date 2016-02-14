cmake_minimum_required(VERSION 3.3)
project(q3_amar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(q3_amar ${SOURCE_FILES})