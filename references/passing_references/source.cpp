//passing in a value using a refernce
/*
*   -  look at passing the reference of an integer
*/

#include <iostream> 

//
using std::cout;
using std::endl;

//swap function prototype
/*
*   -   the amersand gets the memory location
*/
void swap(int &a, int &b);
void print(int* arr);

int arr[5] = {
    1, 2, 3, 4, 5
};
int* ptr = &arr;

//--------------------------------------------------------------
int main() {

    //create two elements 
    int x = 10;
    int y = 15;

    //these are the values before we swap them
    cout << x << endl;
    cout << y << endl;
    //

    //swap those values
    // swap(x, y);
    print(ptr);
    
    //these are the values after we swap them
    cout << x << endl;
    cout << y << endl;

    //
    return 0;
}

//swap function 
void swap(int &a, int &b) {

    //print out that hex address
    

    //instead of passing in the whole chunck of memeory
    //we pass in the memory reference -> the hex address
    int temp = a;
    a = b;
    b = temp;

    //
    return;

}

//
void print(int* arr) {
    cout << arr[0] << endl;
}