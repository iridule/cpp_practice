//
// exploring pointers with some example experiments
//

//
#include <iostream>
#include <string>

//
// some cpu task
//
void task(int a) {
    std::cout << "Inside function /wo pointer: " << a << std::endl;
    std::cout << "Inside function /wo pointer: " << &a << std::endl;    
    std::cout << "Inside function /wo pointer: " << &a << std::endl;        
    int *tp = &a;
    std::cout << "Inside function /wo pointer: " << &tp << std::endl;        
    int **tp2 = &tp;
    std::cout << "Inside function /wo pointer: " << tp2 << std::endl;       
    std::cout << "Inside function /wo pointer: " << &tp2 << std::endl;         
    std::cout << "Inside function /wo pointer double pointer deref: " << **tp2 << std::endl;    
}

// a task overload that requires a pointer
void task(int *pa) {
    std::cout << "Inside function /w pointer: " << pa << std::endl;
    std::cout << "Inside function /w pointer: " << &pa << std::endl;    
    std::cout << "Inside function /w pointer: " << *pa << std::endl;    
}


//
int main() {

    //
    //  declaring pointers
    //
    int a = 10;
    int *pa = &a;

    // outputting the pointer values

    //
    std::cout << "The value in variable a: " << a << std::endl;
    std::cout << "Direct address of a: " << std::hex << &a << std::endl; 
    std::cout << "The pointer to a - stores: " << std::hex << pa << std::endl;
    std::cout << "The pointer to a - stored value - *pointer to a " << *pa << std::endl;
    
    //
    task(a);
    task(&a);   

    //
    return 0; 

}
