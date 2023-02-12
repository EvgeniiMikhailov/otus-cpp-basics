#include <gtest/gtest.h>
#include "mylist.h"

TEST(ListTest, Basic) {
List<int> vec;
EXPECT_EQ(vec.size(), 0);
vec.push_back(1);
EXPECT_EQ(vec.size(), 1);
EXPECT_EQ(vec[0], 1);
}

TEST(ListTest, PushBack) {
List<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);
EXPECT_EQ(vec[0], 1);
EXPECT_EQ(vec[1], 2);
EXPECT_EQ(vec[2], 3);
EXPECT_EQ(vec.size(), 3);
}

TEST(ListTest, PushFront) {
List<int> vec;
vec.push_front(3);
vec.push_front(2);
vec.push_front(1);
EXPECT_EQ(vec[0], 1);
EXPECT_EQ(vec[1], 2);
EXPECT_EQ(vec[2], 3);
EXPECT_EQ(vec.size(), 3);
}

TEST(ListTest, InsertMiddle) {
List<int> vec;
vec.push_back(3);
vec.push_front(1);
vec.insert(1, 2);
EXPECT_EQ(vec[0], 1);
EXPECT_EQ(vec[1], 2);
EXPECT_EQ(vec[2], 3);
EXPECT_EQ(vec.size(), 3);
}

TEST(ListTest, PopBack) {
List<int> vec;
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

TEST(ListTest, PopFront) {
List<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);
vec.pop_front();
EXPECT_EQ(vec[0], 2);
EXPECT_EQ(vec[1], 3);
EXPECT_EQ(vec.size(), 2);
}

TEST(ListTest, EraseMiddle) {
List<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);
vec.erase(1);
EXPECT_EQ(vec[0], 1);
EXPECT_EQ(vec[1], 3);
EXPECT_EQ(vec.size(), 2);
}
