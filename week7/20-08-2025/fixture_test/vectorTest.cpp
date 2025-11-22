#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

class VectorTest : public ::testing::Test 
{
protected:
    std::vector<int> vec;

    void SetUp() override 
    {
        vec = {1, 2, 3, 4, 5};
    }

    void TearDown() override 
    {
        vec.clear(); 
    }
};

TEST_F(VectorTest, SizeIsFive) 
{
    EXPECT_EQ(vec.size(), 5);
}

TEST_F(VectorTest, ContainsElement) 
{
    EXPECT_NE(std::find(vec.begin(), vec.end(), 3), vec.end());
}

TEST_F(VectorTest, RemoveElement) 
{
    vec.erase(std::remove(vec.begin(), vec.end(), 2), vec.end());
    EXPECT_EQ(std::find(vec.begin(), vec.end(), 2), vec.end());
}

TEST_F(VectorTest, PushBackIncreasesSize) 
{
    vec.push_back(6);
    EXPECT_EQ(vec.size(), 6);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
