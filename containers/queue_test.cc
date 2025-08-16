#include "queue.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(MyTest, Ok) {
  EXPECT_EQ(2, 2);
  EXPECT_EQ(2, 3);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
