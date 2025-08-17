#include <iostream>

#include "scratch.h"

int main(int argc, char **argv) {
  std::cout << "Hello World!" << std::endl;

  auto map = scratch::MakeMap();
  std::cout << "Map:" << std::endl;
  for (const auto &[key, value] : map) {
    std::cout << "  " << key << ": " << value << std::endl;
  }

  return 0;
}
