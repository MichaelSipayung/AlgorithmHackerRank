cmake_minimum_required(VERSION 3.27)
project(Algorithm)
enable_testing()
set(CMAKE_CXX_STANDARD 17)
find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
# find_package(Boost CONFIG REQUIRED)
# add_executable(Algorithm main.cpptwosum.h)
#target_link_libraries(Algorithm PRIVATE GTest::gtest GTest::gtest_main
#        GTest::gmock GTest::gmock_main)

# add separate executable for test
add_executable(AlgorithmTests test.cpp )
target_link_libraries(AlgorithmTests PRIVATE GTest::gtest GTest::gtest_main
        GTest::gmock GTest::gmock_main fmt::fmt)

add_test(AllTestsInAlgorithm Algorithm)