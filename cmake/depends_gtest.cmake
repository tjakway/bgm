function(gtest_one_time_setup)
    if(NOT GTEST_ONE_TIME_INIT_FLAG)
        add_subdirectory("${GTEST_DIR}" "${GTEST_BIN_DIR}" EXCLUDE_FROM_ALL)

        #-Wp,-w suppresses preprocessor warnings, -w suppresses gcc warnings
        set(GTEST_COMPILE_OPTIONS -Wp,-w -w)

        target_compile_options(gtest PRIVATE ${GTEST_COMPILE_OPTIONS})
        target_compile_options(gtest_main PRIVATE ${GTEST_COMPILE_OPTIONS})
    endif()

    set(GTEST_ONE_TIME_INIT_FLAG ON CACHE BOOL 
        "cmake/depends_gtest.cmake flag to ensure we only do initialization once" FORCE)
endfunction()

function(depends_gtest TARGET_NAME_PARAM)
    gtest_one_time_setup()

    target_include_directories(${TARGET_NAME_PARAM} 
        PRIVATE SYSTEM ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    target_include_directories(${TARGET_NAME_PARAM} 
        PRIVATE SYSTEM ${GTEST_INCLUDE_DIRS})
    target_link_libraries(${TARGET_NAME_PARAM} PRIVATE gtest gtest_main)
endfunction()

function(depends_gtest_main TARGET_NAME_PARAM)
    gtest_one_time_setup()

    target_link_libraries(${TARGET_NAME_PARAM} PRIVATE gtest_main)
endfunction()
