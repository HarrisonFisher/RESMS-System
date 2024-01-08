cmake_minimum_required(VERSION 3.20)
project(RSEMS)

set(CMAKE_CXX_STANDARD 14)

add_executable(RSEMS src/main.cpp src/Agent.h src/Data.h src/Property.h src/List.h src/Node.h)
