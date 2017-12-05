// exploring the basics of structs
/**
 *  -   understanding structs
 *  -   why use struct instead of classes
 *  -   implement a simple struct object
 *
 *  -   small passive objects
 *  -   structs are aggregate data types - wrap other data
 *  -   all members in structs are public
 *  -   structs are inherited from C - and represent
 *      a physically group set of variables bound within a namespace
 *  -   one can instance multiple objects on this type
 *  -   structs can be passed to functions to process them
 *
 *  -   use structs:
 *          -   when representing single values - similar to primitive types
 *          -   small instance size - do not use struct to defined
 *              large parts of program logic
 *          -   immutable types
 *          -   binding multiple types of data into a small data structure
 *          -   representing types with no indentities
 *
*/
//--------------------------------------------------------------

//
#include <iostream>
#include <string>

//
#define log(x) std::cout << x << std::endl;
#define error(x) std::cerr << x << std::endl;

// a simple struct to represent a date
// the struct 'wraps' the variales into its own data type - date
// makes the type more succient and reusable
struct Date {

    // primitives to encapsulate
    int day;
    int month;
    int year;

    // useful members
    // was Date::set - changed to a constructor
    //
    Date() {}
    Date(int d, int m, int y) {

        //
        day = d; 
        month = m;
        year = y;

        // year will always be valid provided it is not below zero
        // handle the error or throw an exception
        if (year < 0)
        year = 0;
        else if (year > 9999)
        year = 9999;

        // month
        if (!(month > 0 && month < 12))
        error("Month is out of bound");

        // days
        if (day < 0) day = 0;

        // april, june, september, november
        if (month == 4 || month == 6 || month == 8 || month == 11) {
            if (day > 30) {
                day = 30;
                error("Day was out of bound");        
            }   
        }  else if (day > 31) {
            day = 31;
            error("Day was out of bound");        
        }

        // handle/check leap year
        if (month == 2) {
            if (isLeapYear(year)) {
                if (day > 29) {
                    day = 29;
                    error("Day was out of bound");        
                }
            } else {
                if (day > 28) {
                    day = 28;           
                    error("Day was out of bound");        
                } 
            }       
        }

    //        
    }

    // check leap year
    bool isLeapYear(int y) {
        if (y % 4 == 0) {
            if (y % 100 == 0) {
                if (y % 400 == 0)
                return true;
                else
                return false;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    std::string toString() {
        return  std::to_string(day) + "/" +
                std::to_string(month) + "/" +
                std::to_string(year);
    }

};

//
int main() {

    // initialise the object
    // with a struct we must initalise every single value individually
    // this is error prone because there's no order or error handling mechanism
    // one could use a function to set the values of date
    // a function that accepts the struct as an argument
    Date today;
    today.day = 25;
    today.month = 11;
    today.year = 2017;
    log("Today is " + today.toString());

    // it is more valuable to build the function into the struct itself
    Date tomorrow; 

    // setting values
    // a build in set function to set the values can be usedd 
    // tomorrow.set(26, 11, 2017);    

    // another way is to use constructor initialisation
    tomorrow = {26, 11, 2017};
    log("Tomorrow is " + tomorrow.toString());

    // other ways
    Date dayAfterTomorrow {28, 11, 2017};
    Date theDayAfterThat(29, 11, 2017);
    log("Day after tomorrow is " + dayAfterTomorrow.toString());
    log("Day after that is " + theDayAfterThat.toString());

    //
    return 0;

}