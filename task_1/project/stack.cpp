#include <iostream>
#include "stack.h"




template<typename T>
void stack<T>::create(size_t size) {
    if (m_max_size)
        return;

    m_data.resize(size);
    m_max_size = size;
}


template<typename T>
void stack<T>::push(const T& data) {
    if (m_current_size >= m_max_size)
        throw std::logic_error("Error! The stack is filled. (try to resize)");

    m_data.push_back(data);
    m_current_size++;
}


template<typename T>
T stack<T>::pop() {
    if (m_current_size == 0)
        throw std::logic_error("Error! The stack is empty.");

    T temp = *(m_data.cend()-1);
    m_data.pop_back();
    m_current_size--;
    return temp;
}


template<typename T>
void stack<T>::resize(size_t new_size) {
    m_data.resize(new_size);
    m_max_size = new_size;
    if (new_size < m_current_size) {
        m_current_size = new_size;
    }
}
