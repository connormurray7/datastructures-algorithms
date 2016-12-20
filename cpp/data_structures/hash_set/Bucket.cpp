#include "Bucket.h"
#include <vector>

template<typename T>
Bucket<T>::Bucket(HashSetNode<T>& n) {
    node = &n;
}

template<typename T>
bool Bucket<T>::contains(T& val) {
    return find(val) != nullptr;
}

template<typename T>
void Bucket<T>::add(T& val) {
    if(isEmpty()) {
        node = &HashSetNode<T>(val);
        return;
    }
    HashSetNode<T>* n = node;
    while(n->next) {
        n = n->next;
    }
    n->next = &HashSetNode<T>(val);
}

template<typename T>
void Bucket<T>::remove(T& val) {
    if(isEmpty()) {
        return;
    }
    HashSetNode<T>* cur = node;
    HashSetNode<T> prev = nullptr;
    while(cur && cur->val != val) {
        prev = cur;
        cur = cur->next;
    }
    if(cur == nullptr) {
        return; //key not found.
    }
    if(prev == nullptr) {
        node = node->next;
    } else {
        prev->next = cur->next;
    }
}

template<typename T>
bool Bucket<T>::isEmpty() {
    return node == nullptr;
}

template<typename T>
std::vector<T> Bucket<T>::get_keys() {
    std::vector<T> v;
    HashSetNode<T>* n = node;
    while(n) {
        v.push_back(n->val);
        n = n->next;
    }
    return v;
}

template<typename T>
HashSetNode<T>* Bucket<T>::find(T& val) {
    HashSetNode<T>* cur = node;
    while(cur && cur->val != val) {
        cur = cur->next;
    }
    return cur;
}
