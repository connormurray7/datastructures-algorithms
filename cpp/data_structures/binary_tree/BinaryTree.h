#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TreeNode.h"
#include <vector>

/* Simple Binary Tree implementation
 * does not include balancing. Most
 * operations are O(log n), O(n) worst
 * case.
 */

template<typename K, typename V>
class BinaryTree {
public:

    //==============================================//
    //        Constructors and Destructor
    //==============================================//

    BinaryTree();
        //Requires nothing, creates empty BT

    BinaryTree(BinaryTree<K,V> &tree_in);
        //Requires a vector of node pointers

    ~BinaryTree();
        //Requires nothing, does nothing, shared_ptrs
        //delete the data for us.

    //==============================================//
    //                 Map functions
    //==============================================//

    V& at(const K& key);
        //Requires the K, returns value associated to key.
        //O(log N) average, O(N) worst case

    V& operator[](const K& key);
        //Overloaded operator that calls find.

    void insert(const K& key, const V& val);
        //Takes key, and value, emplaces node at key.
        //O(log N) average, O(N) worst case.

    void clear() { root.reset(); }
        //Requires nothing, removes all node from tree
        //shared_ptrs do the deleting for us.
        //O(N) time.

    int size() { return num_nodes; }
        //Requires nothing, returns size of tree
        //O(1)

private:

    //==============================================//
    //           Implementation Details 
    //==============================================//

    std::shared_ptr<TreeNode<K,V>> root;
        //Templated root node

    int num_nodes;
        //Total number of nodes

    std::shared_ptr<TreeNode<K,V>> find_node(const K& key);
        //Returns node associated with key,
        //nullptr if doesn't exist, O(log n).

    std::shared_ptr<TreeNode<K,V>> insert_node(const K& key, const V& val);
        //Returns node that was inserted.
        //O(log n).

    static bool sort_comp(std::shared_ptr<TreeNode<K,V>> a, std::shared_ptr<TreeNode<K,V>> b) {return *a < *b;};
        //Requires two node pointers.
        //Operator< is already overloaded for Node, this function
        //dereferences the pointers and compares. Useful for
        //std::sort.
};
#endif
