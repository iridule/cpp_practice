//the main file
/**
 *  -   to compile we can use g++
 *  -   the linker will auto-link for us
 *  
 *  -   often we need to only compile the code that we've written
 *      instead of every single file again
 *  -   to solve this -> we create seperate .o files
 * 
 *      -   g++ -c file1.cpp file2.cpp      
 *      ^ this is via the -c flag - then we link them
 *  
 *  -   we will be compiling these files seperately
 * 
 *  -   also exploring how to create static libraries
 *      using an archiving tools
 *  
 *  -   to create static library:
 *      -   compile the objects seperately
 *      -   then we let create an archive with:
 *          -   ar -rvs outfile obj1.o obj2.o
 *      
 *  -   to link that library we made - compile the
 *      main source file with the library as an argument
 *      to the g++ compiler
 * 
*/
//--------------------------------------------------------------

#include "helpers.h"
#include "helpers2.h"

//
int main() {

    //
    std::string line1 = "Hello this is my message!!!";
    std::string line2 = "I really hope that this works!!!";    
    std::string line3 = "This is another test line";        

    //
    printLine(line1);
    printLine(line2);    
    printLine(line3);    
    
    //
    printLine(std::to_string(add(1, 2)));
    printLine(std::to_string(subtract(5, 3)));    

    //
    return 0;
}