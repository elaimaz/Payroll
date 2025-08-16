# DEFINE CORE LIBRARY FIRST
file(GLOB PAYROLL_CORE_SOURCES
    handlers/sources/*.cpp
    entities/sources/*.cpp
)
add_library(payroll_core STATIC ${PAYROLL_CORE_SOURCES})
target_include_directories(payroll_core PUBLIC
    Interfaces
    entities/includes
    handlers/includes
)

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

# Find all test source files
file(GLOB TEST_SOURCES "tests/*.cpp")

add_executable(test_runner ${TEST_SOURCES})
set_target_properties(test_runner PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR}
)

target_link_libraries(
    test_runner PRIVATE
    payroll_core
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(test_runner
    WORKING_DIRECTORY ${TEST_OUTPUT_DIR}
    PROPERTIES
        ENVIRONMENT "TEST_OUTPUT_DIR=${TEST_OUTPUT_DIR}"
)
