cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE EcmaRuntime_SOURCES *.cpp)

add_library(EcmaRuntime STATIC ${EcmaRuntime_SOURCES})
