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

  [[nodiscard]] auto empty() const -> bool { return container_.empty(); }

private:
  Container container_;
};

} // namespace containers

#endif // QUEUE_H
