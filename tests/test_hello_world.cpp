#include "hello_world/hello_world.h"
#include "gtest/gtest.h"

TEST(Hello_World, Hello_World0){
    EXPECT_EQ(0, hello_world());
}