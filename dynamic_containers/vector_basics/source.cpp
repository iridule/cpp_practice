// dynamic containers - vectors
// exploring dynamic containers - vectors
/**
 *  -   vectors - most useful container (quote Bjarne S himself)
 * 
 *  -   vectors:
 *          -   provide sequence of elements of a type
 *          -   you can extend it with push_bacak
 *          -   and use subscript [] to get elements
 *          -   handles out-of-range values
 *          -   size & memory are handled
 * 
 *  -   to do anything useful in computation    
 *      - one needs to store data
 *  -   vectors are sequence of indexed elements
 * 
 *  -   it is: convinient and flexible
 *  -   vector takes care of dynamic memory for you
 *  
 *  -   understanding vectors will allow us to
 *      grasp the way memory works
 *  -   thus - look into the design of data-structures  
 *      and containers
 *  
 *  -   to understand low-level memory access
 *      one could design their own data-structure
 *      and containers
 *  
 *  
*/
//--------------------------------------------------------------

//
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

//--------------------------------------------------------------
// useful helpers 
// print out the content of vector
void print1DVector(std::vector <int> vector);

// fill & print a 2D vector
void fill2DVector(std::vector <std::vector<int>> &vector, int a, int b, int value);
void print2DVector(std::vector <std::vector<int>> &vector);

// fill a 3D vector
// void fill3DVector(std::vector<std::vector<int>> vector);
// void print3DVector(std::vector<std::vector<int>> vector);

//--------------------------------------------------------------
int main() {

    // exploring vectors and functionality
    std::cout << "\nExploring vectors and dynamic structures\n" << std::endl;

    // declaring a vector
    /**
     *  -   the following is a vector of size 8
     *  -   it can be declared and values allocated right away
    */
    //
    std::vector <int> exampleVector = {
        2, 7, 1, 0, 1, 9, 9, 5
    };

    // init empty vector - initialised to all 0
    std::vector <int> emptyVector(6);

    std::cout << "Traverse and print out the values of the vector: " << std::endl;
    print1DVector(exampleVector);

    // elements can not be assigned out of range
    /**
     *  -   new elements added with push_back
     *  -   "recreate" the vector and allocate more memory
     *      for data
    */
    //
    std::cout << std::endl;
    emptyVector.push_back(1);

    // multidimensional vectors
    /**
     *  -   vectors may also contain other
     *      vectors - which contain instances
     *      of the underlying data type
     * 
     *  -   they must be filled with a vector of
     *      the inner data type - at every level
     *  
     *  -   eg:
     *      -   2d vector: std::vector <vector<int>> v2d;
     *      -   3d vector: std::vector <vector <vector<int> >> v3d;
     *      -   4d vector: std::vector <vector <vector <vector<int> >>> v3d;
     *      -   nd vector: do above steps for n - 1 depth - last vector holds
     *                     the value
    */
    //
    std::vector <std::vector<int>> example2dVector;
    
    // 10 by 10 vector filled with 1
    fill2DVector(example2dVector, 3, 3, 1);

    // print 2d vector
    std::cout << "Printing the values of 2D vector" << std::endl;
    print2DVector(example2dVector);

    // can use enum to specify verbose code
    return EXIT_SUCCESS;
}
//

//--------------------------------------------------------------
// implemenation of the helper functions

//
void print1DVector(std::vector <int> vector) {
    
    // vectors have size built in and refreshed
    // we can use the size() method to traverse it
    std::string outString = "";
    for (int i = 0; i < vector.size(); i++) 
        outString += " " + std::to_string(vector.at(i)) + " ";

    std::cout << outString << std::endl;

}

// the following function fills a 2D vector
// take vector by reference
void fill2DVector(std::vector <std::vector<int>> &vector, int a, int b, int value) {

    // to fill a 2d vector we need to instance an empty 
    // vector that the first one contains
    for (int i = 0; i < a; i++) {

        // create an empty vector to push_back into
        // the vector of vectors
        std::vector <int> temp;

        // process that vector - add elements to it
        for (int i = 0; i < b; i++) 
            temp.push_back(value);

        // push resulting vector into to-fill vector
        vector.push_back(temp);
            
    }

}

// print 2d vector - into multiple lines
void print2DVector(std::vector<std::vector<int>> &vector) {
    
    // iterate through the element and concat to string 
    // string to store message
    std::string message;

    std::cout << "[" << std::endl; 

    // reduced loop
    for (std::vector<int> &inner : vector) {

        // reset
        message = " [ ";

        // go through each element of that vector
        // get the value and print it out
        for (int elem : inner) {
            message += std::to_string(elem) + " ";   
        }

        // print that string of values
        std::cout << message + "]" << std::endl;

    }

    std::cout << "]\n" << std::endl;

}