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
set(ecma_runtime_SOURCES
    scope.cpp

    types/env.cpp
    types/env_entry.cpp
)

add_library(ecma_runtime ${ecma_runtime_SOURCES})
target_link_libraries(ecma_runtime
    ${LLVM_LIBRARIES_ALL}
    ${LLVM_LDFLAGS}
)

# Variables
set(ecma_runtime_DEFINITIONS
    ${LLVM_CPPFLAGS}
PARENT_SCOPE)

set(ecma_runtime_INCLUDE_DIRS
    ${LLVM_INCLUDE_DIR}
PARENT_SCOPE)

set(ecma_runtime_LIB_DIRS
    ${LLVM_LIB_DIR}
PARENT_SCOPE)

set(ecma_runtime_LIBRARIES
    ecma_runtime
    ${LLVM_LIBRARIES_ALL}
    ${LLVM_LDFLAGS}
PARENT_SCOPE)
