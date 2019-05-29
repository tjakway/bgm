#define targets
set(MAIN_LIB_TARGET bgm_lib)
set(UTIL_LIB_TARGET bgm_util_lib)
set(MAIN_EXE_TARGET bgm)
set(TEST_LIB_TARGET test_lib_bgm)
set(TEST_TARGET test_bgm)
set(RC_TEST_TARGET test_bgm_rc)

set(RUN_TEST_TARGET run_bgm_test_target)
set(RUN_RC_TEST_TARGET run_bgm_rc_test_target)

#set language options
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

#define dependency paths
set(MACH7_PATH "${CMAKE_SOURCE_DIR}/lib/Mach7")
set(MACH7_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/lib/Mach7/code")

set(IMMER_TARGET_NAME immer)
set(IMMER_PATH "${CMAKE_SOURCE_DIR}/lib/immer")
set(IMMER_BIN_DIR "${CMAKE_BINARY_DIR}/immer")

set(CROSSGUID_DIR "${CMAKE_SOURCE_DIR}/lib/crossguid")
set(CROSSGUID_BIN_DIR "${CMAKE_BINARY_DIR}/crossguid")
set(CROSSGUID_INCLUDE_DIR ${CROSSGUID_DIR})
set(CROSSGUID_TARGET_NAME xg)

set(GTEST_DIR "${CMAKE_SOURCE_DIR}/lib/googletest")
set(GTEST_BIN_DIR "${CMAKE_BINARY_DIR}/gtest")

set(RAPIDCHECK_DIR "${CMAKE_SOURCE_DIR}/lib/rapidcheck")
set(RAPIDCHECK_BIN_DIR "${CMAKE_BINARY_DIR}/rapidcheck")
set(RAPIDCHECK_TARGET_NAME "rapidcheck")

set(TMXLITE_DIR "${CMAKE_SOURCE_DIR}/lib/tmxlite/tmxlite")
set(TMXLITE_BIN_DIR "${CMAKE_BINARY_DIR}/tmxlite")

set(CXX_PRETTYPRINT_DIR "${CMAKE_SOURCE_DIR}/lib/cxx-prettyprint")

set(FMT_TARGET_NAME fmt)
set(FMT_DIR "${CMAKE_SOURCE_DIR}/lib/fmt")
set(FMT_BIN_DIR "${CMAKE_BINARY_DIR}/fmt")

set(GLM_DIR "${CMAKE_SOURCE_DIR}/lib/glm")
set(GLM_BIN_DIR "${CMAKE_BINARY_DIR}/glm")
set(GLM_TARGET_NAME "glm")

set(TESTS_BIN_DIR ${CMAKE_BINARY_DIR})
set(TESTS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/test/include)

set(LODEPNG_TARGET_NAME lodepng)

#misc
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
