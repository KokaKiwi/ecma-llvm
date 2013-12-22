cmake_minimum_required(VERSION 2.8)

# Paths
set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Build library
set(ecma_frontend_SOURCES
    frontend/args.cpp

    frontend/input/phase.cpp

    frontend/parse/phase.cpp
)

add_library(ecma_frontend ${ecma_frontend_SOURCES})
target_link_libraries(ecma_frontend
    ecma_parser
)

# Variables
set(ecma_frontend_INCLUDE_DIRS

PARENT_SCOPE)

set(ecma_frontend_LIBRARIES
    ecma_frontend
PARENT_SCOPE)
