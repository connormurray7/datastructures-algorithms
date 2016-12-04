#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector {
public:

    //==============================================//
    //        Constructors and Destructor
    //==============================================//
    
    Vector();
        //Requires nothing, creates empty Vector
    
    Vector(Vector<T> &vector_in);
        //Copy constructor, shallow copy
        
    ~Vector();
        //Requires nothing, does nothing, rule of zero
    
    //==============================================//
    //           Standard functions
    //==============================================//
    
    T operator[](int idx);
        //Requires a valid index
        //O(1)
        
    T at(int idx);
        //Requires a valid index
        //Else throws out_of_range exception
        //O(1)

    T* front();
        //Requires nothing
        //Returns a reference to the first element
        //O(1)

    T* back();
        //Requires nothing
        //Returns a reference to the last element
        //O(1)

    bool empty();
        //Requires nothing
        //True if container is empty.
    
    unsigned int size();
        //Requires nothing
        //Returns number of elements in vector
        //O(1)

    void push_back(T val);
        //Requires nothing, appends to vector.
        //Amortized O(1).
    
    void pop_back();
        //Requires nothing, removes last element
        //if it exists.
        //O(1).
        
    void resize(int num);
        //Requires nothing. Changes capacity
        //of vector. If num < capacity, then
        //it will remove the elements at the 
        //end of the vecotr.
    
private:

    T[] arr;
        //Underlying array.
    
    int capacity = 1;
        //Size of the underlying array
    
    int num_elements = 0;
        //Number of elements in container.
    
    void grow();
        //Doubles the size of the 
        //underlying array.
    
    bool full();
        //Returns true if num_elements
        //equals the capacity.
};
#endif
