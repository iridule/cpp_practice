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

// quicksort prototypes
void quicksort(int arr[], int left, int right, int length);
int partition(int arr[], int pivot, int left, int right, int length);

//
int main() {

    //
    unsigned const int length = 6;
    int array[length] = { 5, 22, 33, 66, 44, 67 };
    int left = 0;
    int right = 5;

    //
    // std::cout << partition(array, right, left, right, length) << std::endl;
    quicksort(array, left, right, length);

    //
    return 0;
}

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

    //
    int wall = left - 1;
    std::cout << wall << std::endl << std::endl;

    
    // go through all elems and swap accordingly
    for (int i = left; i <= right; i++) {

        printArray(arr, length);                        
        
        if (arr[i] <= arr[pivot]) {

            std::cout << "swapped" << std::endl;    
            std::cout << std::to_string(arr[i]) << "<=" << std::to_string(arr[pivot]) << std::endl;                

            std::swap(arr[i], arr[wall + 1]);
    
            printArray(arr, length);    
            std::cout << arr[i] << " " << arr[wall]<< std::endl;            
            wall++;
            std::cout << std::endl;

        }
        
    }



    // return partition
    return wall;

}

// quicksort
void quicksort(int arr[], int left, int right, int length) {

    //
    int pivot = right;
    int wall;

    // base case
    if (left < right) {

        // set pivot
        int pivot = right;

        //
        int wall = partition(arr, pivot, left, right, length);

        // left and right respec
        std::cout << "hello" << std::endl;
        quicksort(arr, left, wall - 1, length);
        quicksort(arr, wall + 1, right, length);

    }

}