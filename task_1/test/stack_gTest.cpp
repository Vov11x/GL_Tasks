#include "stack.cpp"
#include "gtest/gtest.h"


TEST(stack, constructors) {
    stack<int> st;
    EXPECT_EQ(st.capacity(), 0);
    EXPECT_EQ(st.size(), 0);

    stack<int> st2(5);
    EXPECT_EQ(st2.capacity(), 0);
    EXPECT_EQ(st2.size(), 5);
}

TEST(stack, create) {
    stack<int> st;
    st.create(5);

    EXPECT_EQ(st.capacity(), 0);
    EXPECT_EQ(st.size(), 5);
}

TEST(stack, push_1) {
    stack<int> st;
    EXPECT_THROW(st.push(5), std::out_of_range);
}

TEST(stack, push_2) {
    stack<int> st(1);
    st.push(5);
    EXPECT_EQ(st.size(), 1);
    EXPECT_EQ(st.capacity(), 1);
}

TEST(stack, pop_1) {
    stack<int> st;
    EXPECT_THROW(st.pop(), std::out_of_range);
}

TEST(stack, pop_2) {
    stack<int> st(1);
    st.push(5);

    EXPECT_EQ(st.pop(), 5);
}

TEST(stack, resize) {
    stack<int> st(5);
    EXPECT_EQ(st.size(), 5);

    st.resize(3);
    EXPECT_EQ(st.size(), 3);

    st.resize(7);
    EXPECT_EQ(st.size(), 7);
}

int main(int argc, char** argv) {
    printf("Running main() from fibSum_gTest.cpp\n");

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}


