#ifndef SCRATCH_H
#define SCRATCH_H

#include "absl/container/flat_hash_map.h"
#include "absl/status/statusor.h"

namespace scratch {

absl::StatusOr<int> Succeed();

absl::StatusOr<int> Fail();

absl::flat_hash_map<std::string, int> MakeMap();

} // namespace scratch

#endif // SCRATCH_H
