cmake_minimum_required(VERSION 3.6)
project(first)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES list.cpp list.h main.cpp)
add_executable(first ${SOURCE_FILES})