include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/releases/download/v1.17.0/googletest-1.17.0.tar.gz
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TEST_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin_test)
file(MAKE_DIRECTORY ${TEST_OUTPUT_DIR})  

add_executable(test_GTest tests/test_GTest.cpp)
set_target_properties(test_GTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR}
)

target_link_libraries(
    test_GTest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_GTest)

set_property(TEST ${test_GTest} PROPERTY WORKING_DIRECTORY ${TEST_OUTPUT_DIR})
