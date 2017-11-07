//the standard array library
/*
*   -   exploring various methods of array library
*/
//--------------------------------------------------------------
//

#include <iostream>
#include <string>
#include <cmath>
#include <array>

//
using std::cout;
using std::endl;
using std::array;

//
//--------------------------------------------------------------
//prefined consts
const int LENGTH = 5;
const int WIDTH = 5;
const int HEIGHT = 5;
const int LENGTH_UNSORTED = 5;

//function protos
/*
*   -   passing in the refernece is MUCH easier
*/
void printArray(array <int, LENGTH> &arr);
void print2dArray(array <array <int, WIDTH>, HEIGHT> &arr);   

//sorting algorithm --- quicksort
void quicksort(array <int, LENGTH_UNSORTED> &arr, int LENGTH_UNSORTED);
void swap(array <int, LENGTH_UNSORTED> &arr, int j, int j);

//--------------------------------------------------------------
//
int main() {

    //declaring follows template syntax
    /*
    *   -   the way to declare singular arrays
    *   -   std::array <type, size> name{{//values}};
    *   -   std::array <type, size> name = {//values};    
    *   
    *   -   to declare multidimensional -> we create an array of arrays - using the template syntax
    *       std::array <<std::array, nestSize>, parentSize>> = {{}, {}, {}}; 
    *
    */
    //
    
    //single 
    //one way - using namespace
    std::array <int, 5> arr1 = {0, 1, 2, 3, 4};

    //
    cout << "Declaring absolute array - the contents are: " << endl;
    printArray(arr1);
    cout << endl;

    //next way
    array <int, 5> arr2{};
    
    //fill method
    arr2.fill(0);

    //print out that array
    cout << endl;
    cout << "After filling the array: " << endl;
    printArray(arr2);

    //multidimensional array
    array <array <int, WIDTH>, HEIGHT> doubleArray;

    //fill the multi-dim array
    //uses the short syntax
    for (array <int, HEIGHT> arr : doubleArray) {
        arr.fill(0);
    }

    //print that array
    cout << endl;    
    print2dArray(doubleArray);

    //another array to sort 
    //pass into quicksort
    array <int, LENGTH_UNSORTED> unsortedArray{
        -5, 10, -30, 50, 55
    };

    //
    printArray(unsortedArray);
    quicksort(unsortedArray, LENGTH_UNSORTED);
    printArray(unsortedArray);

    //
    return 0;
}
//--------------------------------------------------------------

//to pass it we use the &again
/*
*   -   passing in a ref is as easy as passing
*       in a ref to any instance of an obj -> &obj
*/

//double
void print2dArray(array <array <int, WIDTH>, HEIGHT> &arr) {
    //  
    for (int y = 0; y < HEIGHT; y++) {
        //get elem
        array <int, WIDTH> inner = arr.at(y);
        
        //for every elem - print out
        for (int x = 0; x < WIDTH; x++) {
            cout << inner.at(x) << " ";
        }
        cout << endl;

    }
}

//single
void printArray(array <int, LENGTH> &arr) {

    //print out all elems
    //shorthand loop syntax
    for (int elem : arr) cout << elem << " "; 
    cout << endl;

}

//--------------------------------------------------------------
//quicksort algorithm
void quicksort(array <int, LENGTH_UNSORTED> &arr, int LENGTH_UNSORTED) {

    //implement quick sort
    //

    //chose a pivot start
    //best practice - last element
    int pivot = LENGTH_UNSORTED - 1;
    int wall = -1;
    int lowest = 0;

    //
    for (int i = 0; i < LENGTH_UNSORTED; i++) {

        //
        if (arr.at(i) <= pivot) {
            swap(arr, i, wall + 1);
        }
        
    }

}

//swap
void swap(array <int, LENGTH_UNSORTED> &arr, int i, int j) {
    //swap them using indexes
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
