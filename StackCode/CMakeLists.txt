cmake_minimum_required(VERSION 3.25)
project(StackCode)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

add_executable(StackCode
        src/include/postfix.h
        src/include/stack.h
        src/main.cpp
        src/postfix.cpp)
