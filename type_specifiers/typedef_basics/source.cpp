//  using typdef
/**
 *
*/
//--------------------------------------------------------------

//
#include <iostream>
#include <cstdio>
#include <string>

//
using std::cout;
using std::endl;
using std::cin;

//
typedef std::string Str;

//
int main() {

    //
    cout << "Exploring the basics of enums" << endl;

    Str myString = "hello world";

    //
    cout << myString << endl;

    //
    return 0;
}