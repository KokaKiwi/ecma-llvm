# Find LLVM - Find the LLVM includes and library.
#
# This module defines
#   LLVM_FOUND, If false, do not try to use LLVM.
#   LLVM_VERSION, the LLVM version.
#   LLVM_CONFIG, the llvm-config executable.
#   LLVM_CPPFLAGS, the LLVM C++ preprocessor flags.
#   LLVM_CFLAGS, the LLVM C compiler flags.
#   LLVM_CXXFLAGS, the LLVM C++ compiler flags.
#   LLVM_LDFLAGS, the LLVM C++ linker flags.
#   LLVM_LIBRARIES_ALL, all the LLVM libraries.
#   LLVM_INCLUDE_DIR, the LLVM include directory.
#   LLVM_LIB_DIR, the LLVM libraries directory.
#   LLVM_BIN_DIR, the LLVM binaries directory.
#   LLVM_CMAKE_DIR, the LLVM cmake modules directory.

find_program(LLVM_CONFIG
    NAMES "${LLVM_PATH}/bin/llvm-config" "llvm-config"
    DOC "llvm-config executable")

if (LLVM_CONFIG)
    set (LLVM_FOUND TRUE)

    execute_process(
        COMMAND ${LLVM_CONFIG} --version
        OUTPUT_VARIABLE LLVM_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
        COMMAND ${LLVM_CONFIG} --cppflags
        OUTPUT_VARIABLE LLVM_CPPFLAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
        COMMAND ${LLVM_CONFIG} --cflags
        OUTPUT_VARIABLE LLVM_CFLAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
        COMMAND ${LLVM_CONFIG} --cxxflags
        OUTPUT_VARIABLE LLVM_CXXFLAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
        COMMAND ${LLVM_CONFIG} --ldflags
        OUTPUT_VARIABLE LLVM_LDFLAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
        COMMAND ${LLVM_CONFIG} --libs all
        OUTPUT_VARIABLE LLVM_LIBRARIES_ALL
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
        COMMAND ${LLVM_CONFIG} --includedir
        OUTPUT_VARIABLE LLVM_INCLUDE_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
        COMMAND ${LLVM_CONFIG} --libdir
        OUTPUT_VARIABLE LLVM_LIB_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
        COMMAND ${LLVM_CONFIG} --bindir
        OUTPUT_VARIABLE LLVM_BIN_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    set(LLVM_CMAKE_DIR /usr/share/llvm/cmake)
endif (LLVM_CONFIG)

# handle the QUIETLY and REQUIRED arguments and set LLVM_FOUND to TRUE if
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LLVM REQUIRED_VARS LLVM_CONFIG VERSION_VAR LLVM_VERSION)
