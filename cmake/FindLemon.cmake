# Find Lemon - Find the Lemon executable

find_program(LEMON
    NAMES "${LEMON_PATH}/bin/lemon" "lemon"
    DOC "lemon executable"
)

if (LEMON)
    set(LEMON_FOUND TRUE)

    execute_process(
        COMMAND ${LEMON} -x
        OUTPUT_VARIABLE LEMON_VERSION_FULL
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    string(REGEX REPLACE
        ".*version ([0-9]+(\\.[0-9]+)*).*"
        "\\1"
        LEMON_VERSION ${LEMON_VERSION_FULL}
    )

    function(lemon_generate target target_ext source_file)
        get_filename_component(fext "${source_file}" EXT)
        get_filename_component(fpath "${source_file}" PATH)
        get_filename_component(fbase "${source_file}" NAME_WE)

        set("${target}_OUT" "${fpath}/${fbase}.out" PARENT_SCOPE)
        set("${target}_HEADER" "${fpath}/${fbase}.h" PARENT_SCOPE)
        set("${target}_SOURCE" "${fpath}/${fbase}${target_ext}" PARENT_SCOPE)

        if(NOT EXISTS "${fpath}/")
            set(LEMON_MKDIR COMMAND ${CMAKE_COMMAND} -E make_directory "${fpath}")
        endif(NOT EXISTS "${fpath}/")

        add_custom_command(
            OUTPUT "${fpath}/${fbase}${target_ext}"
            OUTPUT "${fpath}/${fbase}.out"
            OUTPUT "${fpath}/${fbase}.h"
            ${LEMON_MKDIR}
            COMMAND ${LEMON}
                ARGS    ${LEMON_FLAGS}
                        "${CMAKE_CURRENT_SOURCE_DIR}/${source_file}"
            COMMAND mv
                ARGS    "${CMAKE_CURRENT_SOURCE_DIR}/${fpath}/${fbase}.out"
                        "${fpath}/${fbase}.out"
            COMMAND mv
                ARGS    "${CMAKE_CURRENT_SOURCE_DIR}/${fpath}/${fbase}.h"
                        "${fpath}/${fbase}.h"
            COMMAND mv
                ARGS    "${CMAKE_CURRENT_SOURCE_DIR}/${fpath}/${fbase}.c"
                        "${fpath}/${fbase}${target_ext}"
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${source_file}"
            COMMENT "Generating ${target}"
        )
    endfunction(lemon_generate)
endif(LEMON)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    Lemon
    REQUIRED_VARS LEMON
    VERSION_VAR LEMON_VERSION
)
