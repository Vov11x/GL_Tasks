#include <forward_list>


template <typename T>
class stack {
    std::forward_list<T> fList; // main container
    size_t max_size_{};     // size of stack
    size_t current_size_{}; // capacity
public:
    stack() = default;
    explicit stack(size_t size) { create(size); }
    void create(size_t size) noexcept;
    void push(const T& data);
    T pop();
    [[nodiscard]] size_t capacity() const noexcept { return current_size_; }
    [[nodiscard]] size_t size() const noexcept { return max_size_; }
    void resize(size_t new_size) noexcept;
};
