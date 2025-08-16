#ifndef QUEUE_H
#define QUEUE_H

#include <optional>
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
  void percolate_up() {
    int curr = container_.size() - 1;
    while (true) {
      std::optional<int> parent = find_parent(curr);
      if (!parent) {
        break;
      }

      if (container_[*parent] <= container_[curr]) {
        break;
      }

      std::swap(container_[curr], container_[*parent]);
      curr = *parent;
    }
  }

  void percolate_down() {
    int curr = 0;
    while (curr + 1 < container_.size()) {
      int child = min_child(curr);
      if (container_[curr] <= container_[child]) {
        break;
      }

      std::swap(container_[curr], container_[child]);
      curr = child;
    }
  }

  [[nodiscard]] static std::optional<int> find_parent(int i) {
    if (i < 1) {
      return std::nullopt;
    }

    return (i - 1) / 2;
  }

  [[nodiscard]] int min_child(int i) {
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (right >= container_.size()) {
      return left;
    }

    if (container_[left] <= container_[right]) {
      return left;
    } else {
      return right;
    }
  }

  Container container_;
};

} // namespace containers

#endif // QUEUE_H
