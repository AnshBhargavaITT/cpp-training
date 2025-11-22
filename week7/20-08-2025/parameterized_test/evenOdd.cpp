#include <gtest/gtest.h>
#include <string>

class MyTestSuite : public ::testing::TestWithParam<int> 
{
protected:
    int param_value;

    void SetUp() override 
    {
        param_value = GetParam();
        std::cout << "Preparing test with parameter: " << param_value << std::endl;
    }

    void TearDown() override 
    {
        std::cout << "Cleaning up after test with parameter: " << param_value << std::endl;
    }

    std::string paramAsString() const 
    {
        return "Param_" + std::to_string(param_value);
    }
};

TEST_P(MyTestSuite, IsEven) 
{
    std::string msg = paramAsString() + " should be even";

    EXPECT_EQ(param_value % 2, 0) << msg;
}

TEST_P(MyTestSuite, IsOdd)
{
    std::string msg = paramAsString() + " should be odd";
    EXPECT_TRUE(param_value % 2 != 0) << msg;
}


INSTANTIATE_TEST_SUITE_P(
    EvenNumbers,
    MyTestSuite,
    ::testing::Values(2, 4, 6, 8, 10)
);

INSTANTIATE_TEST_SUITE_P(
    OddNumbers,
    MyTestSuite,
    ::testing::Values(1, 3, 5)
);

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
