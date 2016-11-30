#ifndef C_NODE
#define C_NODE

#include <memory>

template<typename KEY, typename VALUE>
struct C_Node {

    KEY key;
    VALUE value; 

    std::shared_ptr<C_Node<KEY,VALUE> > left;
    std::shared_ptr<C_Node<KEY,VALUE> > right;

    C_Node(KEY k_in, VALUE v_in) 
        : key(k_in), value(v_in) {} 

    bool operator<(const C_Node &other) {
        return key < other.key;
    }
    
};
#endif
