cmake_minimum_required(VERSION 3.27)
project(Algorithm)
enable_testing()
set(CMAKE_CXX_STANDARD 11)
find_package(GTest CONFIG REQUIRED)
add_executable(Algorithm main.cpp
        twosum.h)
target_link_libraries(Algorithm PRIVATE GTest::gtest GTest::gtest_main
        GTest::gmock GTest::gmock_main)

# add separate executable for test
add_executable(AlgorithmTests test.cpp
        test.cpp)
target_link_libraries(AlgorithmTests PRIVATE GTest::gtest GTest::gtest_main
        GTest::gmock GTest::gmock_main)

add_test(AllTestsInAlgorithm Algorithm)