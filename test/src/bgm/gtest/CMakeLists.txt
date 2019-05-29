project(bgm_gtest)

cmake_minimum_required(VERSION 3.1)

file(GLOB BGM_GTEST_SRC *.cpp *.c *.cxx)

enable_testing()


add_executable(${TEST_TARGET} ${BGM_GTEST_SRC})


target_include_directories(${TEST_TARGET} 
    PRIVATE ${TESTS_INCLUDE_DIR})

target_link_libraries(${TEST_TARGET} PRIVATE ${TEST_LIB_TARGET})

apply_common_defines(${TEST_LIB_TARGET})

depends_gtest(${TEST_TARGET})
depends_gtest_main(${TEST_TARGET})
