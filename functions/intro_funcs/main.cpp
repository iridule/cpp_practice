//functions - introduction
/**
 *  
 *  -   In c++: functions are grouped/named segements of code
 *      -   these can perform individual tasks
 * 
 *  -   structure/syntax
 *      
 *      returnType identifier( parameters ) {
 *          //body of the function
 *          return returnType;
 *      }
 *      
 *  -   functions - are split into declarations
 *      and defines
 * 
 *      -   the declaration tells compiler
 *          how to call the functions 
 * 
 *      -   the definition is the body
 *          of the function that contains
 *          the code
 * 
 *      -   keeping these seperated into header files
 *          and implementation files - linked to the header 
 *          encourages clean practice.
 * 
 *  -   the usefullness of functions:
 *      -   keeps program logic seperated 
 *      -   program text is clearer
 *      -   modularisatio
 *      -   easier to track what seperate
 *          components are doing
 *      -   ease testing
 *      
 *  -   functions are useful for functional         
 *      programming - where in they always
 *      peform the task we give them - 
 *      they have a determinable output.
 *  
 *  -   here we will test our functions
*/
//--------------------------------------------------------------

//import the library we made
#include "functions.h"

//
int main() {

    //testing the functions we wrote
    /**
     *  -   the functions we wrote in the header
     *      have multiple versions - prototypes 
     *      that are implemented:
     *      -   for example:
     *              the distance() function has an integer
     *              variant for 2d points and a double variant
     *              for 3d points - this is overloading.
    */
    printString("Exploring functions...");
    //

    //sum
    int a = 10;
    int b = 25;
    int sumInt = sum(a, b);

    printString("Sum -> a = 10, b = 25: " +  std::to_string(sumInt));

    //works with doubles too
    double c = 10058.5375;
    double d = 47595748.9;
    double e = 0.55553510;
    double sumDbl = sum(c, d, e);

    printString("Sum -> c = 10058.5375, d = 47595748.9, e = 0.55553510: " + std::to_string(sumDbl));

    //distance function
    //int distance between two integer locations
    int x1 = 0, x2 = 0;
    int y1 = 100, y2 = 100;
    int intDist = distance(x1, x2, y1, y2);

    printString("Distance between <0,0> & <100, 100>: " + std::to_string(intDist));

    //double distance between two 3d coords
    double xd1 = 0.0, yd1 = 0.0, zd1 = 100;
    double xd2 = 100.0, yd2 = 50.0, yd3 = 300;
    double doubleDist = distance(xd1, yd1, zd1, xd2, yd2, yd3);
    
    printString("Distance between <0, 0, 100> & <100, 50, 300> :" + std::to_string(doubleDist));

    //swap two values - pass to function by name
    //
    printString("A: " + std::to_string(a) + " B: " + std::to_string(b));
    swapInts(a, b);
    printString("A: " + std::to_string(a) + " B: " + std::to_string(b));
    printString("You can see they don't swap - all is copied internally");

    //iterate through an array and sum elements
    //create a reference to that array
    std::array<int, 10> arr = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    //refs
    std::array<int, 10> &arrRef = arr;
    const std::array<int, 10> &constarrRef = arr;

    //pass to print with const ref
    printArray(constarrRef);

    //sum with normal ref
    int arraySum = sumArray(arr);

    //
    printString("Sum of array: " + std::to_string(arraySum));

    //
    return 0;
}
