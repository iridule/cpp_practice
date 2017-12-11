//
//
// memory, pointers, freestore drill
//
//

//
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

// print
void print(std::string string) { std::cout << string << std::endl; }
void print(int number) { std::cout << number << std::endl; }
void print(int *pointer) { std::cout << pointer << std::endl; }
void printv(int *pointer) { std::cout << *pointer << std::endl; }
void nl() { std::cout << "\n"; }

// print the values of an array to the ostream
std::ostream& print_array10(std::ostream &os, int *array) {
    os << "[";
    for (int i = 0; i < 10; i++) 
        os << " " << array[i];
    os << " ]\n";
    return os;
}

//
std::ostream& print_array(std::ostream &os, int *array, int n) {
    os << "[";
    for (int i = 0; i < n; i++) 
        os << " " << array[i];
    os << " ]\n";
    return os;
}

//
std::ostream& print_vector(std::ostream &os, std::vector<int> *vector) {
    os << "[";
    for (int i = 0; i < (*vector).size(); i++) 
        os << " " << (*vector)[i];
    os << " ]\n";
    return os;
}

//
int main() {

    // array and allocation
    // allocating ten ints on the free store
    // printing the ints to the console
    int *ints = new int[10];
    std::cout << "[";
    for (int i = 0; i < 10; i++) 
        std::cout << " " << ints[i];
    std::cout << " ]\n";

    //
    // std::cout is an iostream object so we can pass
    // it into the function
    //
    print_array10(std::cout, ints);
    nl();

    // deallocate the array
    delete[] ints;

    // allocating an array of ints and intialising them
    ints = new int[10];
    for (int i = 0; i < 11; i++) 
        ints[i] = 100 + i;
    print_array(std::cout, ints, 10);
    delete[] ints;

    //
    ints = new int[11];
    for (int i = 0; i < 11; i++) 
        ints[i] = 100 + i;
    print_array(std::cout, ints, 11);
    delete[] ints;

    // allocating array of 20 int
    ints = new int[20];
    for (int i = 0; i < 20; i++) 
        ints[i] = 100 + i;
    print_array(std::cout, ints, 20);
    delete[] ints;
    nl();

    // vectors and allocation
    // doing the above with vectors
    std::vector <int> vector;
    for (int i = 0; i < 10; i++) 
        vector.push_back(100 + i);
    print_vector(std::cout, &vector);

    //
    vector.clear();
    for (int i = 0; i < 11; i++) 
        vector.push_back(100 + i);
    print_vector(std::cout, &vector);

    //
    vector.clear();
    for (int i = 0; i < 20; i++) 
        vector.push_back(100 + i);
    print_vector(std::cout, &vector);
    nl();

    // pointers
    int number = 7;
    int *p1 = &number;
    nl();
    print(number);
    print(p1);

    // array of numbers    
    int numbers[7];
    for (int i = 0; i < 7; i++) 
        numbers[i] = std::pow(2, i);
    int *p2 = numbers;
    nl();
    print_array(std::cout, numbers, 7);
    print(p2);

    // passing pointers around
    int *p3 = p2;
    p2 = p1;
    p3 = p2;
    
    //
    nl();
    printv(p1);
    print(p1); 
    printv(p2);
    print(p2);
    nl();

        
    //
    int numbers2[10];
    for (int i = 0; i < 10; i++) 
        numbers2[i] = std::pow(2, i);
    p1 = numbers2;
    print_array(std::cout, numbers2, 10);

    //
    int numbers3[10];
    p2 = numbers3;

    // copy the values
    for (int i = 0; i < 10; i++)
        p2[i] = p1[i];        
    print_array(std::cout, p2, 10);    
    nl();

    // doing the above with a vector
    std::vector <int> vector2;
    for (int i = 0; i < 10; i++) 
        vector2.push_back(std::pow(2, i));
    std::vector <int> *vp1 = &vector2;
    print_vector(std::cout, &vector2);

    //
    std::vector <int> vector3;
    std::vector <int> *vp2 = &vector3;
    for (int i = 0; i < vector2.size(); i++)
        (*vp2).push_back((*vp1)[i]);
    print_vector(std::cout, &vector3);    

    //
    return 0;
}