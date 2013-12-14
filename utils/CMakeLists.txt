cmake_minimum_required(VERSION 2.8)

# Build library
set(ecma_utils_SOURCES
    messages.cpp
)

add_library(ecma_utils STATIC ${ecma_utils_SOURCES})

# Variables
set(ecma_utils_LIBRARIES
    ecma_utils
PARENT_SCOPE)
