set(ALL_TARGETS_CXX_STANDARD 14)

function(all_targets_require_cxx11)
    set(CXX_STANDARD_REQUIRED CACHE FORCE ON)
    foreach(loop_var ${ALL_TARGETS})
        set_property(TARGET ${loop_var} 
            PROPERTY CXX_STANDARD ${ALL_TARGETS_CXX_STANDARD})
    endforeach(loop_var)
endfunction()

function(target_set_cxx_standard TARGET_NAME_PARAM WHICH_CXX_STANDARD)
    set(CXX_STANDARD_REQUIRED CACHE FORCE ON)
    set_property(TARGET ${TARGET_NAME_PARAM} PROPERTY CXX_STANDARD ${WHICH_CXX_STANDARD})
endfunction()

function(target_require_cxx11 TARGET_NAME_PARAM)
    target_set_cxx_standard(${TARGET_NAME_PARAM} 11)
endfunction()

function(target_require_cxx14 TARGET_NAME_PARAM)
    target_set_cxx_standard(${TARGET_NAME_PARAM} 14)
endfunction()
