#include "scratch.h"

#include "absl/container/flat_hash_map.h"
#include "absl/status/statusor.h"

namespace scratch {

absl::StatusOr<int> Succeed() { return absl::OkStatus(); }

absl::StatusOr<int> Fail() {
  return absl::InvalidArgumentError("invalid argument");
}

absl::flat_hash_map<std::string, int> MakeMap() {
  return {
      {"a", 1},
      {"b", 2},
  };
}

} // namespace scratch
