// quicksort implementation in c++
/**
 *  -   quicksort implementation in c++
 *  -   for more detail on how it works 
 *      look at data structures and algorithms folder
 *      for the javascript implementation
 */
//--------------------------------------------------------------

//
#include <iostream>
#include <string>
#include <utility>

// utils
void printArray(int arr[], int length);

// quicksort prototypes
void quicksort(int arr[], int left, int right, int length);
int partition(int arr[], int pivot, int left, int right, int length);

//
int main() {

    //
    unsigned const int length = 9;
    int array[length] = { 654, 5, 1, 12, 6, 4432, 56638, 262, 33 };
    int left = 0;
    int right = length - 1;

    //
    std::cout << "unsorted: \n";    
    printArray(array, length);
    quicksort(array, left, right, length);
    std::cout << "unsorted: \n";        
    printArray(array, length);
    

    //
    return 0;
}

//--------------------------------------------------------------
// implementation 
// print
void printArray(int arr[], int length) {
    std::string message = " "; 
    for (int i = 0; i < length; i++) {
        message += std::to_string(arr[i]) + " ";
    }
    std::cout << message << std::endl;    
}

// partition
int partition(int arr[], int pivot, int left, int right, int length) {

    // wall will move up
    int wall = left - 1;

    // go through all elems and swap accordingly
    for (int i = left; i < right; i++) {
        if (arr[i] <= arr[pivot]) {
            std::swap(arr[i], arr[++wall]); 
        }
    }

    // swap the last element with itself after 
    // everything else has been relocated
    std::swap(arr[right], arr[++wall]);     

    // return partition
    return wall;

}

// quicksort
void quicksort(int arr[], int left, int right, int length) {

    //
    int pivot;
    int wall;

    // base case
    if (left < right) {

        // set pivot
        int pivot = right;

        //
        int wall = partition(arr, pivot, left, right, length);

        // left and right respec
        quicksort(arr, left, wall - 1, length);
        quicksort(arr, wall + 1, right, length);

    }

}