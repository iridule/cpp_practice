// pointers and objects

#include <iostream>
#include <string>
#define log(x) std::cout << x << std::endl;

//
class Object {
    public:
        Object(int _a): a{_a}{}
        void print() { std::cout << a << std::endl; }    
        void somesString() { std::cout << "test string" << std::endl; } 
        void printThisString() { this->somesString(); }
    private:
        int a; 
};

//
int main() {

    //
    log("Creating an object");
    Object a{1};
    a.print();

    log("Creating a pointer to an object");
    Object *pa = &a;    
    log(pa);    

    // printing the value using the arrow pointer
    pa->print();

    // using the "this pointer" to print somethin   
    pa->printThisString();

    Object *pda;

    pda = new Object{5};
    pda->print();

}