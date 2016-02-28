cmake_minimum_required(VERSION 3.3)
project(Theft)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp lib.h lib.cpp)
add_executable(Theft ${SOURCE_FILES})