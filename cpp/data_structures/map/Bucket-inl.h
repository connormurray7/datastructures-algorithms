#pragma once

#include <vector>

template<typename T>
Bucket<T>::Bucket() {
    head = nullptr;
}

template<typename T>
Bucket<T>::Bucket(HashNode<T>& n) {
    head = &n;
}

template<typename T>
bool Bucket<T>::contains(const T& key) const {
    return find(key) != nullptr;
}

template<typename T>
void Bucket<T>::add(std::shared_ptr<HashNode<T>> new_node) {
    if(empty()) {
        head = new_node;
        return;
    }
    auto cur = head;
    while(cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = new_node;
}

template<typename T>
std::shared_ptr<HashNode<T>> Bucket<T>::get_node(const T& key) const {
    return find(key);
}

template<typename T>
bool Bucket<T>::remove(const T& key) {
    if(empty()) {
        return false;
    }
    auto cur = head;
    std::shared_ptr<HashNode<T>> prev = nullptr;
    while(cur != nullptr && cur->key != key) {
        prev = cur;
        cur = cur->next;
    }
    if(cur == nullptr) {
        return false; //key not found.
    }
    if(prev == nullptr) {
        head = head->next;
    } else {
        prev->next = cur->next;
    }
    return true;
}

template<typename T>
bool Bucket<T>::empty() const {
    return head == nullptr;
}

template<typename T>
std::vector<T> Bucket<T>::get_keys() const {
    std::vector<T> v;
    auto cur = head;
    while(cur != nullptr) {
        v.push_back(cur->key);
        cur = cur->next;
    }
    return v;
}

template<typename T>
std::vector<std::shared_ptr<HashNode<T>>> Bucket<T>::get_nodes() const {
    std::vector<std::shared_ptr<HashNode<T>>> v;
    auto cur = head;
    while(cur != nullptr) {
        v.push_back(cur);
        cur = cur->next;
    }
    return v;
}

template<typename T>
std::shared_ptr<HashNode<T>> Bucket<T>::find(const T& key) const {
    auto cur = head;
    while(cur != nullptr && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}
