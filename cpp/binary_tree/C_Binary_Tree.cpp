#include "C_Binary_Tree.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stack>
#include <queue>
#include <algorithm>

//  Constructors and Destructor  //

template<typename KEY, typename VALUE>
C_Binary_Tree<KEY,VALUE>::C_Binary_Tree() {
    root = nullptr;
    num_nodes = 0;
}

//Shallow copy for now.
template<typename KEY, typename VALUE>
C_Binary_Tree<KEY,VALUE>::C_Binary_Tree(C_Binary_Tree<KEY,VALUE> &tree_in) {
    auto data = tree_in.get_nodes();
    std::sort(data.begin(), data.end(),sort_comp);
    root = build_tree(data, 0, data.size());
}

template<typename KEY, typename VALUE>
C_Binary_Tree<KEY,VALUE>::~C_Binary_Tree() {}

//  Standard map functions  //
template<typename KEY, typename VALUE>
typename C_Binary_Tree<KEY,VALUE>::nodeptr_t C_Binary_Tree<KEY,VALUE>::find(KEY k) {
    auto ptr = root;
    while(ptr != nullptr && k != ptr->key) {
        ptr = (k < ptr->key) ? ptr->left : ptr->right;
    }
    return ptr;
}

template<typename KEY, typename VALUE>
void C_Binary_Tree<KEY,VALUE>::insert(KEY k, VALUE v) {
    nodeptr_t n = std::make_shared<C_Node<KEY,VALUE> >(node_t(k,v));
    if(!root) {
        root = n;
        return;
    }
    auto cur = root;
    auto last = cur;
    while(cur) {
        last = cur;
        cur = (n->key < cur->key) ? cur->left : cur->right;
    }
    if(n->key < last->key) {
        last->left = n;
    }
    else {
        last->right = n;
    }
}

//  Utility functions  //

template<typename KEY, typename VALUE>
void C_Binary_Tree<KEY,VALUE>::print_tree() {
    //Iterative function that prints the tree, run in O(n) time,
    //O(k) space where k is the depth of the tree.

    if(!root) {
        std::cout << std::endl;
        return;
    }

    std::ostringstream os;
    std::stack<nodeptr_t> s;
    s.push(root);
    nodeptr_t cur = root->left;

    while(!s.empty() || cur) {
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
        if(!s.empty()) {
            cur = s.top();
            s.pop();

            os << cur->key << " ";
            cur = cur->right;
        }
    }

    std::cout << os.str() << std::endl;
}

template<typename KEY, typename VALUE>
void C_Binary_Tree<KEY,VALUE>::generate_tree(int num, int max) {
    //Using an implementation similar to cplusplus.com

    auto gen_node = [](int max) { return std::make_shared<C_Node<int,VALUE>>((rand() % (max+1)),""); };

    srand(time(nullptr));

    std::vector<std::shared_ptr<C_Node<int,VALUE>> > vec;
    vec.resize(num,std::shared_ptr<C_Node<int,VALUE>>(nullptr)); //Don't need to waste time growing.

    //O(N) to generate the tree.
    for(int i = 0; i < num; ++i) {
        //Make a new node generated from a random function.
        vec[i] = gen_node(max);
    }

    //O(N Log N) to sort.
    std::sort(vec.begin(), vec.end(),sort_comp);

    //O(N Log N) to fill tree.
    root = build_tree(vec,0,num);

    num++; //temp to compile
    max++;
}

template<typename KEY, typename VALUE>
std::vector<typename C_Binary_Tree<KEY,VALUE>::nodeptr_t> C_Binary_Tree<KEY,VALUE>::get_nodes() {
    std::queue<nodeptr_t> q;
    std::vector<nodeptr_t> v;
    q.push(root);
    while(!q.empty()) {
        if(q.front()) {
            v.push_back(q.front());
            q.push(q.front()->left);
            q.push(q.front()->right);
        }
        q.pop();
    }
    return v;
}

//Private Member Functions

template<typename KEY, typename VALUE>
typename C_Binary_Tree<KEY,VALUE>::nodeptr_t //<-- return type is a nodeptr
C_Binary_Tree<KEY,VALUE>::build_tree(std::vector<nodeptr_t> &vec, int start, int end) {
    //This function is private, so we know that vec is sorted.
    if(end <= start) {
        nodeptr_t null_ptr;
        return null_ptr;
    }
    int mid = (start + end)/2;
    vec[mid]->left = build_tree(vec, start, mid);
    vec[mid]->right = build_tree(vec,mid+1,end);
    return vec[mid];
}
