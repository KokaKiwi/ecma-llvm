cmake_minimum_required(VERSION 2.8)

project(ecma-llvm)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "-std=c++11 -ggdb3")

include_directories(include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(parser)
add_subdirectory(compiler)
add_subdirectory(ecmac)
