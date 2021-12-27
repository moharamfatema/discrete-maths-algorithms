#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/fast-exp.c"
#include <iostream>
using ::testing::ElementsAreArray;

/*TEST(TestUtil,TestTimer){
    time_t start = tick();
    sleep(1);
    EXPECT_NEAR(tock(start),1000,1);
}*/
TEST(TestFastExp,TestNaive1)
{
    EXPECT_EQ(naive1(3,644,645),36);
}
TEST(TestFastExp,TestNaive2)
{
    EXPECT_EQ(naive2(3,644,645),36);
}
TEST(TestFastExp,TestAlgo5)
{
    unsigned int size = ceil(log2(645+1));
    char * n = (char *)malloc((size) * sizeof(char));
    strcpy(n, "1010000100");
    EXPECT_EQ(algo5(3,n,645,size),36);
    free(n);
}
TEST(TestUtil, TestUInt2Bin)
{
    const unsigned int n = 644;
    const unsigned int size = ceil(log2(n+1));
    char * nstr = (char *)malloc((size) * sizeof(char));
    uint2bin(n,nstr);
    EXPECT_STREQ(nstr,"1010000100");
    free(nstr);

}
TEST(TestUtil, TestSizeOfBinStr)
{
    EXPECT_EQ(sizeOfBinStr(1024),11);
    EXPECT_EQ(sizeOfBinStr(1023),10);
    EXPECT_EQ(sizeOfBinStr(0),1);
}