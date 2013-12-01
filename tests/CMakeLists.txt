cmake_minimum_required(VERSION 2.8)

find_package(LLVM REQUIRED)
add_definitions(${LLVM_CPPFLAGS})
link_directories(${LLVM_LIB_DIR})
include_directories(${LLVM_INCLUDE_DIR})

find_package(CxxTest)
if (CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    file(GLOB_RECURSE ecma_tests_SOURCES *.h)
    cxxtest_add_test(ecma_tests ecma_tests.cpp ${ecma_tests_SOURCES})
    target_link_libraries(ecma_tests
        EcmaParser
        EcmaCompiler
        ${LLVM_LIBRARIES_ALL}
        ${LLVM_LDFLAGS}
    )
    set(ECMA_TESTS ON PARENT_SCOPE)
else (CXXTEST_FOUND)
    set(ECMA_TESTS OFF PARENT_SCOPE)
endif (CXXTEST_FOUND)
