cmake_minimum_required(VERSION 3.1)
project(bgm_src)

FILE(GLOB MAIN_LIB_SRCS 
    *.cpp *.c *.cxx)

add_library(${MAIN_LIB_TARGET} ${MAIN_LIB_SRCS})
apply_common_defines(${MAIN_LIB_TARGET})

#add dependencies
depends_spdlog(${MAIN_LIB_TARGET})

target_include_directories(${MAIN_LIB_TARGET} SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/include)

process_warnings(${MAIN_LIB_TARGET})
target_require_cxx14(${MAIN_LIB_TARGET})
