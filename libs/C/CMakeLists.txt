cmake_minimum_required(VERSION 3.18.0)

project(zeta-filter)

set(TEST_FILES
    tests/Complex_test.cpp
    tests/Zeta_test.cpp
)

set(SOURCE_FILES
    src/Complex.c
    src/Zeta.c
)

add_executable(test 
    tests/tests_runner.cpp
    ${SOURCE_FILES}
    ${TEST_FILES}
)
target_include_directories(test PRIVATE
    inc
)
target_link_libraries(test PRIVATE
    gtest 
    pthread
)