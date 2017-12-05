// a detailed example in class constructors/destructors and initialiser lists
/**
 *  
 *  -   constructors are class member functions
 *  -   they do not have a return type
 *  -   they are identified by the same name as the class itself
 *  
 *  -   constructors - take the blueprint that was defined by the class
 *      and produce an object
 *  -   constructors can have overloads so that we can defined more than one    
 *      way of creating an object 
 *  
 *  -   there are a few types of constructors - default, defined/overloaded and initialised
 *  -   default constructor
 *          -   when we declare an object of type x
 *          -   with this constructor there are no arguments 
 *          -   a default constructor is called - this sets the values of specific
 *              member/variables for the object
 *     
 *  -   defined/overloaded 
 *          -   constructor with arguments that set up and object such that
 *              the object has been intialised
 *          -   there are many ways to initialise an object
 *          -   for example a vector object could be initialised
 *              with 3 values for a 3d vectors, n values for an an dimensional  
 *              vector or copy a vector with another vector passed in as the
 *              argument
 *          -   overloaded constructors provide multiple ways to create the object
 *  
 *  -   initialised constructors
 *          -   simple overloaded constructors but the arguments are initialised
 *          -   if the user does not give arguments to the constructor the
 *              class will set these values
 * 
 *  -   multiple ways to initalise/call constructors
 *          -   Type t;
 *          -   Type t();
 *          -   Type t{};
 *          -   Type t = Type();
 *          -   Type t = {};
 *  
 *  -   destructors
 *          -   to conserve memory - all objects created must be destroyed
 *          -   the purpose of a destructor is to free the resources the object 
 *              was using
 *          -   if no destructor provided - the compiler sets an inline destructor  
 *              - "implicit destructor"
 *        
 *  -   note:
 *          -   inline function - the compiler places the declaration before 
 *              the point in code where function is called - exchange space for execution speed
 *              (good for small functions called repeatedly)
 *          -   virtual functions - functions to be redefined in an inheritance
 *              chain
 *          -   when pointing to a base class for derived class - the newly defined
 *              virtual func specific to the derived class can be used
 *             
 *  
*/
//--------------------------------------------------------------

//
#include "star.h"

// 
int main() {

    // create a star
    // indiviually assign the values with setter methods
    Star sun;
    sun.setName("Sol");
    sun.setPositionX(0.0);
    sun.setPositionY(0.0);
    sun.setPositionZ(0.0);            
    sun.print();

    // create a star with a constructor
    Star alphaCentauri {3.205, -3.014, 0.035, 85397, "Alpha Centauri"};
    alphaCentauri.print();

    // create a copy of a object with the copy constructor
    // since in this case the star has the position but different radius 
    // and name - we have to set that after
    Star betaCentauri {alphaCentauri};
    betaCentauri.setName("Beta Centauri");
    betaCentauri.setRadius(4176);
    betaCentauri.print();

    //
    return 0;

}