//
//
//  freestore exercises
//
//

//
#include <iostream>
#include <string>
#include <cstdlib>

// helper functions
void print(std::string string) { std::cout << string << std::endl; }
void print(const char *string) { std::cout << string << std::endl; }
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
    print("Press any key to start");

    // 
    int size = 0;
    int length = 0;
    char temp;
    char *buffer = nullptr;
    char *userString = new char[length];

    //
    if (std::cin.get()) {
        while(true) {

            //
            std::cin >> temp;
            size++;
            length = size + 1;
            
            // terminate
            if (temp == '!') {
                userString[length - 1] = '\0';
                break;
            } else {
                // resize   
                buffer = new char[length];
                for (int i = 0; i < size; i++) 
                buffer[i] = userString[i];
                buffer[size - 1] = temp;
                delete[] userString;
                userString = buffer;
            }
            
        }
    }

    //
    print(userString);

    //
    print("Working with strings");
    print("Press any key to start");
    std::string str;
    std::string userString2;

    //
    if (std::cin.get()) {
        while(true) {

            //
            std::cin >> str;
            if (str == "!")
                break;
            else 
                userString2 += str; 

        }
    }

    //
    print(userString2);    

    //
    print("Stack growth");
    
    //
    int s1 = 10;
    int s2 = 20;
    int s3 = 30;
    int s4 = 40;
    int s5 = 50;  
    print(&s1);
    print(&s2);
    print(&s3);            
    print(&s4);
    print(&s5);   

    //
    int *s6;
    for (int i = 0; i < 5; i++) {
        s6 = new int(i);
        print(s6);  
    }                         

    //
    std::cin.get();
    return 0;

}

