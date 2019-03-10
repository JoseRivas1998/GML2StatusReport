cmake_minimum_required(VERSION 3.6)
project(GML2StatusReport C)

set(CMAKE_C_STANDARD 11)

add_executable(GML2StatusReport src/main.c src/StatusTree.c)