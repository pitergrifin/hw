cmake_minimum_required(VERSION 3.14)
project(MyTests)

set(CMAKE_CXX_STANDARD 17)

find_package(Catch2 3 REQUIRED)

add_subdirectory(hw1)
