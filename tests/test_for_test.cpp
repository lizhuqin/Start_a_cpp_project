#include "for_test/for_test.h"
#include "gtest/gtest.h" // 包含GoogleTest库的头文件，注意CMakeLists.txt中需要链接gtest库及其路径

TEST(Sum, Sum0){ // TEST(测试组，测试实例)
    int a = 3;
    int b = 5;
    EXPECT_EQ(8, Sum(a, b)); // 断言相等
}

TEST(IsOdd, IsOdd3){
    EXPECT_TRUE(IsOdd(3)); // 断言真
}

TEST(IsOdd, IsOdd5){
    EXPECT_TRUE(IsOdd(5));
}