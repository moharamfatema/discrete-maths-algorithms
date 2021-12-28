#include <gtest/gtest.h>
#include "../src/trialDivision.c"

TEST(TestTrial,TestCorrectness)
{
    EXPECT_EQ(isPrime(0),-1);
    EXPECT_EQ(isPrime(1),-1);
    EXPECT_EQ(isPrime(2),1);
    EXPECT_EQ(isPrime(55),0);
    EXPECT_EQ(isPrime(997),1);
}