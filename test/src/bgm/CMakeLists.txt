project(bgm_tests)

cmake_minimum_required(VERSION 3.1)

file(GLOB TEST_SRC *.cpp *.c *.cxx)

enable_testing()


add_library(${TEST_LIB_TARGET} ${TEST_SRC})

#need at least one source file to build an executable
#see https://stackoverflow.com/questions/34234446/cmake-is-it-possible-to-build-an-executable-from-only-static-libraries-and-no-s
add_executable(${TEST_TARGET} ${TEST_EXE_SRC})

target_include_directories(${TEST_LIB_TARGET} 
    PRIVATE ${TESTS_INCLUDE_DIR})

apply_common_defines(${TEST_LIB_TARGET})
