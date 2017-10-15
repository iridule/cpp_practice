//C++ BASICS - OVERVIEW 
/** c++ fundementals in one video
*   -   foundations in cpp
*/  

//this is a comment
/* this is a multiline comment*/

//import statments
/*
    import - preprocessor directive
    -   copies header from libs into this file
        before compiling
*/
#include <iostream> //inout 
#include <vector> //vectors - array of flexible size
#include <string>   //strings
#include <fstream>  //file operations
#include <typeinfo> //type operations
#include <limits> //data type limits

//set namespace stop repetition
using namespace std;

//main function 
int main() {

    //out statement
    cout << "This is a basic c++ output statement" << endl;

    //data types
    //floats
    //float 7 digits of sig numbers
    float _float = 1.1234;
    const float _const_float = 3.14159;
    float _signed_float;
    float _unsigned_float;

    //double - large floats
    //double 15 digits sig numbers 
    double _double = 1.6180339887498;
    const double _const_double = 1.61803398874989;

    //ints - whole numbers
    int _int = 2147483647; 
    signed int _signed_int = 4294967295;    
    unsigned int _unsigned_int = 4294967295;
    short int _short_int = 32767;
    signed short int _signed_short_int = 32767;
    unsigned short int _unsigned_short_int = 65535;
    long int _long_int = 2147483647;
    signed long int _signed_long_int = 2147483647;
    unsigned long int _unsigned_long_int = 4294967295;
 
    //above we can declare these as constants too
    //we can also use -> long/long int or long long int
    const unsigned long int const_unsigned_long_int = 2147483647;

    //characters
    //single chars hold 1 byte in memory
    //'' - char, "" - string literal
    char _one_char = 'a';

    //test output examples
    //we can use typeid().name to get var data types
    cout << "_float is: " << typeid(_float).name() << endl;

    //sizeof 
    cout << "size of float: " << sizeof(_float) << endl;    
    cout << "size of double: " << sizeof(_double) << endl;
    cout << "size of int: " << sizeof(_int) << endl;
    cout << "size of char: " << sizeof(_one_char) << endl;        

    //operators
    int _n = 5;
    cout << "5++ = " << _n++ << endl;
    cout << "++5 = " << ++_n << endl;
    cout << "5-- = " << _n-- << endl;
    cout << "--5 = " << --_n << endl;        

    //order of operations /* before +-
    cout << "1 + 2 - 3 * 2 = " << 1 + 2 - 3 * 2 << endl;
    cout << "(1 + 2 - 3) * 2 = " << (1 + 2 - 3) * 2 << endl;
        
    //casting
    cout << "4/5 - int: " << 4/5 << endl;
    cout << "4/5 - cast to float: " << (float) 4/5 << endl;    

    //if statement - conditional execution
    // == != > < <= >= ! && ||
    string out_value = "";    
    int value_1 = 80;
    int value_2 = 100;
    bool check_greater = value_1 > value_2;

    if (check_greater) {
        out_value = "value_1 is greater: " + to_string(value_1);
    } else {
        out_value = "value_2 is greater: " + to_string(value_2);
    }

    cout <<  out_value << endl;

    //switch statements
    int language = 2;

    switch(language) {

        case 1:
            cout << "Language 1: JavaScript";
            break;

        case 2: 
            cout << "Language 2: C++";
            break;

        case 3: 
            cout << "Language 3: glsl"; 
            break;

        default: 
            cout << "Language 4: Life";
            break;

    }

    cout << endl;
    //

    //ternary operator
    int int_1 = 5;
    int int_2 = 10;
    string larger_number = (int_1 > int_2) ? 
        "int_1 : " + to_string(int_1) + " is larger":
        "int_2 : " + to_string(int_2) + " is larger";

    cout << larger_number << endl;

    //arrays
    //define sized - fixed sized
    //array with empty values
    int odd_nums[5];

    //array with set values
    int even_nums[5] = {
        2, 4, 6, 8, 12
    };

    //access using brackets
    cout << even_nums[0];

    //multi-dimensional
    char myName[2][5] = {
        {'W', 'a', 'q', 'a', 's'}, //00
        {'H', 'a', 'q'} //01
    };

    cout << "2nd letter in 2nd array: " << myName[1][1] << endl;
    //

    //for loop
    //fill array -> even nums loop
    int array_even_nums[10];
    int even_num = 0;
    for (int i = 0; i < sizeof(array_even_nums); i++) {
        array_even_nums[i] = even_num;
        even_num += 2;
    }

    //print using while loop
    cout << "Contents of the even numbers array: " << endl;
    int _index = 0;
    int sizeOf_array = sizeof(array_even_nums);
    while (_index < sizeOf_array) {

        //print and iterate
        cout << array_even_nums[_index] << endl;
        _index++;

        //break out
        if (_index == sizeOf_array) break;

    }

    //do while loop
    //getting user input
    string user_guess = ""; //user input string
    int int_user_guess = 0;
    int number_to_guess = 4;
    do { //atleast exec once

        //guess
        cout << "Guess number between 1 - 10: ";
        getline(cin, user_guess);
        int_user_guess = stoi(user_guess); //conv to int

        //notify user
        if (int_user_guess == 4) {
            cout << "Correct number! Well Done!" << endl;
            break;
        } else {
            cout << "Wrong Number! Guess again!" << endl;
        }


    } while (int_user_guess != number_to_guess); //then keep doing if this is true

    cout << "You're great at this guessing!" << cout;
    //

    //strings
    //c++ has string objects
    //the old c method - char array
    char friend_name[8] = {'S', 'h', 'a', 'r', 'j', 'e', 'e', 'l'};

    //c++ 
    string friend_second_name = "Farrukh";
    
    //combine char arrays and strings
    cout << friend_name << friend_second_name << endl;

    //end
    //correct way to exit program
    cout << "Hit any key to exit..." << endl;
    cin.get();

    return 0; //debug int for main - exec perf

}