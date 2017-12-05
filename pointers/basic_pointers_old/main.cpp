//looking into the basics of pointers
#include <iostream>
#include <string>

//
using std::cout;
using std::cin;
using std::getline;
using std::endl;
//


//declare a data type
int dataUnit;

//create a pointer to that data type
int* _dataUnit = &dataUnit;

//
int main() {

    cout << "This is working" << endl;
    
    cout << "Please enter an interger: " << endl;
    cin >> dataUnit;

    ////
    /*
    *   -   logging out the pointer to the console
    *       reveals a memory address to the actual value
    *       
    *   -   to access the contents - use the content operator
    *        -> *
    */
    cout << _dataUnit << endl;
    cout << "log contents" << endl;
    cout << *_dataUnit << endl;

    return 0;

}