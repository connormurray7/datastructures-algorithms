#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Node.h"
#include <vector>

/* Standard Binary Tree Implementation
 * with utility functions to test your
 * implementations. Also includes benchmarking
 * functions to test against the stl and your
 * code.
 */

template<typename K, typename V>
class BinaryTree {

    typedef std::shared_ptr<Node<K,V>> nodeptr_t;
        //Typedef that will be used throughout the class
        //shared_ptr was chosen over standard pointers

    typedef Node<K,V> node_t;
        //Typedef for a templated node.

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
    //           Standard map functions
    //==============================================//

    nodeptr_t find(K k);
        //Requires the K, and returns a pointer
        //to the node.
        //O(log N) average, O(N) worst case

    nodeptr_t operator[](K k) { return find(k); }
        //Overloaded operator that calls find.

    void insert(K k, V v);
        //Takes a pointer to the node and inserts
        //at correct position.
        //O(log N) average, O(N) worst case.

    bool erase(K k);

    void clear() { root.reset(); }
        //Requires nothing, removes all node from tree
        //shared_ptrs do the deleting for us.
        //O(N) time.

    int size() { return num_nodes; }
        //Requires nothing, returns size of tree
        //O(1)


    //==============================================//
    //             Utility Functions
    //==============================================//

    void print_tree();
        //Requires nothing, prints the tree
        //In order.
        //O(N) time, O(K) (where K is the
        //depth of the tree) space.

    void generate_tree(int n, int max);
        //Requires nothing, generates a tree
        //of size n, with a range of integers
        //from 0 to max. Uses rand() to generate
        //the integers with a seed from the current
        //time from your cpu clock.
        //O(N Log N) time.

    std::vector<nodeptr_t> get_nodes();
        //Requires nothing, returns all of
        //the nodes of the tree.
        //O(N) time, space

private:

    nodeptr_t root;
        //Templated root node

    int num_nodes;
        //Total number of nodes

    nodeptr_t build_tree(std::vector<nodeptr_t> &vec, int start, int end);
        //Requires a vector of node pointers
        //Private function to do the actual building of the tree.

    static bool sort_comp(nodeptr_t a, nodeptr_t b) {return *a < *b;};
        //Requires two node pointers.
        //Operator< is already overloaded for Node, this function
        //dereferences the pointers and compares. Useful for
        //std::sort.
};
#endif
