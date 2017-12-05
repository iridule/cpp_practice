// 
//
//  -   implementing a basic class skeleton
//  -   more detailed explanation will be in   
//
//

//
#include <iostream>

//
#ifndef POINT_H
#define POINT_H

//
class Point {

    //
    public:
        
        // create the basic constructors
       
        // constructor - notes
        // the following is also applicable to copy and move constructors
        /**
         * 
         *  -   constructor called with no arguments
         *  -   class is DefaultConstrucible is it has a public def cons
         *  
         *  -   implicitly-declared default constructor
         *          -   constructor with empty body, initializer and parameters
         *          -   compiler defined constructor
         *          -   if no constructor declared the compiler provides one
         *          -   the "default" keyword - explicitly forces compiler to create def cons
         *          
         *  -   implicitly-defined default constructor     
         *          -   non deleted cons
         *          -   defined by the compiler
         *          -   definition - empty body and init list
         *          -   called by base members and derived classes
         * 
         *  -   deleted, implicitly-declared default
         *          -   if def constructor - set to/is "delete/undefined"
         *          -   this is when:
         *                  -   T has &T (reference type) without default init
         *                  -   T has const member - w/ no user defined def or init list
         *                  -   T has a member with delted default constructor
         * 
         *  -   trivial default constructor
         *          -   trivial means performs no action
         *          -   cons is trivial when:
         *                  -   no user provided cons
         *                  -   no virtual member function/base class   
         *                  -   no non-static(static means only accessible in the current file) 
         *                      members with default init list
         * 
        */
        //

        // this is a user defined empty default constructor
        // no parameters/body
        Point();

        // copy construtor
        /**
         *  -   declared/used/called when another object of the same type is created
         *      as a "copy" of another one.
         *  -   called when:    
         *          -   object of class returned by value
         *          -   object of class passed to func by value
         *          -   object constructed based on object of the same class
         *          -   generating temporary objects
         *  -   the compiler generates one if there is none - default 
         *      copy constructor
         * 
        */
        Point(const Point &point);

        // move constructor
        // Point();

        // copy initialisation
        // use assigment operator to init spec members with the same value
        // to stop this being used - call explicit
        Point(int v);

        // some helper functions
        // friend allows ostream to access the members here
        // we are overloading the ostream to output values from this class
        friend std::ostream& operator<< (std::ostream &ostream, const Point &point);


    private:
    //

        //
        int x;
        int y;

        // refernce type
        // reference types are a replacement for pointers
        // if we wish to use them
        // int& reference;

};

#endif