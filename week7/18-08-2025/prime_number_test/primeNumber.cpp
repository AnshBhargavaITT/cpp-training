#include<iostream>
#include<gtest/gtest.h>

bool isPrime(int n)
{
    if(n<=1)
    {
        return false;
    }
    if(n==2)
    {
        return true;
    }
    if(n%2==0)
    {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) 
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

TEST(PrimeTest, NegativeNumbers) 
{
    EXPECT_FALSE(isPrime(-1));
    EXPECT_FALSE(isPrime(-5));
    EXPECT_FALSE(isPrime(-10));
}

TEST(PrimeTest, ZeroAndOne) 
{
    EXPECT_FALSE(isPrime(0));
    EXPECT_FALSE(isPrime(1));
}

TEST(PrimeTest, SmallPrimes) 
{
    EXPECT_TRUE(isPrime(2));
    EXPECT_TRUE(isPrime(3));
    EXPECT_TRUE(isPrime(5));
    EXPECT_TRUE(isPrime(7));
}

TEST(PrimeTest, SmallNonPrimes) 
{
    EXPECT_FALSE(isPrime(4));
    EXPECT_FALSE(isPrime(6));
    EXPECT_FALSE(isPrime(8));
    EXPECT_FALSE(isPrime(9));
    EXPECT_FALSE(isPrime(10));
}

TEST(PrimeTest, LargerPrimes) 
{
    EXPECT_TRUE(isPrime(97));
    EXPECT_TRUE(isPrime(101));
}

TEST(PrimeTest, LargerNonPrimes)
{
    EXPECT_FALSE(isPrime(100));
    EXPECT_FALSE(isPrime(102));
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
