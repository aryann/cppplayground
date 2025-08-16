#include "queue.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace containers {

using ::testing::ElementsAre;
using ::testing::IsTrue;

TEST(PriorityQueue, Empty) {
  priority_queue<int> q;
  EXPECT_THAT(q.empty(), IsTrue());
}

TEST(PriorityQueue, PushNonDecreasing) {
  priority_queue<int> q;
  q.push(1);
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  std::vector<int> vals;
  while (!q.empty()) {
    vals.push_back(q.top());
    q.pop();
  }

  EXPECT_THAT(vals, ElementsAre(1, 1, 2, 3, 4, 5));
}

TEST(PriorityQueue, PushNonIncreasing) {
  priority_queue<int> q;
  q.push(5);
  q.push(4);
  q.push(3);
  q.push(3);
  q.push(3);
  q.push(2);
  q.push(1);

  std::vector<int> vals;
  while (!q.empty()) {
    vals.push_back(q.top());
    q.pop();
  }

  EXPECT_THAT(vals, ElementsAre(5, 4, 3, 3, 3, 2, 1));
}

TEST(PriorityQueue, PushUnordered) {
  priority_queue<int> q;
  q.push(1);
  q.push(2);
  q.push(5);
  q.push(9);
  q.push(6);
  q.push(4);
  q.push(4);
  q.push(6);
  q.push(1);
  q.push(2);

  std::vector<int> vals;
  while (!q.empty()) {
    vals.push_back(q.top());
    q.pop();
  }

  EXPECT_THAT(vals, ElementsAre(1, 1, 2, 2, 4, 4, 5, 6, 6, 9));
}

TEST(PriorityQueue, Size) {
  priority_queue<int> q;
  EXPECT_EQ(q.size(), 0);

  q.push(1);
  EXPECT_EQ(q.size(), 1);

  q.push(2);
  EXPECT_EQ(q.size(), 2);

  q.push(3);
  EXPECT_EQ(q.size(), 3);

  q.push(4);
  EXPECT_EQ(q.size(), 4);

  q.push(5);
  EXPECT_EQ(q.size(), 5);

  q.pop();
  EXPECT_EQ(q.size(), 4);

  q.pop();
  EXPECT_EQ(q.size(), 3);

  q.pop();
  EXPECT_EQ(q.size(), 2);

  q.pop();
  EXPECT_EQ(q.size(), 1);

  q.pop();
  EXPECT_EQ(q.size(), 0);
  EXPECT_EQ(q.size(), 0);
  EXPECT_EQ(q.size(), 0);
}

} // namespace containers

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
