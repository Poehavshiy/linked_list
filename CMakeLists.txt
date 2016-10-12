cmake_minimum_required(VERSION 3.5)
project(TZtest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Person.cpp Person.h
        Date.cpp Date.h
        Node.cpp Node.h
        Linked_list.cpp Linked_list.h)
add_executable(TZtest ${SOURCE_FILES})