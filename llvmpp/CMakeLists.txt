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
# set(llvmpp_SOURCES

# )

# add_library(llvmpp ${llvmpp_SOURCES})
# target_link_libraries(llvmpp
#     ${LLVM_LIBRARIES_ALL}
#     pthread
#     dl
# )

# Variables
set(llvmpp_DEFINITIONS
    ${LLVM_CPPFLAGS}
PARENT_SCOPE)

set(llvmpp_INCLUDE_DIRS
    ${LLVM_INCLUDE_DIR}
PARENT_SCOPE)

set(llvmpp_LIB_DIRS
    ${LLVM_LIB_DIR}
PARENT_SCOPE)

set(llvmpp_LIBRARIES
    # llvmpp
    ${LLVM_LIBRARIES_ALL}
    pthread
    dl
PARENT_SCOPE)
