cmake_minimum_required(VERSION 3.3)
project(q1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sort.cpp sort.h lib.cpp lib.h heap.h heap.cpp)
add_executable(q1 ${SOURCE_FILES} sort.cpp sort.h lib.cpp lib.h heap.h)