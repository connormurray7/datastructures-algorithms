#ifndef BUCKET_H
#define BUCKET_H

template<typename T>
struct HashSetNode {

    HashSetNode(T& val_in) : val(val_in) {}

    T val;
    HashSetNode* next;
}

template<typename T>
class Bucket {
public:
    Bucket(HashSetNode& n) {
        node = &n;
    }

    void add(T& val) {
        if(isEmpty()) {
            node = &HashSetNode(val);
            return;
        }
        HashSetNode* n = node;
        while(n->next) {
            n = n->next;
        }
        n->next = &HashSetNode(val);
    }

    void remove(T& val) {
        if(isEmpty()) {
            return;
        }
        HashSetNode* cur = node;
        HashSetNode prev = nullptr;
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

    bool isEmpty() {
        return node == nullptr;
    }

private:
    HashSetNode* node;
}

#endif
