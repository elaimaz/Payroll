cmake_minimum_required(VERSION 3.10)
project(Payroll VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Werror -D_GLIBCXX_DEBUG -fno-omit-frame-pointer -fstack-protector-strong -fsanitize=address,undefined")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -flto=auto -march=native -s")

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(Payroll payroll/src/main.cpp)

add_subdirectory(payroll)

add_custom_target(
    check_tests ALL
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running unit tests..."
    DEPENDS test_GTest
)
