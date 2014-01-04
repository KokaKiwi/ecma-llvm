cmake_minimum_required(VERSION 2.8)

# Paths
set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Dependencies
## LLVM
find_package(LLVM REQUIRED)
add_definitions(${LLVM_CPPFLAGS})
include_directories(${LLVM_INCLUDE_DIR})
link_directories(${LLVM_LIB_DIR})

# Build library
set(ecma_frontend_SOURCES
    frontend/args.cpp

    frontend/input/phase.cpp

    frontend/parse/phase.cpp

    frontend/compile/phase.cpp

    frontend/output/phase.cpp
)

add_library(ecma_frontend ${ecma_frontend_SOURCES})
target_link_libraries(ecma_frontend
    ecma_parser
    ecma_compiler
    ${LLVM_LIBRARIES_ALL}
    pthread
    dl
)

# Variables
set(ecma_frontend_DEFINITIONS
    ${LLVM_CPPFLAGS}
PARENT_SCOPE)

set(ecma_frontend_INCLUDE_DIRS
    ${LLVM_INCLUDE_DIR}
PARENT_SCOPE)

set(ecma_frontend_LIBRARIES
    ecma_frontend
    ${LLVM_LIBRARIES_ALL}
    pthread
    dl
PARENT_SCOPE)
