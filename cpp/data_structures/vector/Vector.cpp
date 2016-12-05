#include "Vector.h"

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
T operator[](int idx){}
    
template<typename T>
T at(int idx){}

template<typename T>
T* front(){}

template<typename T>
T* back(){}

template<typename T>
bool empty(){}

template<typename T>
unsigned int size(){}

template<typename T>
void push_back(T val){}

template<typename T>
void pop_back(){}
    
template<typename T>
void resize(int num){}

template<typename T>
T[] arr{}

template<typename T>
int capacity = 1{}

template<typename T>
int num_elements = 0{}

template<typename T>
void grow(){}

template<typename T>
bool full(){}
