cmake_minimum_required(VERSION 3.25)
project(CursLabCpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(StackCode/src)
include_directories(StackCode/src/include)

add_executable(CursLabCpp
        StackCode/src/include/postfix.h
        StackCode/src/include/stack.h
        StackCode/src/main.cpp
        StackCode/src/postfix.cpp)
