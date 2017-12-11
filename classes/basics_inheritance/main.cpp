// 
// basics of inheritance
// 

//
#include <iostream>
#include "parent.h"
#include "child.h"

//
int main() {

    //
    std::cout << "Basics of inheritance" << std::endl;
    Parent parent;
    parent.sayThing();
    Child child;
    child.sayThing();

    //
    return 0;

}