#include <iostream>
#include "BinaryTree.cpp"
#include <ctime>
#include <set>

using namespace std;

int main() {
    BinaryTree<int,std::string> binary_tree;
    binary_tree.generate_tree(1000000, 5000000);

    auto v = binary_tree.get_nodes();

    binary_tree.clear();
    set<int> to_test;

    cout << "Beginning Benchmark " << endl;

    clock_t start;
    clock_t end;
    double duration;

    start = clock();
    for(auto &i : v) {
        to_test.insert(i->key);
    }
    end = clock();
    duration = (end - start)/ (double) CLOCKS_PER_SEC;
    cout << "STL Finished in a time of " << duration << endl;

    BinaryTree<int, std::string> b_tree;
    std::string s = "";
    start = clock();
    for(auto &i :v) {
        b_tree.insert(i->key,s);
    }
    end = clock();
    duration = (end - start)/ (double) CLOCKS_PER_SEC;
    cout << "Your implementation finished in a time of " << duration << endl;

    return 0;
}
