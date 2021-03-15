#include <iostream>
#include "stack.h"



template<typename T>
void stack<T>::create(size_t size) noexcept {
    max_size_ = size;
}

template<typename T>
void stack<T>::push(const T& data) {
    if (current_size_ < max_size_) {
        fList.push_front(data);
        current_size_++;
    } else {
        throw std::out_of_range("Error! The stack is filled. (try to resize)");
    }
}

template<typename T>
T stack<T>::pop() {
    if (current_size_ != 0) {
        T temp = *(fList.begin());
        fList.pop_front();
        current_size_--;
        return temp;
    } else {
        throw std::out_of_range("Error! The stack is empty.");
    }
}

template<typename T>
void stack<T>::resize(size_t new_size) noexcept {
    if (new_size > current_size_) {
        max_size_ = new_size;
    } else {
        size_t delta = current_size_ - new_size;
        while (delta--) {
            fList.pop_front();
        }
    }
}

