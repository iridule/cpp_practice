//implementation
/**
 *  -   the functions we have DECLARED in the header
 *      cannot be used till they have been defined
 *  -   they will be defined here in the source file
 *      of the same name
*/
//--------------------------------------------------------------

//we must always include the header with the implementaions we wish to use
//

#include "math.h"

//the following functions showcase overloading
int sum(int a, int b) {
    return a + b;
}

//  
int sum(int arr[], int length) {
    int c = 0;
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << std::endl;
        c += arr[i];
    }
    return c;
}   
