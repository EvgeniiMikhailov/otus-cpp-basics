#include <gtest/gtest.h>
#include "myvector.h"

TEST(VectorTest, Basic) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    vec.push_back(1);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 1);
}

TEST(VectorTest, PushBack) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec.size(), 3);
}

TEST(VectorTest, PushFront) {
    Vector<int> vec;
    vec.push_front(3);
    vec.push_front(2);
    vec.push_front(1);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec.size(), 3);
}

TEST(VectorTest, InsertMiddle) {
    Vector<int> vec;
    vec.push_back(3);
    vec.push_front(1);
    vec.insert(1, 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec.size(), 3);
}

TEST(VectorTest, PopBack) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 2);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 1);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 0);
    EXPECT_TRUE(vec.empty());
}

TEST(VectorTest, PopFront) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.erase(0);
    EXPECT_EQ(vec[0], 2);
    EXPECT_EQ(vec[1], 3);
    EXPECT_EQ(vec.size(), 2);
}

TEST(VectorTest, EraseMiddle) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.erase(1);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 3);
    EXPECT_EQ(vec.size(), 2);
}
