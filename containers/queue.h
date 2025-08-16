#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

namespace containers {

template <class T, class Container = std::vector<T>> class priority_queue {
public:
  using container_type = Container;
  using value_type = typename Container::value_type;
  using size_type = typename Container::size_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;

  [[nodiscard]] auto top() const -> const_reference {
    return container_.front();
  }

  auto push(const value_type &val) -> void {}
  auto push(value_type &&val) -> void {}

  auto pop() -> void {}

  [[nodiscard]] auto empty() const -> bool { return container_.empty(); }
  [[nodiscard]] auto size() const -> size_type { return container_.size(); }

private:
  Container container_;
};

} // namespace containers

#endif // QUEUE_H
