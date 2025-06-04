cmake_minimum_required(VERSION 3.16.3)
project(test)

set(BUILD_GMOCK OFF) # 禁用GoogleMock构建，变量会向下传递到googletest的CMakeLists.txt中
add_subdirectory(${HELLO_WORLD_PROJECT_ROOT}/thirdpart/googletest-1.17.0 googletest) # 接入GoogleTest，第一个路径为googletest指定编译路径

add_executable(test_hello_world ${CMAKE_CURRENT_SOURCE_DIR}/test_hello_world.cpp)
# target_include_directories(test_hello_world PUBLIC ${HELLO_WORLD_PROJECT_ROOT}/thirdpart/googletest-1.17.0/googletest/include) # 指定GoogleTest头文件路径
# 隐藏了，不需要指定googletest的头文件路径
target_include_directories(test_hello_world PUBLIC ${HELLO_WORLD_PROJECT_ROOT}) # 指定项目根目录路径, hello_world/hello_world.h在项目根目录下
target_link_libraries(test_hello_world PUBLIC hello_worldlib gtest gtest_main) # 链接hello_worldlib，gtestlib，gtest_mainlib

add_test(NAME test_hello_world COMMAND test_hello_world) # 添加测试，NAME为测试名称，COMMAND为可执行文件

add_executable(test_for_test ${CMAKE_CURRENT_SOURCE_DIR}/test_for_test.cpp)
# target_include_directories(test_for_test PUBLIC ${HELLO_WORLD_PROJECT_ROOT}/thirdpart/googletest-1.17.0/googletest/include)
target_include_directories(test_for_test PUBLIC ${HELLO_WORLD_PROJECT_ROOT})
target_link_libraries(test_for_test PUBLIC for_testlib gtest gtest_main)

add_test(NAME test_for_test COMMAND test_for_test)