#ifndef SCRATCH_H
#define SCRATCH_H

#include "absl/container/flat_hash_map.h"

namespace scratch {

absl::flat_hash_map<std::string, int> MakeMap();

} // namespace scratch

#endif // SCRATCH_H
