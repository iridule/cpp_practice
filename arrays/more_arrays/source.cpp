//more types of array usage
/*
*   -   exploring array memory
*   -   exploring multidimensional arrays
*   -   "psuedo" multidimensional arrays
*   -   passing arrays as parameters
*   -   using the standard array library
*/
//--------------------------------------------------------------

//load in the standard array header/lib
#include <iostream>
#include <string> //for handling strings
#include <array> //array header

//
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
//--------------------------------------------------------------
//constants for multidimensional arrays
const int WIDTH = 10;
const int HEIGHT = 10;

//
//func prototypes
//2d array
void print2dArray(int arr[][HEIGHT], int WIDTH);
void print2dArrayRef(int (&rr)[WIDTH][HEIGHT], int WIDTH, int HEIGHT);

//single array
void printArray(int arr, int length);
void printArrayRef(int &arr, int length);

//--------------------------------------------------------------
int main() {


    //array memory
    /*
    *   -   let arr => array - with n objects and holds data type of size s
    *   -   the max memory that array will hold will be n * s
    *   
    *   -   standard ints hold 32 bits/4 bytes of memory
    *   -   let arr have 10 elements - the memory useage will be 10 * 4 bytes -> 40 bytes 
    *
    */
    //
    int memoryArray[5] = {1, 2, 3, 4, 5};
    
    //
    cout << "The size of an integer is: " << sizeof(int) << endl;
    cout << "The size of an integer array with 5 elements: " << sizeof(memoryArray) << endl; 
    
    //we can use this to work out the length of the array
    cout << "The length of the array is: " << sizeof(memoryArray) / sizeof(int) << endl;

    //multidimensional array
    /*
    *   -   arrays containing arrays are multidimensional
    *   -   for an array with n depth
    *   -   the total elements -> a * b * c * d ....
    *   -   until n depth
    *
    *   -   in that same way the memory will be a product of the depth
    * 
    *   eg: 
    *   -   let arr => array -> [5][5][5] -> 5 elements with 5 elems etc...
    *   -   if arr => int arr[5][5][5] -> there will be 125 elems
    *   -   125 * 4 bytes => 500 bytes of data
    *           
    */  
    //

    //declare a multidimensional array
    //we are using char here
    char name[2][5] = {
        {'W', 'a', 'q', 'a', 's'},
        {'H', 'a', 'q'}
    };

    //we an convert char arrays into strings using st::string(char&, size);
    cout << "Converting nested char array to string... " << endl;
    cout << "My name is: " << std::string(name[0], 5) + " " + std::string(name[1], 3) << endl;
    
    //
    //the sizeof() for char arrays will always return the number of elements exactly
    //char is 1 byte -> 1 byte * number of elems 
    cout << "Elements in the array: " << std::to_string(sizeof(name)) + " bytes" << endl;    
    cout << "Elements in the array: " << sizeof(name) / sizeof(char) << endl;

    //testing multidimensional arrays and their sizes
    char multArray[5][5][5];
    cout << "The size (memory) used by an array of 5 * 5 * 5: " << sizeof(multArray) << endl;
    
    //md arrays vs psuedo-md arrays
    //height and width for the arrays
    //look at the top theyre delcared as constants
    //WIDTH HEIGHT
    
    //std md array
    int stdMultiDim[WIDTH][HEIGHT];

    //filling the array
    //for multi-dimensional arrays always do -> for each y - do each x
    //for height do width
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            stdMultiDim[x][y] = x * y; //multiply each index
        }
    }

    //pass in the array and the width
    //this is how you pass a 2d array
    //or n dimensional array

    //expects the whole memory block
    // print2dArray(stdMultiDim, WIDTH); 

    //expects the array - but uses the memory address
    print2dArrayRef(stdMultiDim, WIDTH, HEIGHT);

    //
    cout << endl << endl;    

    //psuedo multi-dimensional arrays
    /*
    *   -   multi arrays - abstractions
    *   -   easier to understand
    *   -   we can represent the same thing:
    *       as a single array/linear array
    *  
    *   -   we create a * b elements for the
    *       parent size * nest size
    *   -   array[a * b * c ...]
    */
    int pseudoMultiDim[WIDTH * HEIGHT];

    //fill that array using nested loop
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
    
            //must calculate index
            /*
            *   -   the index in a double loop
            *       for a linear representation of a 2d array
            *       ->  the number of rows * the y-index (0 till height)
            *       ->  add the x-index onto it (the position along x-axis)
            */
            //num rows * y + x
            int index = (y * HEIGHT) + x;
            
            //set that value
            pseudoMultiDim[index] = x * y;

        }
    }

    //pass in that array 
    printArrayRef(pseudoMultiDim, WIDTH * HEIGHT);

    //
    return 0;
}

//passing arrays as arguments
/*
*   -   to pass an array as an argument
*       we pass in the memory address of that array
*   -   the argument can simply be
*       
*   -   ->  array[] <-  defines we pass in an array
*   
*   -   for 2d arrays:
*   -   we have to pass in the first/parent as empty & the second specified
*   -   also pass in the dimensions of the parent array
*       ->  array[][height] <-    defines that we should pass in an a 2d array 
*   -   also spec width -> int width
*   
*   -   this is the same for n dimensions
*   -   the parameter will be: int arr[][a][b][c][d]...
*   -   this passes in the whole array
*   
*   -   figure out how to pass in the reference or pointer to that array
*
*/
//print out 2d array
void print2dArray(int arr[][HEIGHT], int WIDTH) {
    
    //
    cout << "Memory address for array: " << &arr << endl;    

    //for all rows
     for (int j = 0; j < HEIGHT; j++) {

        //print all elems in the nested array
        for (int i = 0; i < WIDTH; i++) {
            cout << to_string(arr[i][j]) + " ";
        }
        cout << endl;

    }

}

//single array
void printArray(int arr[], int length) {
    //loop through and print
    for (int i = 0; i < length; i++) 
        cout << arr[i] << endl;
}

//the above functions can be rewritten 
//they currently take the array -> passing the whole chunk
//the ideal scenario -> pass in the reference
/*
*   -   & -> gets the ref to array
*   -   with an array, distinction between:
*       
*   -   &arr[size] -> creates array of refs
*   -   (&arr)[size] -> creates a ref to array
*
*   -   we want to use: (&arr)[width][height]
*/

//if size known at compile time
//print out 2d array ref
void print2dArrayRef(int (&arr)[WIDTH][HEIGHT], int WIDTH, int HEIGHT) {

    //for all rows
     for (int j = 0; j < HEIGHT; j++) {

        //print all elems in the nested array
        for (int i = 0; i < WIDTH; i++) {
            cout << to_string(arr[i][j]) + " ";
        }
        cout << endl;

    }

}

//same with single dimension
void printArrayRef(int &arr, int length) {
    //loop through and print
    for (int i = 0; i < length; i++) 
        cout << arr[i] << endl;
}