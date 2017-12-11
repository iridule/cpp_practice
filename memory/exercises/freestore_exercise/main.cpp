//
//
//  freestore exercises
//
//

//
#include <iostream>
#include <cstdlib>

// helper functions
void print(std::string string) { std::cout << string << std::endl; }
void print(int number) { std::cout << number << std::endl; }
void print(int *pointer) { std::cout << pointer << std::endl; }
void printv(int *pointer) { std::cout << *pointer << std::endl; }
void nl() { std::cout << "\n"; }

// string length
// calculate by counting up the 0 terminator
int stringlength(const char* string) {
    int size = 0;
    int index = 0;
    while(string[index] != '\0') {
        size++;
        index++;
    }
    return size;
}

// this function returns a lower case version of the char input
char* toLower(const char* chars) {
    int size = sizeof(chars);
    char *transformed = new char[size];
    for (int i = 0; i < size; i++) {
        char modified = chars[i];
        if (modified != ' ') 
            modified = chars[i] + char(32);
        transformed[i] = modified;
    } 
    return transformed;
}

// find in the string
int findInString(const char* string, const char* c) {
    // use strlen to get the length of a char*
    // otherwise it will return the size of the pointer
    int size = stringlength(string);
    for (int i = 0; i < size; i++) 
        if (string[i] == *c) return i;
} 

//
const char* stringDuplicate(const char* string) {
    int size = stringlength(string);
    char* duplicate = new char[size];
    for (int i = 0; i < size; i++) duplicate[i] = string[i];
    return duplicate;
}

//
int main() {

    // testing output format
    int test = 10;
    int *testp = &test;
    print(testp);

    // sizes of values
    print("Size of int: " + std::to_string(sizeof(int)));
    print("Size of double: " + std::to_string(sizeof(double)));
    print("Size of bool: " + std::to_string(sizeof(bool)));            

    // chars and strings
    /**
     *  -   const char* -   pointer to an immutable string
     *                      creates a read only copy of string  
     *  -   char* const -   immutable pointer to string
     *  -   char* c[]   -   char array - adds read only string to memory and stores copy in the
     *                      stack  
    */
    // converting char string to lower
    // char string[] = {'T', 'O', ' ', 'L', 'O', 'W', 'E', 'R', ' ', 'C', 'A', 'S', 'E'};
    const char *string = "TO LOWER CASE";
    std::cout << toLower(string) << std::endl;

    // find the first occurance of a letter in a char string
    const char *string2 = "Find me at (x) please";
    const char *c = "x";
    int pos = findInString(string2, c);
    std::cout << c << " is at " << pos << std::endl;

    // string dup - allocate on the freestore
    const char *string3 = "Duplicate me";   
    const char *string4 = stringDuplicate(string3);  
    std::cout << string4 << std::endl;

    //
    print("Begin adding chars");
    int size = 0;
    char *buffer = nullptr;
    char *string5 = nullptr;
    if (std::cin.get()) {
        while(true) {

            // get the user input
            print("Enter a character");
            char temp;
            std::cin >> temp;
            size++;
        
            // create the array first iteration
            if (string5 == nullptr) {
                string5 = new char[2];
                string5[0] = temp;
            } else {

                //
                buffer = new char[size];
                std::cout << string5 << std::endl;
                std::cout << buffer << std::endl;                

                for (int i = 0; i < size; i++) 
                    buffer[i] = string5[i];
                buffer[size - 2] = temp;    
                
                //
                string5 = buffer;
                delete[] buffer;    

            }

        
            // //
            if(temp == '!') {
                buffer[size] = '\0';
                break;
            }


        }
    }
    //
    std::cout << string5 << std::endl;

    //
    std::cin.get();

    //
    return 0;

}