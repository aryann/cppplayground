#include "scratch.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "absl/status/status_matchers.h"

namespace scratch {
namespace {

using ::absl_testing::IsOk;
using ::absl_testing::IsOkAndHolds;
using ::absl_testing::StatusIs;
using ::testing::Pair;
using ::testing::UnorderedElementsAre;

TEST(Succeed, Ok) {
  EXPECT_THAT(Succeed(), IsOk());
  EXPECT_THAT(Succeed(), IsOkAndHolds(1));
}

TEST(Fail, InvalidArgument) {
  EXPECT_THAT(Fail(),
              StatusIs(absl::StatusCode::kInvalidArgument, "invalid argument"));
}

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
