# Find Ragel - Find the Ragel executable

find_program(RAGEL
    NAMES "${RAGEL_PATH}/bin/ragel" "ragel"
    DOC "ragel executable")

if (RAGEL)
    set(RAGEL_FOUND TRUE)

    execute_process(
        COMMAND ${RAGEL} --version
        OUTPUT_VARIABLE RAGEL_VERSION_FULL
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    string(REGEX REPLACE
        ".*version ([^ ]+).*"
        "\\1"
        RAGEL_VERSION ${RAGEL_VERSION_FULL}
    )

    function(ragel_generate target target_file source)
        get_filename_component(fext "${target_file}" EXT)
        get_filename_component(fpath "${target_file}" PATH)

        if("${fext}" STREQUAL ".cpp" OR "${fext}" STREQUAL ".c")
            set(RAGEL_DST_FLAG "-C")
        endif("${fext}" STREQUAL ".cpp" OR "${fext}" STREQUAL ".c")

        if(NOT EXISTS "${fpath}/")
            set(RAGEL_MKDIR COMMAND ${CMAKE_COMMAND} -E make_directory "${fpath}")
        endif(NOT EXISTS "${fpath}/")

        add_custom_command(
            OUTPUT "${target_file}"
            ${RAGEL_MKDIR}
            COMMAND ${RAGEL}
                ARGS    ${RAGEL_DST_FLAG} ${RAGEL_FLAGS}
                        -o "${target_file}"
                        "${CMAKE_CURRENT_SOURCE_DIR}/${source}"
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${source}"
            COMMENT "Generating ${target}"
        )
    endfunction(ragel_generate)

endif(RAGEL)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    Ragel
    REQUIRED_VARS RAGEL
    VERSION_VAR RAGEL_VERSION
)
