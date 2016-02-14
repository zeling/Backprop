cmake_minimum_required(VERSION 3.3)
project(Backprop)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/math/var.hpp src/math/propagatable.hpp src/memory/stackAlloc.cxx src/memory/stackAlloc.hpp src/math/var.cxx)
add_executable(Backprop ${SOURCE_FILES})