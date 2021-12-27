#include <gtest/gtest.h>
#include "../src/fast-exp.c"

TEST(TestFastExp,TestTimer){
    time_t start = tick();
    sleep(1);
    EXPECT_NEAR(tock(start),1000,1);
}