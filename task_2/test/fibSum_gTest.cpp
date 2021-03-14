#include "fibSum.h"
#include "gtest/gtest.h"


TEST(fibSum, sum_of_n_numbers) {
    const unsigned sum_of_2 = 1;
    const unsigned sum_of_5 = 7;
    const unsigned sum_of_10 = 88;

    EXPECT_EQ(fibSum(2), sum_of_2);
    EXPECT_EQ(fibSum(5), sum_of_5);
    EXPECT_EQ(fibSum(10), sum_of_10);
}


TEST(fibSum, null_points) {
    const unsigned sum_of_0 = 0;
    const unsigned sum_of_1 = 0;

    EXPECT_EQ(fibSum(0), sum_of_0);
    EXPECT_EQ(fibSum(1), sum_of_1);
}


int main(int argc, char** argv)
{
    printf("Running main() from fibSum_gTest.cpp\n");

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}


