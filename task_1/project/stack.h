#include <vector>


template <typename T>
class stack {
public:
    explicit stack(size_t size);

    void push(const T& data);
    T pop();
    [[nodiscard]] size_t capacity() const { return m_data.capacity(); }
    [[nodiscard]] size_t size()     const { return m_data.size(); }
    void resize(size_t new_size);

private:
    std::vector<T> m_data;
};
