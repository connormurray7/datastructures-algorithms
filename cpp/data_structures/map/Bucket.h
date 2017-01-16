#include "HashNode.h"
#include <vector>
#include <memory>

#ifndef BUCKET_H
#define BUCKET_H

template<typename T>
class Bucket {
public:

    //==============================================//
    //         Constructors and Destructor
    //==============================================//

    Bucket();
        //Default ctor, creates empty bucket.

    Bucket(HashNode<T>& n);
        //Emplaces node in new bucket.

    //==============================================//
    //             Member functions
    //==============================================//

    void add(std::shared_ptr<HashNode<T>> node);
        //Appends node to end of node linked list.
        //Typically O(1) unless many hash collisions

    std::shared_ptr<HashNode<T>> get_node(const T& key) const;
        //Retrieves node for associated key.
        //Typically O(1) unless many hash collisions

    bool contains(const T& key) const;
        //True if bucket contains node with
        //associated key.
        //Typically O(1) unless many hash collisions

    bool remove(const T& key);
        //Removes node from list if node for key exists.

    bool empty() const;
        //True if bucket is empty.

    std::vector<T> get_keys() const;
        //Returns vector of all keys in bucket.
        //O(k) where k is number of keys with the same
        //hash.

    std::vector<std::shared_ptr<HashNode<T>>> get_nodes() const;
        //Returns vector of all nodes in bucket.
        //O(k) where k is number of keys with the same
        //hash.

private:
    std::shared_ptr<HashNode<T>> head;
        //First node in the linked list.

    std::shared_ptr<HashNode<T>> find(const T& key) const;
        //Returns node for associated key.
};

#include "Bucket-inl.h"
#endif
