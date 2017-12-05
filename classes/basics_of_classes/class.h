// classes - exploring the basics of classes and how to implement them
/**
 *      -   classes:
 *     
 *          -   user defined types - composed of built in types, user defined types
 *              and functions
 *          -   a class is split into its interface and the implementation
 *          
 *          -   the interface is the section of the class / the class members that  
 *              the user can interact with. 
 *              -   The interface defines the core functions that the user can access and operate on 
 *              -   this can also be thought of the PUBLIC sector of the class
 *              -    the members which are accessible outside of the scope of the class.
 *          
 *          -   the implementation are the members of the class which are not accessible
 *              -   the actual code/functionality is written   
 *              -   the functionality of the class should not be mutable by the user 
 *                  only the members that are useful for dealing with the data type t
 *                  that class represents
 * 
 *          -   constructor
 *              -   is the subroutine - with the same indentifier as the class
 *                  that is used to create an object of that type
 *              -   there is no return type
 *              -   classes must have an initialiser / empty constructor
 *                  if one doesn't exist - then it is created
 *  
 *      -   header file for the class
 *      -   the main skeleton of the class in created here then the rest of
 *          the functionality of the class is written in the class.cpp file
 *      
*/
//--------------------------------------------------------------
//

// 
#include <iostream>
#include <string>
#include <cmath>

//
class Vector {

    // 
    public:
        
        // an empty constructor must be created
        // the second is the constructor to initialise the values
        Vector();
        Vector(double a, double b, double c);

        // some functions for this class
        // this is a vector class so it would be useful 
        // to have vector methods
        Vector add(Vector &vector);
        Vector sub(Vector &vector);
        Vector normalise();
        double mag();        
        double dot(Vector &vector);
        Vector cross(Vector &vector);
        std::string toString();  
        void log();

    // 
    private:

        //
        double x;
        double y;
        double z;


};



