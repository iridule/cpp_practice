//functions - introduction to functions
//the header file containing our functions - interface of our application
/**
 *  -   the functions will be declared here
 *  -   we only need to know the arguments that are useful for a function   
 *  -   we don't really need to know how a function works - unless we are
 *      implementing that function ourselves
 *  -   so an ideal - and the best practice is to keep functions in the header file
 *          
 *  -   the example below sets up an interface/declarations of 
 *      some print functions/mathematical functions
 *      
*/
//--------------------------------------------------------------

//
#include <iostream>
#include <string>
#include <cmath>
#include <array>

//function prototypes
/**
 *  -   prototypes:
 *          -   declarations of functions
 *          -   inits a new name into scope with type
 *          -   we use the keyword "extern" when we wish    
 *              to implemenet the function elsewhere but
 *              set aside a name & tell compiler how to do something
 * 
 *  -   overloaded functions:
 *          -   multiple definitions for the same function  
 *              in the same scope.
 *          -   these must differ in the argument types
 *              and the number of arguments for the function
 *          -   we cannot overload functions with just 
 *              a difference in return type.
 * 
*/

//sum
int sum(int a, int b);
double sum(double a, double b, double c);

//square
int square(int a);
double square(double a);

//distance 
int distance(int a, int b, int c, int d);
double distance(double a, double b, double c, double d, double e, double f);

//divisiblity
bool isDivisible(int n, int m);

//print
//using the extern keyword to declare
void printString(std::string a);

//types of argument passing into functions
/**
 *  -   there are multiple ways to pass objects
 *      into a function - for it to use
 *  -   the use of each depends on the situation
 *  
 *  -   these are:
 *      -   passing by value    
 *      -   passing by const reference
 *      -   passing by reference
 *      -   passing by pointer
 *      
 *  -   passing by value:
 *      -   passing the literal identifier
 *      -   this creates a local copy of the function   
 *      -   useful for a small task and passing very small      
 *          functions
 * 
 *  -  passing by const reference:
 *      -   giving the memory address of the        
 *          object - therefore the reference to
 *          that objecr
 *      -   this is not overwritable and just acesses
 *          the desired value
 *      -   use when we want to pass large
 *          data structures but we don't        
 *          want to modify them or create   
 *          un-needed copies of memories     
 * 
 *  -   passing by std reference:
 *      -   same as above except we can modify the
 *          object that this refers to
 *      -   use when passing values to function
 *          that we want to modify - eg: an array
 *  
 *      -   look at pointers to see why and when
 *  -   pointer
 *      -   this is up to the user discretion
 *          one should use this
 *      -   ideally when we are moving where
 *          the pointer should refer this would be 
 *          useful
 * 
*/
//

//passing by value - here we swap two variables
//we are only passing small values into this function so directly pass 
void swapInts(int a, int b);

//pass by reference
/**
 *  -   this function sums an array by reference
 *  -   we do not need the whole array's copy to sum it
*/
int sumArray(std::array <int, 10> &arr);


//pass by const reference
/**
 *  -   this accepts an element by const reference
 *      -   it will just print values from that object
 *          so it doesn't need to copy the array
 *          or have a modifiable reference
*/
std::string printArray(const std::array <int, 10> &arr);
