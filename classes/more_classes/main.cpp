// 
// 
//  exploring more aspects of classes in depth
//
/**
 *  -   look at constructors
 *          -   copy 
 * 
 *          -   move
 *  -   look at destructors and passing objects into        
 *      functions
 * 
*/
//
//

//
#include "point.h"

// checking point
void printPoint(Point point) {
    std::cout << "From within function" << std::endl;
    std::cout << point << std::endl;
}

//
int main() {

    // testing the class/constructors
    Point point{};
    std::cout << point << std::endl;

    // implicit operator test
    Point point2 = 50;
    std::cout << point2 << std::endl;

    // testing the copy constructor
    Point point3{point2};
    std::cout << point3 << std::endl;

    // passing an object to a function by value
    std::cout << "Passing to function" << std::endl;
    printPoint(point3);
    
    // move constructor test
    

    //  
    return 0;

}