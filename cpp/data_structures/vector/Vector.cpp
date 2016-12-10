#include "Vector.h"
#include <stdexcept>
#include <memory>

template<typename T>
Vector<T>::Vector() {
    arr = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
    arr = new T[other.size()];
    for(unsigned int i = 0; i < other.size(); ++i) {
        arr[i] = other[i];
    }
}

template<typename T>
Vector<T>::~Vector(){}

template<typename T>
T& Vector<T>::operator[](unsigned int idx) const {
    return arr[idx];
}

template<typename T>
T& Vector<T>::at(unsigned int idx) const {
    if(empty() || num_elements < idx) {
        throw std::out_of_range ("Index out of bounds.");
    }
    return arr[idx];
}

template<typename T>
T& Vector<T>::front() const {
    if(empty()) {
        throw std::out_of_range ("Index out of bounds.");
    }
    return arr[0];
}

template<typename T>
T& Vector<T>::back() const {
    if(empty()) {
        throw std::out_of_range ("Index out of bounds.");
    }
    return arr[size()-1];
}

template<typename T>
void Vector<T>::push_back(const T& val) {
    if(full()) {
        grow();
    }
    arr[num_elements++] = val;
}

template<typename T>
void Vector<T>::pop_back() {
    if(num_elements != 0)
        num_elements--;
}

template<typename T>
void Vector<T>::resize(unsigned int num, const T& val) {
    while(capacity < num) {
        grow();
    }
    for(unsigned int i=0; i < num; ++i) {
        arr[i] = val;
    }
}

template<typename T>
void Vector<T>::grow() {
    capacity *= 2;
    auto old = arr;
    auto new_arr = new T[capacity];
    for(unsigned int i = 0; i < num_elements; ++i) {
        new_arr[i] = arr[i];
    }
    arr = new_arr;
    delete[] old;
}

template<typename T>
bool Vector<T>::empty() const {
    return (num_elements == 0);
}

template<typename T>
unsigned int Vector<T>::size() const {
    return num_elements;
}

template<typename T>
bool Vector<T>::full() {
    return (num_elements == capacity);
}
