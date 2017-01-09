#include "../TreeNode.h"
#include <vector>
#include <memory>
#include <functional>


#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

template<typename K, typename V, typename C = std::less<K>>
class BinaryHeap {
public:

    //==============================================//
    //         Constructors and Destructor
    //==============================================//

    BinaryHeap();
        //Requires nothing, creates empty heap.

    BinaryHeap(const BinaryHeap& other);
        //Copy constructor, shallow copy

    ~BinaryHeap();
        //Does nothing, unique_ptrs take care of
        //deallocation.

    void push(const K& key, const V& val);
        //Emplaces val with associated key on heap
        //O(log n) time.

    void pop();
        //Removes element with highest priority (top
        //of the heap). O(log n).

    V& top() const;
        //Returns the val of the highest priority. O(1)

    bool empty() const;
        //True if empty, O(1).

private:
    
    std::vector<std::unique_ptr<TreeNode<K,V>>> heap;
        //Vector that stores pointers to all of the nodes
        //The 0th element is a sentinel as the heap starts
        //at index 1.

    void fix_down(int node_idx);
        //Also know as "bubble_down", node with lowered
        //priority may need to be shifted down to
        //maintain the heap property. O(log n)

    void fix_up(int node_idx);
        //Also know as "bubble_up", node with increased
        //priority may need to be shifted up to
        //maintain the heap property. O(log n)

    C comp;
        //Comparator used to determine a nodes priority,
        //default is std::less<K>
};

#endif
