cmake_minimum_required(VERSION 3.16.3)
project(hello_world)

set(HELLO_WORLD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp) # 源文件路径

add_library(hello_worldlib SHARED ${HELLO_WORLD_SRC}) # 以源文件创建一个动态库

target_include_directories(hello_worldlib SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}) # 隐藏的头文件搜索路径，到当前CMakeLists.txt所在目录寻找