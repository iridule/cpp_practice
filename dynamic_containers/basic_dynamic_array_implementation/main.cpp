//
//  understanding destructors/memory by creating basic dynamic array
//
//

//
//  including the header only hpp file
// 
#include "vector.hpp"

//
int main() {

    // instance a vector of length n
    Vector<int> test{};

    // testing - pushing back some values
    test.insert(0, 10);
    test.insert(1, 15);       
    test.push_back(10);
    test.print();     

    //
    int elem0 = test.at(0);
    int elem1 = test[1];
    std::cout << "Element at index 0: " << elem0 << std::endl;
    std::cout << "Element at index 1 - overloaded operator: " << elem1 << std::endl;    

    //
    std::cout << "Capacity of the vector " << test.get_size() << std::endl;
    std::cout << "Active elements total in the vector " << test.get_count() << std::endl;

    //
    Vector<int> test2{};
    test2 = test;

    std::cout << "Testing the '=' overloaded operator" << std::endl;
    test2.print();

    std::cout << "Popping last element" << std::endl;
    // test2.pop_back();
    // test2.print();

    //  
    return 0;

} 

