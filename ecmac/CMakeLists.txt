cmake_minimum_required(VERSION 2.8)

find_package(LLVM REQUIRED)
add_definitions(${LLVM_CPPFLAGS})
link_libraries(${LLVM_LIBRARIES_ALL} ${LLVM_LDFLAGS})
link_directories(${LLVM_LIB_DIR})
include_directories(${LLVM_INCLUDE_DIR})

set(ecmac_SOURCES
    main.cpp)

add_executable(ecmac ${ecmac_SOURCES})
target_link_libraries(ecmac EcmaParser EcmaCompiler ${LLVM_LIBRARIES_ALL})
