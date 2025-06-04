cmake_minimum_required(VERSION 3.16.3) # 最低cmake版本要求
project(main) # 项目名称

enable_testing() # 启用测试功能

set(HELLO_WORLD_PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}) # 设置项目根目录
add_subdirectory(hello_world) # 添加子目录，hello_world目录下有CMakeLists.txt
add_subdirectory(for_test)

add_executable(main ${HELLO_WORLD_PROJECT_ROOT}/main.cpp) # 添加可执行文件，main.cpp是源文件
# target_include_directories(main PUBLIC hello_world) 注意：如果hello_world.h 在 hello_world 目录下但main.cpp中没注明路径，则需要添加 include_directories
# 也可以在 hello_world/CMakeLists.txt 中添加 target_include_directories(hello_worldlib SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}) 来隐藏头文件搜索路径

target_link_libraries(main PUBLIC hello_worldlib) # 将hello_worldlib库链接到main可执行文件，链接库时自动添加头文件搜索路径
target_link_libraries(main PUBLIC for_testlib)

option(BUILD_TEST "ON: 开启测试； OFF: 默认关闭测试" OFF) # 定义一个选项，是否开启测试，默认关闭
if(BUILD_TEST)
    add_subdirectory(tests) # 添加测试目录
endif()