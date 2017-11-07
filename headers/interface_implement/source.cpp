//main file
/**
 *  -   here we will test our math library
*/
//--------------------------------------------------------------

#include "math.h"

//
int main () {

    //using our lib
    int arr[5] = {1, 2, 3, 4, 5};
    int a = sum(arr, 5);

    //formatted printing
    //from cstdio
    std::cout << a << std::endl;

    //
    return 0;
}