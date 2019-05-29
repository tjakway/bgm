project(bgm_tests)

cmake_minimum_required(VERSION 3.1)

file(GLOB TEST_SRC *.cpp *.c *.cxx)

enable_testing()


add_library(${TEST_LIB_TARGET} ${TEST_SRC})


target_include_directories(${TEST_LIB_TARGET} 
    PRIVATE ${TESTS_INCLUDE_DIR})
target_link_libraries(${TEST_LIB_TARGET} PUBLIC ${MAIN_LIB_TARGET})

apply_common_defines(${TEST_LIB_TARGET})

add_subdirectory(gtest)
