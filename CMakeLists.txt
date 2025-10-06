cmake_minimum_required(VERSION 3.14)
project(MyTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Catch2 3 REQUIRED)

add_library(common STATIC ${CMAKE_SOURCE_DIR}/common/Tree.cpp)

add_subdirectory(${CMAKE_SOURCE_DIR}/hw1)
add_subdirectory(${CMAKE_SOURCE_DIR}/hw2)
add_subdirectory(${CMAKE_SOURCE_DIR}/hw3)
