#include "absl/container/flat_hash_map.h"

#include <iostream>

int main() {
  absl::flat_hash_map<int, int> map;
  std::cout << "size = " << map.size();
  return 0;
}
