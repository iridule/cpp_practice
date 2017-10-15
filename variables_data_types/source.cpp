//	-------------------------
//  variables_data_types

//
#include <iostream> //i/o

#include <climits> //limit headers 
#include <cfloat>

using namespace std;

//
int main() {

    //
    cout << "Exploring variables and data types" << endl;

    //void - type with empty set of values
    //incomplete types 
    //void typeVoid; 
    cout << "void is an empty type or incomplete type" << endl;

    //nullptr
    cout << "nullptr - null type of ptr" << endl;

    //boolean type
    //holds just a single value - represented by 1/0 congr. T/F
    bool trueBool = true;
    bool falseBool = false;

    cout << "trueBool: " << trueBool << endl;
    cout << "falseBool: " << falseBool << endl;    

    //character types 
    //char - represents ONE char 
    //rep by single quote
    //chars can represent string chars aswell as integers
    char charVal = 'A'; //rep 1 byte
    cout << "Value of char: " << charVal << endl;
    cout << "Size of char: " << sizeof(charVal) << endl;
    cout << "Number of bits in a char " << CHAR_BIT << endl;
    cout << "Char range: " << CHAR_MIN << " to " << CHAR_MAX << endl;    
    cout << "Signed char range: " << SCHAR_MIN << " to " << SCHAR_MAX << endl;
    cout << "Unsigned char range " << 0 << " to " << UCHAR_MAX << endl;

    //integer types
    cout << "Ints are whole numbers" << endl;   
    
    //types
    //std - these hold a max value - displayed below
    //std integer - 16 bit int -> this is signed by def
    int int16Min = -32767;
    int int16Max = 32767;
    cout << "Signed int goes from: " << int16Min << " to"  << int16Max << endl;

    //modfied
    /*
    *   -   data types can be modded with modifiers
    *   -   convert 16 bit ints -> 32 bit ints -> 64 bit etc
    *   -   signed/unsigned values -> removes the -ve component -> 
    *       if x is a max value for signed - the range -> -x -> x
    *       ->  tf: for unsigned -> 0 -> 2x
    *   -   const -> value in NOT OVERWRITTEN
    */
    unsigned u_int16Max = 65535;
    cout << "Unsigned int goes from: 0 to " << u_int16Max << endl; 

    //other modified types
    /*
    *   short int
    *   long int
    *   long long
    *   -> these can be signed or unsigned
    */

    //we can use <climits> <cfloat> <numeric_limits> to get the data limits    
    cout << "Signed short int: " << SHRT_MIN << " to " << SHRT_MAX << endl;
    cout << "Unsigned short it: " << 0 << " to " << USHRT_MAX << endl;
    cout << "Signed long int: " << LONG_MIN << " to" << LONG_MAX << endl;
    cout << "Unsigned long int: " << 0 << " to " << ULONG_MAX << endl;
    cout << "Signed long long int: " << LLONG_MIN << " to " << LLONG_MAX << endl;
    cout << "Unsigned long long int: " << 0 << " to " << ULLONG_MAX << endl;    

    //floating point numbers
    /*
    *   -   floating point values -> the computer equiv of real numbers
    *   -   we can modify them with const and long for doubles
    *   -   floats -> 32 bit values
    *   -   doubles -> 64 bit values
    *   -   long double -> 80 bit value
    */

    //using cfloat to show different components    
    cout << "Float radix/base: " << FLT_RADIX << endl;
    
    //mantissa - component that reps the sig digits
    cout << "Mantissa - float " << FLT_MANT_DIG << endl;
    cout << "Mantissa - double " << DBL_MANT_DIG << endl;
    cout << "Mantissa - long double " << LDBL_MANT_DIG << endl;

    //max values
    cout << "Float range: " << FLT_MIN << " to " << FLT_MAX << endl;
    cout << "Double range: " << DBL_MIN << " to " << DBL_MAX << endl;
    cout << "Long double range: " << LDBL_MIN << " to " << LDBL_MAX << endl;

    //
    cout << endl;
    cout << "Press any key to exit...";
    cin.get();

    //
    return 0;

}
