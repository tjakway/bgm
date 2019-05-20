function(apply_debug_defines TARGET_NAME_PARAM)
    enable_standalone_debug("${TARGET_NAME_PARAM}")
endfunction()

function(apply_common_defines TARGET_NAME_PARAM)
    target_compile_definitions(${TARGET_NAME_PARAM}
        PRIVATE "-DUNIQUE_UTIL_NS=CITY_GAME_NS"
        PRIVATE "-DCITY_GAME_NS=city_game")

    #check if we're building in debug mode
    string(TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_UPPER_RES)
    if("${BUILD_TYPE_UPPER_RES}" MATCHES ".*DEBUG.*")
        apply_debug_defines("${TARGET_NAME_PARAM}")
    endif()
endfunction()
