cmake_minimum_required(VERSION 2.8)
project(ecma-llvm)
set(PROJECT_VERSION "0.1.0")

# Paths
set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BUILD_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BUILD_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BUILD_DIR}/lib")

# Build type
if (NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Debug")
endif (NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")

# Compiler
option(USE_CLANG "Use clang for compilation." ON)

if (USE_CLANG)
    find_program(CLANG_EXECUTABLE
        clang
    )
    find_program(CLANGXX_EXECUTABLE
        clang++
    )

    if (NOT CLANG_EXECUTABLE OR NOT CLANGXX_EXECUTABLE)
        set(USE_CLANG OFF)
    endif (NOT CLANG_EXECUTABLE OR NOT CLANGXX_EXECUTABLE)
endif (USE_CLANG)

if (USE_CLANG)
    set(CMAKE_C_COMPILER ${CLANG_EXECUTABLE})
    set(CMAKE_CXX_COMPILER ${CLANGXX_EXECUTABLE})
else (USE_CLANG)
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_CXX_COMPILER g++)
endif (USE_CLANG)

# Flags
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(COMPILE_FLAGS "-ggdb3")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(COMPILE_FLAGS "-march=native -O4")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

if (USE_CLANG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else (USE_CLANG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
endif (USE_CLANG)

# Dependencies
## LLVM
find_package(LLVM REQUIRED)
string(REPLACE "." "" LLVM_VERSION_NUMBER ${LLVM_VERSION})
configure_file(include/config.cmake.h include/config.h @ONLY)

## Paths
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_BUILD_DIR}/include)

## Parser
add_subdirectory(parser)
include_directories(${ecma_parser_INCLUDE_DIRS})
list(APPEND ecma_LIBRARIES ${ecma_parser_LIBRARIES})

## Utils
add_subdirectory(utils)
list(APPEND ecma_LIBRARIES ${ecma_utils_LIBRARIES})

# Binaries
## Parser
add_executable(ecmap parser/main.cpp)
target_link_libraries(ecmap ${ecma_LIBRARIES})

# Special rules
## Tests
find_package(PythonInterp)
if (PYTHONINTERP_FOUND)
    add_custom_target(test
        COMMAND
            ${PYTHON_EXECUTABLE}
            ${PROJECT_SOURCE_DIR}/tests/runner.py
            --bin-dir=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        DEPENDS
            ecmap
        WORKING_DIRECTORY
            ${PROJECT_SOURCE_DIR}/tests
    )
endif (PYTHONINTERP_FOUND)
