cmake_minimum_required(VERSION 3.16.3) # 最低cmake版本要求
project(main) # 项目名称

add_subdirectory(hello_world) # 添加子目录，hello_world目录下有CMakeLists.txt

add_executable(main main.cpp) # 添加可执行文件，main.cpp是源文件
# target_include_directories(main PUBLIC hello_world) 注意：如果hello_world.h 在 hello_world 目录下但main.cpp中没注明路径，则需要添加 include_directories

target_link_libraries(main PUBLIC hello_worldlib) # 将hello_worldlib库链接到main可执行文件