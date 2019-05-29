cmake_minimum_required(VERSION 3.1)

project(bgm)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include("${CMAKE_SOURCE_DIR}/cmake/vars.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/common_defines.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/default_build_type.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/enable_standalone_debug.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/process_warnings.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/clang_libstdcpp_hack.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/depends_spdlog.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/depends_gtest.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/target_set_cxx_standard.cmake")


OPTION(BUILD_TESTS ON)

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()
