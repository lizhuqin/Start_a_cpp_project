cmake_minimum_required(VERSION 3.16.3)
project(for_test)

set(FOR_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/for_test.cpp) # 源文件路径

add_library(for_testlib SHARED ${FOR_TEST_SRC}) # 以源文件创建一个动态库