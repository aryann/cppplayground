#include "queue.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace containers {

using ::testing::IsTrue;

TEST(PriorityQueue, Empty) {
  priority_queue<int> q;
  EXPECT_THAT(q.empty(), IsTrue());
}

} // namespace containers

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
