# 学习构建如何C++项目

## C++功能模块
1. 按模块去实现子函数的不同功能：
main.cpp + hello_world.{h/cpp}，在hello_world.h中`\#ifndef, \#define and \#endif`：防止文件被重复include

## Make工具与Makefile的写法
1. Makefile文件：
```
make命令: 依赖文件
    执行的命令
```
2. g++分步编译：整合到一个make命令
```shell
g++ -c main.cpp # -> main.o
g++ -c hello_world/hello_world.cpp # -> hello_word.o
g++ -o main main.o hello_world.o # 链接
```

## Cmake工具与CMakeLists.txt的写法
1. 分模块去写CMakeLists.txt：子函数生成动态库或者静态库+主函数链接这些库 (**动态库与静态库的区别**)
2. CMakeLists的命令见具体的CMakeLists.txt文件
3. 编译方法：根目录下
```shell
mkdir build
cd build
cmake .. # cmake作用在根目录的CMakeLists.txt
make # Ubuntu
```

## 测试用例与GoogleTest
1. 在tests文件夹里编写测试所用的.cpp文件和CMakeLists.txt构建文件。注意接入第三方库的方法。
2. 学习**GoogleTest**的相关使用！
3. 在根目录的CMakeLists.txt文件中添加测试目录tests。注意：预存项目根目录变量以备后续使用。
4. 两点优化：
定义option选择是否编译测试代码
在子模块的CMakeLists.txt中可以将头文件目录与lib库绑定，到当前CMake路径下寻找头文件，如此在C++代码中include时可以不加头文件路径
5. `set(BUILD_GMOCK OFF)`可以关闭GoogleTest库的GMOCK功能，变量会自动传递到下一级CMakeLists.txt中

## cmake的跨平台
1. 自动检测环境生成对应的编译类型，使用`cmake --help`查看可生成的编译类型
2. `-G"Ninja"`指定生成的编译类型
3. 跨平台编译：
```shell
cmake -S . -B build # 自动创建build目录并生成项目
cmake --build build # 编译，在Ubuntu相当于cd build+make，会按照平台执行相应的编译类型
cmake --install build # 安装脚本
```