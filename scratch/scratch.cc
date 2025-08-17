#include "scratch.h"

#include "absl/container/flat_hash_map.h"

namespace scratch {

absl::flat_hash_map<std::string, int> MakeMap() {
  return {
      {"a", 1},
      {"b", 2},
  };
}

} // namespace scratch
