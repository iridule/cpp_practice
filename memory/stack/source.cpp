// the memory stack
// exploring memory and memory allocation
/**
 *  -   stack is part of computer memory
 *  -   lifo - last in first out
 *  
 *  -   the call stack process:
 * 
 *      -   program encounters a function call
 *          
 *      -   a stack frame is constructed:
 *          and pushed onto the stack - w/ that function info
 *      
 *      -   stack contains:
 *              -   address of instruction
 *              -   return address - where to return to after call
 *              -   cpu remembers where to return to
 *              -   all function arguments
 *              -   memory for local variables
 *              -   saved copies of registars
 *                  modified by the function
 *  
 *      -   cpu jumps to function start point
 *      -   the instructions execute
 *      
 *      -   when function terminates: 
 *              -   registers restored from stack
 *              -   stack frame popped
 *              -   return value passed
 *              -   cpu gets return address
 *              -   continues rest of program
 * 
 *      -   stack overflow when memory leaks
 *          beyond the current x amt of max memory  
 *          -   tf: leaks into other areas of memory
 *  
*/
//--------------------------------------------------------------

//
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>

//--------------------------------------------------------------
int main() {

    //
    std::cout << "\nExploring the stack. \n" << std::endl;
    
    // items allocated on the stack (consequitively) hold adjacent memory
    int number0 = 0;
    int number1 = 1;
    int number2 = 2;

    // use \n to seperate lines instead of std::endl
    std::cout <<
    "The following are addresses: \n"  
    "- numbers delcared in memory side by side\n"
    "you can see these numbers are next to each other\n"    
    << std::endl;
    
    //
    std::cout << "Number0: " << &number0 << std::endl;
    std::cout << "Number1: " << &number1 << std::endl;    
    std::cout << "Number2: " << &number2 << std::endl;    

    //  
    /**
     *  -   the std::stack data structure:
     *  -   describes how this process of stack works
     *  
     *  -   this data structure allows us to        
     *      use the full functionality of a LIFO 
     *      data structure
     *  -   objects can only be acessed via
     *      one end of container
     *  -   similar to how the stack
     *      in memory works
     *      
     *  -   stacks are container adaptors  
     * 
    */
    //

    //
    std::stack <int> exampleStack;
    int pushValue = 0;

    // pushing items on top of the stack
    // in console is the result
    // this is how function calls and the call stack is set up
    exampleStack.push(pushValue);

    std::cout << "Explore stack pushing and popping" << std::endl;
    std::cout << std::endl;
    std::cout << "Repeat\n" << std::endl;

    //
    std::cout << std::endl;
    std::cout << "Pushing onto stack: " << pushValue << std::endl;
    std::cout << "Pushing element on the the stack" << std::endl;
    std::cout << "Print the last element - top(): " << exampleStack.top() << std::endl;
    std::cout << "Size of stack " << exampleStack.size() << std::endl; 

    pushValue = 1;
    exampleStack.push(pushValue);    

    std::cout << std::endl;    
    std::cout << "Pushing onto stack: " << pushValue << std::endl;
    std::cout << "Pushing element on the the stack" << std::endl;
    std::cout << "Print the last element - top(): " << exampleStack.top() << std::endl;
    std::cout << "Size of stack " << exampleStack.size() << std::endl;

    pushValue = 2;
    exampleStack.push(pushValue);    
    
    std::cout << std::endl;    
    std::cout << "Pushing onto stack: " << pushValue << std::endl;
    std::cout << "Pushing element on the the stack" << std::endl;
    std::cout << "Print the last element - top(): " << exampleStack.top() << std::endl;
    std::cout << "Size of stack " << exampleStack.size() << std::endl;

    pushValue = 3;
    exampleStack.push(pushValue);    
    
    std::cout << std::endl;    
    std::cout << "Pushing onto stack: " << pushValue << std::endl;
    std::cout << "Pushing element on the the stack" << std::endl;
    std::cout << "Print the last element - top(): " << exampleStack.top() << std::endl;
    std::cout << "Size of stack " << exampleStack.size() << std::endl;

    exampleStack.pop();

    std::cout << std::endl;    
    std::cout << "Popping elements" << std::endl;    
    std::cout << "Print the last element - top(): " << exampleStack.top() << std::endl;    
    std::cout << "Size of stack " << exampleStack.size() << std::endl;

    // this causes a bus core dumped error
    // int array[800000000000000000];
    std::cout << std::endl;    
    std::cout << "int array[800000000000000000] causes an error" << std::endl;

    //
    return 0;

}


