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

# Flags
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(COMPILE_FLAGS "-ggdb3")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(COMPILE_FLAGS "-march=native -O4")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Dependencies
## Paths
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_BUILD_DIR}/include)

## Utils
add_subdirectory(utils)
list(APPEND ecma_LIBRARIES ${ecma_utils_LIBRARIES})

## Parser
add_subdirectory(parser)
include_directories(${ecma_parser_INCLUDE_DIRS})
list(APPEND ecma_LIBRARIES ${ecma_parser_LIBRARIES})

## LLVMPP
add_subdirectory(llvmpp)
add_definitions(${llvmpp_DEFINITIONS})
include_directories(${llvmpp_INCLUDE_DIRS})
link_directories(${llvmpp_LIB_DIRS})
list(APPEND ecma_LIBRARIES ${llvmpp_LIBRARIES})

## Runtime
add_subdirectory(runtime)
add_definitions(${ecma_runtime_DEFINITIONS})
include_directories(${ecma_runtime_INCLUDE_DIRS})
link_directories(${ecma_runtime_LIB_DIRS})
list(APPEND ecma_LIBRARIES ${ecma_runtime_LIBRARIES})

## Compiler
add_subdirectory(compiler)
add_definitions(${ecma_compiler_DEFINITIONS})
include_directories(${ecma_compiler_INCLUDE_DIRS})
link_directories(${ecma_compiler_LIB_DIRS})
list(APPEND ecma_LIBRARIES ${ecma_compiler_LIBRARIES})

## Frontend
add_subdirectory(frontend)
add_definitions(${ecma_frontend_DEFINITIONS})
include_directories(${ecma_frontend_INCLUDE_DIRS})
link_directories(${ecma_frontend_LIB_DIRS})
list(APPEND ecma_LIBRARIES ${ecma_frontend_LIBRARIES})

# Binaries
## Frontend
add_executable(ecmac frontend/main.cpp)
target_link_libraries(ecmac ${ecma_LIBRARIES})

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
            ecmac
        WORKING_DIRECTORY
            ${PROJECT_SOURCE_DIR}/tests
    )
endif (PYTHONINTERP_FOUND)

configure_file(include/config.cmake.h include/config.h @ONLY)
