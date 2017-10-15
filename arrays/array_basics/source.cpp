//--------------------------------------------------------------
//basics of arrays
/*
*   -   exploring the basics of arrays in c++
*   -   how to declare, assign variables
*   -   sorting an array
*/
//--------------------------------------------------------------

/*
*   -   this is a preprocessor directive
*   -   here we are including a file 
*   -   tells compiler to copy the code into the this current file
*/
#include <iostream>
#include <string>
#include <climits>

//we can declare specific things from namespaces we wish to use
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::to_string;
//--------------------------------------------------------------

//function prototypes - these must be declared beforehand
//let the compiler know that we are implementing functions
//print array
void printArray(int arr[], const int size);

//print max
void printMax(int arr[], const int size);

//bubble sort
void bubbleSort(int arr[], const int size);

//--------------------------------------------------------------
int main () {
    
    //--------------------------------------------------------------
    //this is how you declare an array
    /*
    *   type name[size] = {contents};
    */

    //simple declaration
    //here we've simple created an array of size n 
    //the size MUST BE: const int

    //std method
    int arr[5];
    
    //seperate size
    const int size2 = 10;
    float arr2[size2]; //declaring the array with the desired sizes

    //getting the length of an array
    /*
    *   -   get the total bytes within an array
    *   -   you then divide by the byte-size of one element
    *   -   totalBytes/singleByte
    *   
    *   -   sizeof[arr]/sizeof[arr[0]]
    */
    //testing some values
    cout << "Size of arr1: " << to_string(sizeof(arr)/sizeof(arr[0])) << endl;
    cout << "Size of arr2: " << to_string(sizeof(arr2)/sizeof(arr2[0])) << endl;    

    //the arr can also be declared with values inside
    //assignment
    //creating an array of characters
    const int size3 = 10;
    char arr3[size3] = {
        'A', 'r', 'r', 'a', 'y'
    };

    //loop through this array and print its values
    for (int i = 0; i < size3; i++) cout << arr3[i];
    cout << endl;

    //we can also assign fly w/o a specified size for the array
    //this will give it an n size when it compiled
    char arr4[] = {
        'A', 'r', 'r', 'a', 'y', '2'
    };

    //
    cout << "The size of arr4 is: " << sizeof(arr4)/sizeof(arr4[0]) << endl;

    //arrays in string and chars
    /*
    *   -   char[] vs std::string
    *   -   char array is an array of character
    *   -   we can use the insertion operator on this to add a "string" to it
    *   -   the max size for a type char in c++ is one byte
    *   -   and the max size that a char array can be is 256 bytes
    *   -   this is if we pre-defined this char array
    *  
    *   -   we can define it after on the heap - but that requires memory allocation
    *       and dealing with releasing memory
    *   
    */
    char myCharString[256];
    
    //
    cout << "Enter your name: " << endl;

    //where to store pointer/ref to that
    //maximum chars (prevent stackoverflow)
    //delimiting/splitting chars (optional)
    cin.getline(myCharString, 256);

    //
    //in a real scenario there would have to be memory management
    cout << "Your string is: " << myCharString << endl;

    //iteration practice
    /*
    *   -   practice some iteration and algorithms
    *   -   implement a few important/interesting algorithms
    *   -   find the max/sort an array/search through an array
    *  
    */

    //declare an array of ints -> we can apply our algorithms
    //ideally size should be unsigned and const
    const int size4 = 10;
    int myInts[size4] = {
        -50, 3, 72, 1104, 80, -910, 23, -33, 9, -10
    };
    cout << "Array: " << endl;
    printArray(myInts, size4);

    //
    printMax(myInts, size4);
    
    bubbleSort(myInts, size4);
    printArray(myInts, size4);

    //
    return 0;
}

//--------------------------------------------------------------
//definitions for the functions used
//print array
void printArray(int arr[], const int size) {
    for (int i = 0; i < size; i++) cout << " " << arr[i] << " ";
    cout << endl;
}

//finding the maximum value in an array
void printMax(int arr[], const int size) {

    //the size is usually passede in and not determined here
    cout << "The size: " << size << endl;

    //
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        //check against others
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    //
    cout << max << endl;

}

//bubble sort
/*
*   -   implement the slowest algorithm known to man
*   -   this is for demonstration and practice
*/
void bubbleSort(int arr[], const int size) {

    //we check once if any elements need sorting
    //do - while

    //bool - keep track
    bool swapped = false;

    //control - preventing the program getting stuck
    int iters = 0;
    int maxIters = size * size;

    //
    do {

        //reset the swap flag
        swapped = false;
    
        //swap if elemt @ i > i + 1
        for (int i = 0; i < (size - 1); i++) {

            //
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }       

        }

        //
        iters++;

        //
        if (!swapped || iters > maxIters) break;

    } while(swapped);

}