// classes - exploring the basics of classes and how to implement them
/**
 *  -   exploring classes    
 *  -   more details can be found in the header file
 * 
*/
//--------------------------------------------------------------

// include the classs
#include "class.h"

//

int main() {
    
    // testing our class
    // create an empty constructor and print it
    Vector a;
    a.log();

    // testing the class and it's other operations
    // the x, y, z axis respectively
    Vector x = Vector(1.0, 0.0, 0.0);
    Vector y = Vector(0.0, 1.0, 0.0); 
    Vector z = Vector(0.0, 0.0, 1.0);         

    //
    std::cout << std::endl;

    // cross product of two axis gives the left over axis
    Vector xCrossY = x.cross(y);
    x.log();
    y.log();
    xCrossY.log();

    //
    std::cout << std::endl;    

    // dot product of two normalised vectors
    Vector b = Vector(5.0, 10.0, 9.0);
    Vector c = Vector(3.0, -7.0, 13.0);
    
    //
    std::cout << "Before normalising" << std::endl;
    b.log();
    c.log();

    std::cout << "After normalising" << std::endl;    
    b.normalise();
    c.normalise();
    b.log();
    c.log();

    //
    std::cout << "Dot product" << std::endl;
    double dot = b.dot(c);
    std::cout << dot << std::endl;

    //
    std::cout << "Press any key to continue..." << std::endl;    
    std::cin.get();

    //
    return EXIT_SUCCESS;

}