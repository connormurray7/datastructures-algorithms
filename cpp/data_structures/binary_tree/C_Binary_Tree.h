#ifndef C_BINARY_TREE
#define C_BINARY_TREE

#include "C_Node.h"
#include <vector>

/* Standard Binary Tree Implementation
 * with utility functions to test your
 * implementations. Also includes benchmarking
 * functions to test against the stl and your
 * code.
 */

template<typename KEY, typename VALUE>
class C_Binary_Tree {

    typedef std::shared_ptr<C_Node<KEY,VALUE>> nodeptr_t;
        //Typedef that will be used throughout the class
        //shared_ptr was chosen over standard pointers

    typedef C_Node<KEY,VALUE> node_t;
        //Typedef for a templated node.

public:

    //==============================================//
    //        Constructors and Destructor
    //==============================================//

    C_Binary_Tree();
        //Requires nothing, creates empty BT

    C_Binary_Tree(C_Binary_Tree<KEY,VALUE> &tree_in);
        //Requires a vector of node pointers

    ~C_Binary_Tree();
        //Requires nothing, does nothing, shared_ptrs
        //delete the data for us.

    //==============================================//
    //           Standard map functions
    //==============================================//

    nodeptr_t find(KEY k);
        //Requires the key, and returns a pointer
        //to the node.
        //O(log N) average, O(N) worst case

    nodeptr_t operator[](KEY k) { return find(k); }
        //Overloaded operator that calls find.

    void insert(KEY k, VALUE v);
        //Takes a pointer to the node and inserts
        //at correct position.
        //O(log N) average, O(N) worst case.

    bool erase(KEY k);

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
        //Operator< is already overloaded for C_Node, this function
        //dereferences the pointers and compares. Useful for
        //std::sort.
};
#endif
