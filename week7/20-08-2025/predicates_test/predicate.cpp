#include <iostream>
#include <cmath>
#include <gtest/gtest.h>

bool isAlmostEqual(int a ,int b)
{
    return std::abs(a-b) < 10;
}

TEST(ExpectPredicateTest, isAlmostEqual)
{
    int a=0;
    int b=10;
    EXPECT_FALSE(isAlmostEqual(a,b));
    EXPECT_PRED2(isAlmostEqual, a, b);
}

testing::AssertionResult isAlmostEqual2(int a , int b)
{
    if(std::abs(a-b) < 10)
    {
        return testing::AssertionSuccess();
    }
    else {
    
        return testing::AssertionFailure() << "a is " << a << ", b is " << b << ", difference is " << std::abs(a-b);
    }
}
TEST(ExpectPredicateTest, isAlmostEqual2)
{
    int a=0;
    int b=100;
    EXPECT_TRUE(isAlmostEqual2(a,b));             
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
