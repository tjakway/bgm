include(CheckCXXCompilerFlag)

function(enable_standalone_debug TARGET_NAME_PARAM)
    add_flag_if_supported("${TARGET_NAME_PARAM}" "-fstandalone-debug")
endfunction()

#add a flag to the target if it's supported by the current compiler
function(add_flag_if_supported TARGET_NAME_PARAM FLAG_NAME_PARAM)
    CHECK_CXX_COMPILER_FLAG("${FLAG_NAME_PARAM}" FLAG_SUPPORTED_RESULT)

    if(FLAG_SUPPORTED_RESULT)
        target_compile_options("${TARGET_NAME_PARAM}" 
            PRIVATE "${FLAG_NAME_PARAM}")
    endif()
endfunction()
