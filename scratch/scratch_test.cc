#include "scratch.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace scratch {
namespace {

using ::testing::Pair;
using ::testing::UnorderedElementsAre;

TEST(MapMap, Default) {
  auto map = MakeMap();

  EXPECT_THAT(map, UnorderedElementsAre( //
                       Pair("a", 1),     //
                       Pair("b", 2)      //
                       ));
}

} // namespace
} // namespace scratch

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
