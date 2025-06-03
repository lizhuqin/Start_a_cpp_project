# 学习构建如何C++项目

## C++功能模块
1. 按模块去实现子函数的不同功能：
main.cpp + hello_world.{h/cpp}，在hello_world.h中\#ifndef, \#define and \#endif：防止文件被重复include

## Make工具与Makefile的写法
1. Makefile文件：
make命令: 依赖文件
    执行的命令
2. g++分步编译：整合到一个make命令
```shell
g++ -c main.cpp # -> main.o
g++ -c hello_world/hello_world.cpp # -> hello_word.o
g++ -o main main.o hello_world.o # 链接
```

## Cmake工具与CMakeLists.txt的写法
1. 分模块去写CMakeLists.txt：子函数生成动态库或者静态库+主函数链接这些库 (*动态库与静态库的区别*)
2. CMakeLists的命令见具体的CMakeLists.txt文件
3. 编译方法：根目录下
```shell
mkdir build
cd build
cmake .. # cmake作用在根目录的CMakeLists.txt
make # Ubuntu
```
也可以直接在根目录执行：
```shell
cmake -S . -B build # 自动创建build目录并生成项目
cmake --build build # 编译，相当于cd build+make
```