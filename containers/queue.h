#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

namespace containers {

template <typename T, typename Container = std::vector<T>>
class priority_queue {
public:
  [[nodiscard]] bool empty() { return true; }
};

} // namespace containers

#endif // QUEUE_H
