cmake_minimum_required(VERSION 3.10)
project(Payroll VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set gcc flags
add_compile_options(-Wall -Wextra -Wpedantic -Werror)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wshadow -Wduplicated-cond -Wduplicated-branches -D_GLIBCXX_DEBUG -fno-omit-frame-pointer -fstack-protector-strong -fsanitize=address,undefined,leak,pointer-compare,pointer-subtract")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -flto=auto -march=native -s")

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message("CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
add_executable(Payroll payroll/src/main.cpp)

add_subdirectory(payroll)

# Find Cppcheck and setup analysis
find_program(CPPCHECK cppcheck)
if(CPPCHECK)
    # Configure Cppcheck options as a proper CMake list
    set(CPPCHECK_OPTIONS
        --enable=all
        --inline-suppr
        --std=c++23
        --platform=unix64
        --suppress=missingIncludeSystem
        --suppress=checkersReport
        --quiet
        --checkers-report=cppcheck.report
        --template=[{severity}][{id}] {message} {callstack} On {file}:{line}
        --quiet
        --error-exitcode=1
        -i ${CMAKE_SOURCE_DIR}/third_party
    )

    add_custom_target(
        run_cppcheck
        COMMAND ${CPPCHECK} ${CPPCHECK_OPTIONS} --project=${CMAKE_BINARY_DIR}/compile_commands.json
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running Cppcheck static analysis..."
    )

    add_dependencies(run_cppcheck Payroll)
endif()

add_custom_target(
    check_tests ALL
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS test_GTest
    COMMENT "Running unit tests..."
)

set(RUN_VALGRIND FALSE)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(NOT CMAKE_CXX_FLAGS_DEBUG MATCHES "-fsanitize=address")
        set(RUN_VALGRIND TRUE)
    endif()
endif()

if(RUN_VALGRIND)
    add_test(
        NAME valgrind_check
        COMMAND valgrind 
            --leak-check=full 
            --show-leak-kinds=all 
            --track-origins=yes 
            --error-exitcode=1 
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Payroll
    )
endif()
