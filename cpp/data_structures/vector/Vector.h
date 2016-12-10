#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

template<typename T>
class Vector {
public:

    //==============================================//
    //        Constructors and Destructor
    //==============================================//

    Vector();
    //Requires nothing, creates empty Vector

    Vector(const Vector<T>& other);
    //Copy constructor, shallow copy

    ~Vector();
    //Requires nothing, does nothing, rule of zero

    //==============================================//
    //           Standard functions
    //==============================================//

    T& operator[](unsigned int idx) const;
    //Requires a valid index
    //O(1)

    T& at(unsigned int idx) const;
    //Requires a valid index
    //Else throws out_of_range exception
    //O(1)

    T& front() const;
    //Requires nothing
    //Returns a reference to the first element
    //O(1)

    T& back() const;
    //Requires nothing
    //Returns a reference to the last element
    //O(1)

    bool empty() const;
    //Requires nothing
    //True if container is empty.

    unsigned int size() const;
    //Requires nothing
    //Returns number of elements in vector
    //O(1)

    void push_back(const T& val);
    //Requires nothing, appends to vector.
    //Amortized O(1).

    void pop_back();
    //Requires nothing, removes last element
    //if it exists.
    //O(1).

    void resize(unsigned int num);
    //Requires nothing. Changes capacity
    //of vector. If num < capacity, then
    //it will remove the elements at the
    //end of the vecotr.

    void resize(unsigned int num, const T&);
    //Requires nothing. Changes capacity
    //of vector. If num < capacity, then
    //it will remove the elements at the
    //end of the vecotr.

private:

    unsigned int capacity = 1;
    //Size of the underlying array

    unsigned int num_elements = 0;
    //Number of elements in container.

    void grow();
    //Doubles the size of the
    //underlying array.

    bool full();
    //Returns true if num_elements
    //equals the capacity.

    T* arr;
    //Underlying array.
};
#endif
