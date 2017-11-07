// exploring input/output streams with iostream
/**
 *  -   exploring the iostream model
 *  
 *  -   istream/ostream deal with streams
 *  -   cin: input istream, cout: output ostream
 *  -   they are included with the iostream header
 * 
 *  -   ostream:
 *          -   values of various types -> character sequences
 *          -   sends the char sequence to file/memory/computers      
 *          -   values from program: 'c', (12, 34), 123 -> ostream
 *              ostream -> buffer
 * 
 *  -   buffer is used by the ostream to store temp data - 
 * 
 *  -   istream:
 *          -   char sequences into types
 *          -   gets those values from a computer/file/network  
 *          -   values from outside -> buffer -> 
 *              'c', (12, 34), 123  -> program
 *          -   is
 *  
 *          -   buffer in istream also holds temp data
 *          -   eg: the text in a console before you press enter
 *      
 *  -   produce input/output that is human readble or useful to humans
 * 
 *  -   example below looks at input/output +
 *      standard input loops
 * 
 */
//--------------------------------------------------------------

//
#include <iostream>

//
int main() {

    // this line outputs a value to the console
    std::cout << "Hello, this is a basic output to the cosole" << std::endl;

    // variables to store values in
    // int stores a number
    int favouriteNumber; 

    // char stores an array
    // we need an upper limit for the char array
    int upperLimit = 256;
    char name[upperLimit];

    // input comes in from cin
    // we can store this into a value
    // atio converts string into int
    std::cout << "Please enter your favourite number: " << std::endl;
    std::cin >> favouriteNumber; 

    // everytime we use cin - we must clear the buffer
    // otherwise the newline '\n' stays in the buffer
    // ignore the buffer and clear
    std::cin.ignore();    
    std::cin.clear(); 

    // get the whole line with cin.getline()
    // cin.getline - outputs value into std::string or int char[]
    /**
     *  -   the following demontrates how cin.getline works
     *  -   accepts the char array and the max buffer size
     */
    std::cout << "Please enter your name: " << std::endl;    
    std::cin.getline(name, upperLimit); 

    // we can then output the array
    std::cout << "Your name is " << name << std::endl;

    // this is a standard input loop
    // define a boolean to track the current loop
    bool userInput = true;

    /**
     *  -   user input is constantly checked
     *  -   the loop will stop if the wrong data 
     *      type is entered 
     */
    int numberInRange;
    
    //
    while (userInput) {

        //
        std::cout << "Enter a number between 0 and 10" << std::endl;

        // get a number between 0 - 10
        // going to check if it is integer
        std::cin >> numberInRange;        
        std::cout << "You entered: " << numberInRange << std::endl;

        // deals wtith correct input
        if (std::cin) {

            // check the number is in range
            if ((numberInRange > 0 && numberInRange < 10)) {
                
                //
                std::cout << "Hooray you entered a number within range" << std::endl;
                break;

            } else {

                //
                std::cout << "Your number is not in range" << std::endl;
                
            }

        // dealing with errors
        // for example - getting integers only
        } else if (std::cin.fail()) {

            //
            std::cout << "Sorry that was not a number" << std::endl;
            
            //
            std::cin.unget();

            // clears the error state - cin.good()
            // next loop can receive correct data 
            std::cin.clear();
            std::cin.ignore();


        // errors
        } else if (std::cin.bad()) {
            std::cout << "Error - false input" << std::endl;
        }
    
    }


    // get user input to end the program
    std::cout << "\nPress any key to continue... " << std::endl;
    std::cin.get();

    //
    return 0;

}



//--------------------------------------------------------------
// what does this piece of code do? 
// how can we extract unwanted characters?
// throw away non digits
// goes through the cin object and removes digits
// for(char ch; std::cin >> ch && !isdigit(ch); NULL);

// incorrect input
// if (!std::cin) // std::cout << "Error - false input" << std::endl;