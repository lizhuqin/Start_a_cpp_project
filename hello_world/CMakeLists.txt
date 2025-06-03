cmake_minimum_required(VERSION 3.16.3)
project(hello_world)

set(HELLO_WORLD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp) # 源文件路径

add_library(hello_worldlib SHARED ${HELLO_WORLD_SRC}) # 以源文件创建一个动态库