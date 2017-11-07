//  the fundementals of enums - plain enums
/**
 *  -   enums - simple user defined types
 *  -   set of values with symbolic constants
 *  -   an enum declaration creates a class-like blueprint
 *  -   the body of an enum - the list of enumerations
 * 
 *  -   two types, scoped(class based) and unscoped(plain)
 * 
 *  -   plain enums - when instanced they are given     
 *      a value from 0 -> n-1 enumerations
 *  -   the first value may be specified - s.t: 
 *      each conseq value is previous + 1
 * 
 *  -   enums are essentially a list of constants
 *      with increasing integer labels
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

//  plain enums
//  declaring enumerator list
/**
 *  -   how you declare plain enums
 *  -   this is a template - it doesn't
 *      instant it.
 *  
 *  -   here we are declaring enums
 *      for suit types for playing cards
 * 
*/
//
enum Suit {
    HEARTS,
    SPADES,
    DIAMONDS,
    CLUBS

};

//  we can also use enums to keep track of states
/**
 *  -   here is a enum list that will print out 
 *      the current season based on an integer that
 *      the user inputs - for the current season
 *  
 *  -   also it is an example of how when the first enumeration
 *      of the list is given a value - the rest of the values
 *      are consequently increased from there.
 * 
 *  
*/
//
enum Season {
    SPRING = 1,
    SUMMER,
    AUTUMN,
    WINTER
};

//
int main() {

    //
    cout << "Exploring the basics of enums" << endl;

    //  using the suit enums
    Suit suit;

    //
    /**
     *  -   demonstrates the initial values
     *      that enums are set by default
     *      and can be accessed in the namespace they
     *      are decalred.
     *  -   here the values are "set" or "enumerated"
     *      one by one - from 0 to n - 1
    */
    cout << "This is the output for the suit enums" << endl;
    cout << "The following are the enumerated values - you can see they are ranged. " << endl;
    cout << "Hearts: " << HEARTS << endl;
    cout << "Spades: " << SPADES << endl;
    cout << "Diamonds: " << DIAMONDS << endl;
    cout << "Clubs: " << CLUBS << endl;

    /**
     *  -   demonstrates a way enums could be used
     *  -   they can be used to group constants
     *      so that they can be accessed in the 
     *      scope they are declared.    
    */
    //  using the seasons enums
    Season season;
    int currentSeason = 0;

    //
    cout << "Enter the number of the current season: " << endl;
    cin >> currentSeason;

    //
    std::string message = "";
    //
    if (currentSeason == SPRING)
        message = "Spring";
    else if (currentSeason == SUMMER)
        message = "Summer";
    else if (currentSeason == AUTUMN)
        message = "Autumn";
    else if (currentSeason == WINTER)
        message = "Winter"; 
    else    
        message = "...FAIL - please given an EARTHLY season...";

    //
    cout << "Your season is " + message + " !!!" << endl;

    //
    return 0;
}