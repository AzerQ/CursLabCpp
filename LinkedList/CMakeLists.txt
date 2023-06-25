cmake_minimum_required(VERSION 3.25)
project(LinkedList)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

add_executable(LinkedList
        src/include/DoublyLinkedList.h
        src/include/Node.h
        src/main.cpp)
