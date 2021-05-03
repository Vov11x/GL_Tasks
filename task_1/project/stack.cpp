#include <iostream>
#include "stack.h"




template <typename T>
stack<T>::stack(size_t size) {
    m_data.resize(size);
}


template<typename T>
void stack<T>::push(const T& data) {
    m_data.push_back(data);
}


template<typename T>
T stack<T>::pop() {
    T temp = *(m_data.rbegin());
    m_data.pop_back();
    return temp;
}


template<typename T>
void stack<T>::resize(size_t new_size) {
    m_data.resize(new_size);
}
