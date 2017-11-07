//variables and data types - safe conversions
/**
 *  -   types - set of possible values + operations that
 *      can be performed on those types
 *  -   object - memory that holds value for that type
 * 
 *  -   type safety:
 *          -   when information in converting types is not lost
 *          -   unsafe methods would convert to types that are      
 *              smaller in range or will not output the same
 *              essential value 
 *      
 *  -   safe conversions:   
 *          -   bool to char
 *          -   bool to int
 *          -   bool to double
 *          -   char to int
 *          -   char to double
 *          -   int to double
 *
 *  -   unsafe conversions
 *          -   double to int
 *          -   double to char  
 *          -   double to bool
 *          -   int to char
 *          -   int to bool
 *
 *  -   below there are explorations of these type conversions
 *  -   also we are looking at how to do basic casts      
 * 
*/
//--------------------------------------------------------------
//
#include <iostream>
#include <climits>
#include <cfloat>

//
using std::cout;
using std::endl;

//
int main () {

    //first unsafe rep 
    //no init of vars - unsafe -> int num; -> always init:
    int num = 0;

    //safe conversion
    /**
     *  -   some here more useful than others
    */
    //bool to char
    bool isTrue = true;
    char boolChar = char(isTrue); //cast
    
    //false outputs nothing and true outputs [0001] ?
    //one questions the usefulness
    cout << "value of bool: " << isTrue << " -> true " << endl;
    cout << "value of char from bool: " << boolChar << endl;  

    //conversion to int - represent bool as int
    int boolInt = isTrue;
    cout << "value of int from bool: " << boolInt << endl;  
    
    //bool to double
    double boolDbl = isTrue;
    cout << "value of double from bool: " << boolDbl << endl;  

    //char to double
    char testChar = 'A';
    double charDbl = testChar;
    cout << "value of char to double: " << charDbl << " -> ASCII code "<< endl;  

    //int to double
    //most useful for calculations
    //we use limits -> it doesn't go out of range 
    int minInt = INT_MIN;
    int maxInt = INT_MAX;
    double intDbl = maxInt;
    cout << "range of double is: " << DBL_MIN << " to " << DBL_MAX << endl;
    cout << "value of int to double: " << intDbl << endl;

    //unsafe conversions
    /**
     *  -   these may be handled different
     *      depending on the compiler implementation
    */
    //

    //double to int
    /**
     *  -   description of what is happening:
     *      -   the double overflows the init
     *      -   so it returns to INT_MIN
     *      -   it seems to be stuck - doesn't move from 
     *          that value
    */
    //overflows the number
    double dblMin = DBL_MIN;
    double dblMax = DBL_MAX;
    int dblInt = dblMax + dblMax/2.0; 
    cout << "range of int is: " << INT_MIN << " to " << INT_MAX << endl;
    cout << "value of max double to int: " << dblInt << endl;

    //double to char
    /**
     *  -   doesn't even output value
     *  -   the compiler doesn't know what to do ->  blank
    */
    char dblChar = dblMax;
    cout << "value of max double to char: " << dblChar << endl;
    
    //to bool - no value
    bool dblBoolMin = dblMin;        
    bool dblBoolMax = dblMax;
    cout << "value of min double to char: " << dblBoolMin << endl;
    cout << "value of max double to bool: " << dblBoolMax << endl;

    //int to char
    //outputs a question mark symbol
    //this is not working
    char intChar = maxInt;
    cout << "value of max int to char: " << intChar << endl;    
    
    //int to bool
    //results in the same value -> 1 -> UNSAFE
    bool intBoolMax = maxInt;
    bool intBoolMin = minInt;    
    cout << "value of min int to bool: " << intBoolMin << endl;    
    cout << "value of max int to bool: " << intBoolMax << endl;    

    //
    return 0;
}

