cmake_minimum_required(VERSION 2.8)

project(ecma-llvm)
set(PROJECT_VERSION "0.1.0")

set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BUILD_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BUILD_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BUILD_DIR}/lib")

set(OFLAGS "-ggdb3")
# set(OFLAGS "-O4 -march=native -msse -msse2 -msse3 -mmmx -m3dnow")

set(CMAKE_C_FLAGS "-std=c99 ${OFLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++0x -Wno-deprecated-writable-strings ${OFLAGS}")

include_directories(include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

add_subdirectory(parser)
add_subdirectory(runtime)
add_subdirectory(compiler)
add_subdirectory(ecmac)

add_subdirectory(tests)

find_package(LLVM REQUIRED)
string(REPLACE "." "" LLVM_VERSION_NUMBER ${LLVM_VERSION})
configure_file(include/config.cmake.h include/config.h @ONLY)

if (ECMA_TESTS)
    add_custom_target(run_tests
        COMMAND
            bin/ecma_tests
        DEPENDS
            ecma_tests
    )
endif (ECMA_TESTS)
