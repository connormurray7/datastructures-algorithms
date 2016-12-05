#include "Vector.h"
#include <stdexcept>

template<typename T>
Vector<T>::Vector(){}

template<typename T>
Vector<T>::Vector(const Vector<T>& v){
    arr = std::unique_ptr<T[]>(new T[v.size()]);
    for(unsigned int i = 0; i < v.size(); ++i) {
        arr[i] = v[i];
    }
}
    
template<typename T>
Vector<T>::~Vector(){}

template<typename T>
T operator[](int idx){
    return arr[idx];
}
    
template<typename T>
T at(int idx) {
    if(empty() || num_elements < idx) {
        throw std::out_of_range ("Index out of bounds.");
    }
    return arr[idx];
}

template<typename T>
T& front() {
    if(empty()) {
        throw std::out_of_range ("Index out of bounds.");
    }
    return arr[0];
}

template<typename T>
T& back() {
    if(empty()) {
        throw std::out_of_range ("Index out of bounds.");
    }
}

template<typename T>
void push_back(T val){
    if(full()) {
        grow();
    }
    arr[++num_elements] = val;
}

template<typename T>
void pop_back(){
    if(num_elements != 0)
        num_elements--;
}
    
template<typename T>
void resize(int num, const T& val){
    if(num < 0) {
        throw std::out_of_range ("Cannot resize negative size.");
    }
    while(capacity < num) {
        grow();
    }
    for(int i=0; i < num; ++i) {
        arr[i] = val;
    } 
}

template<typename T>
void grow() {
    int doubled = capacity * 2;
    auto new_arr = make_unique<T[]>(new T[doubled]);
    for(int i = 0; i < num_elements; ++i) {
        new_arr[i] = arr[i];
    }
    arr = std::move(new_arr);
}

bool empty(){
    return (num_elements == 0);
}

unsigned int size() {
    return num_elements;
}

bool full(){
    return (num_elements == capacity);
}
