#include <vector>


template <typename T>
class stack {
public:
    stack()                     : m_max_size{0}, m_current_size{0} {}
    explicit stack(size_t size) : m_max_size{0}, m_current_size{0}  { create(size); }
    
    void create(size_t size);
    void push(const T& data);
    T pop();
    [[nodiscard]] size_t capacity() const { return m_max_size; }
    [[nodiscard]] size_t size()     const { return m_current_size; }
    void resize(size_t new_size);

private:
    std::vector<T> m_data;  // vector stack based on
    size_t m_max_size;      // maximum amount of elements
    size_t m_current_size;  // amount of elements in stack
};
