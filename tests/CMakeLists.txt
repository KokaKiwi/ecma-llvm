cmake_minimum_required(VERSION 2.8)

find_package(LLVM REQUIRED)
add_definitions(${LLVM_CPPFLAGS})
link_directories(${LLVM_LIB_DIR})
include_directories(${LLVM_INCLUDE_DIR})

find_package(CxxTest)
if (CXXTEST_FOUND)
    macro (ecma_add_tests)
        foreach (test ${ARGN})
            set(TEST_NAME test_${test})
            list(APPEND ecma_TESTS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_NAME}.h)
        endforeach (test)

        cxxtest_add_test(ecma_tests ecma_tests.cpp ${ecma_TESTS_SOURCES})
        target_link_libraries(ecma_tests
            EcmaParser
            EcmaCompiler
            ${LLVM_LIBRARIES_ALL}
            ${LLVM_LDFLAGS}
        )
    endmacro (ecma_add_tests)

    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    set(ecma_TESTS
        basic
    )

    ecma_add_tests(${ecma_TESTS})

    set(ECMA_TESTS ON PARENT_SCOPE)
else (CXXTEST_FOUND)
    set(ECMA_TESTS OFF PARENT_SCOPE)
endif (CXXTEST_FOUND)
