//
//
//  dynamic vector header class
//
/**
 *  -   this vector class is infact a template class
 *  -   not actual compiled code but a template for the compiler    
 *      to generate classes from when the code is compiled
 *  -   therefore the rule is:
 *          -   the header file has the "data structure"    
 *              (the structure where the algorithms rest)
 *          -   if seperation of files is needed - then one can
 *              declare the .h and .cpp files for the algorithms
 *              they wish to implement
 * 
*/
//
//
//

//
//
#include <iostream>
#include <cmath>

//
#ifndef VECTOR_H
#define VECTOR_H

//
template <class T> 
class Vector {

    //
    public:

        // constructors/destructors
        Vector();
        Vector(unsigned int _size);
        Vector(const Vector<T> &vector);
        ~Vector();

        // capacity
        void resize();
        int get_size() const;
        int get_count() const;

        // element access/assing
        T at(int index);
        T operator[] (int index) const;
        Vector<T> operator= (const Vector<T> &vector);

        // modify
        void insert(unsigned int index, T t);
        void push_back(T t);
        void pop_back();
        void clear();
        
        // extras
        void print();   
        void copy(const Vector<T> &vector);

    //
    private:

        //
        unsigned int count;
        unsigned int size;  
        unsigned int minSize;
        T *buffer;
        
        
};


//
// the implementation code for the vector goes here
//

// constructors
template <class T> 
Vector<T>::Vector() 
:count{0}, size{0}, minSize{1}, buffer{nullptr} 
{}

//
template <class T>
Vector<T>::Vector(unsigned int _size) {
    size = _size;
    buffer = new T[size];
    for (int i = 0; i < size; i++) 
        buffer[i] = T{};
    count = size;
}

// copy constructor
template<class T>
Vector<T>::Vector(const Vector<T> &vector) {
    copy(vector);
}

// delete/deallocate the buffer memory
// must be careful of nullptr
template <class T>
Vector<T>::~Vector() {
    if (buffer != nullptr) 
        delete[] buffer;
}

// capacity
// resize array - deal with size = 0 - return 1 as the max instead
template <class T>
void Vector<T>::resize() {
    
    size = std::max(minSize, size * 2);
    T *array = new T[size];
    
    for (int i = 0; i < count; i++) {
        array[i] = buffer[i];
    }
        
    if (buffer != nullptr) delete[] buffer;
    buffer = array;

}

// size - size of the vector - not excluding empty elements
template <class T>
int Vector<T>::get_size() const {
    return size;
}

// count - number of active elements
template <class T>
int Vector<T>::get_count() const {
    return count;
}

// element access/assignment
//
template <class T>
T Vector<T>::at(int index) {
    if (index < 0 || index > size) 
        std::cout << "Index out of bounds" << std::endl;
    else
        return buffer[index];
}

//
template <class T>
T Vector<T>::operator[] (int index) const {
    if (index < 0 || index > size) 
        std::cout << "Index out of bounds" << std::endl;
    else
        return buffer[index];
}

// "=" operator - must check if not the same
template <class T>
Vector<T> Vector<T>::operator= (const Vector<T> &vector) {
    if (this != &vector) {
        if (buffer != nullptr) delete[] buffer;
        copy(vector);
    } else {
        return *this;
    } 
}

// modification
//
template <class T>
void Vector<T>::insert(unsigned int index, T t) {
    
    //
    if (index < 0 || index > size) 
        std::cout << "Index out of bounds" << std::endl;

    // shifting the array to resize it
    if (count == size) resize();

    // add the element at the specified place
    buffer[index] = t;
    count++;
    
}   

// get the size of the other and copy over the elements
// with a new buffer
template <class T>
void Vector<T>::copy(const Vector<T> &vector) {
    count = size = vector.get_count();
    buffer = (size == 0) ? nullptr : new T[size];
    for (int i = 0; i < count; i++)
        buffer[i] = vector[i];
}

//
template <class T>
void Vector<T>::push_back(T t) {
    insert(count, t);
}

// pop back
// a question - is this a particularly heavy implementation
// 
template <class T>
void Vector<T>::pop_back() {
    T *array = new T[count - 1];
    for (int i = 0; i < count - 1; i++) 
        array[i] = buffer[i];
    if (buffer != nullptr) 
        delete[] buffer;
    buffer = array;
}

// 
template<class T>
void Vector<T>::clear() {
    if (buffer != nullptr)
        delete[] buffer;
    size = count = 0;
    buffer = nullptr;
}

// extras
//  
template <class T>
void Vector<T>::print() {
    for (int i = 0; i < count; i++)
        std::cout << buffer[i] << " ";
    std::cout << std::endl;
}

//
#endif