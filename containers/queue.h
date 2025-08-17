#ifndef QUEUE_H
#define QUEUE_H

#include <optional>
#include <vector>

namespace containers {

template <class T, class Container = std::vector<T>,
          class Compare = std::less<typename Container::value_type>>
class priority_queue {
public:
  using container_type = Container;
  using value_compare = Compare;
  using value_type = typename Container::value_type;
  using size_type = typename Container::size_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;

  priority_queue() = default;
  explicit priority_queue(Compare compare) : compare_(compare) {}

  [[nodiscard]] auto top() const -> const_reference {
    return container_.front();
  }

  auto push(const value_type &val) -> void {
    container_.push_back(val);
    percolate_up();
  }
  auto push(value_type &&val) -> void {
    container_.push_back(std::move(val));
    percolate_up();
  }

  auto pop() -> void {
    std::swap(container_.front(), container_.back());
    container_.pop_back();
    percolate_down();
  }

  [[nodiscard]] auto empty() const -> bool { return container_.empty(); }
  [[nodiscard]] auto size() const -> size_type { return container_.size(); }

private:
  auto percolate_up() -> void {
    size_type curr = container_.size() - 1;
    while (curr > 0) {
      size_type parent = find_parent(curr);

      if (compare_(container_[parent], container_[curr])) {
        break;
      }

      std::swap(container_[curr], container_[parent]);
      curr = parent;
    }
  }

  auto percolate_down() -> void {
    size_type curr = 0;
    while (curr + 1 < container_.size()) {
      size_type child = min_child(curr);
      if (child >= container_.size()) {
        break;
      }

      if (compare_(container_[curr], container_[child])) {
        break;
      }

      std::swap(container_[curr], container_[child]);
      curr = child;
    }
  }

  [[nodiscard]] auto find_parent(size_type i) -> size_type {
    return (i - 1) / 2;
  }

  [[nodiscard]] auto min_child(size_type i) -> size_type {
    size_type left = i * 2 + 1;
    size_type right = i * 2 + 2;

    if (right >= container_.size()) {
      return left;
    }

    if (compare_(container_[left], container_[right])) {
      return left;
    } else {
      return right;
    }
  }

  Container container_;
  Compare compare_;
};

} // namespace containers

#endif // QUEUE_H
