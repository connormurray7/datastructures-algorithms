#include "Vector.cpp"
#include <iostream>

int main() {
    Vector<int> v;
    v.push_back(5);
    v.push_back(6);

    std::cout << v[0] << std::endl;
    std::cout << v[1] << std::endl;

    return 0;
}
