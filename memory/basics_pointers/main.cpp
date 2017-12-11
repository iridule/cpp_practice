//
//  
//  Exploring pointers
//
/**
 *  -   references:   
 *          -   is the memory address of a variable
 *          -   alternative method of accessing an object
 *          -   machine oriented - not suitable for human readability
 *          -   to get a reference - use the '&' address of operator
 *          -   can be seen as: automatically dereferenced immutable pointer
 * 
 *  -   pointers:   
 *          -   pointer is a variable that holds the address
 *          -   thus it points to that address 
 *          -   can also access the value in that address
 *              by reference with '*' dereference operator
 *  
 *  -   difference between:
 *          -   assignment to pointer changes pointer value not the pointed to
 *          -   to get pointer - use new/&
 *          -   to access pointed value - use []/*
 *          -   assignment to referenced value - changed the value at reference/address
 *          -   reference cannot refer to different object 
 *          -   assignment of references - deep copy - assigns to the reference object
 *          -   assingment of pointers - assigns to the pointer object
 *  
 *  -   null pointer:
 *          -   empty pointer - denoted by type *ptr = nullptr (0 or NULL is also valid)
 *  
 * 
*/
//
//

//
#include <iostream>
#include <string>

//
// function prints out type and performs arithmetic 
// based on the typeless pointer passed in
//
void manageType(void * data, int size) {

    // determines one of three types
    // then casted to appropriate type
    // char
    if (size == sizeof(char)) {
        char *pc = (char*)data;
        std::cout << "Type is char" << std::endl;
        std::cout << *pc + 1 << std::endl; // cast to char pointer
    // int          
    } else if (size == sizeof(int)) {
        int *pi = (int*)data;
        std::cout << "Type is int" << std::endl;        
        std::cout << *pi + 1 << std::endl; // cast to char pointer        
    // long
    } else if (size == sizeof(long)) {
        long *pl = (long*)data;
        std::cout << "Type is long" << std::endl;
        std::cout << *pl + 1 << std::endl; // cast to char pointer        
    }

}

//
// functions to pass to the functor
//
void addOnePrint(int &elem) {
    elem += 1;
    std::cout << "New element: " << elem << std::endl;
}

//
// array for each 
// function expects a function pointer as argument
// type (*name)(params)  
//
void forEach(int *array, int size, void (*func)(int &elem)) {
    for (int i = 0; i < size; i++) {
        func(array[i]);
    }
}

//
int main() {

    //
    // references
    //

    // printing out the reference of a
    int a = 5;
    std::cout << "Reference of " << a << ": " << &a << std::endl;

    //
    //  pointer
    //
    std::cout << "Declaring a pointer to the variable" << std::endl;
    
    //
    int *pa = &a;
    std::cout << "Address inside pointer to value: " << pa << std::endl;

    // 
    //  dereferencing
    //  
    std::cout << "Value stored inside the pointer: " << *pa << std::endl;

    //  pointers can be reassigned values
    int b = 10;
    std::cout << "Before reassignment - reference: " << pa << std::endl; 
    std::cout << "Before reassignment - value: " << *pa << std::endl;         
    std::cout << "Reassigning different reference to pointer" << std::endl;

    pa = &b;
    std::cout << "After ressignment - reference: " << pa << std::endl;    
    std::cout << "After ressignment - value: " << *pa << std::endl;        
    std::cout << "Reassigning different value to pointed value" << std::endl;
    
    *pa = 100; 
    std::cout << "After ressignment - reference: " << pa << std::endl;    
    std::cout << "After ressignment - value: " << *pa << std::endl;       

    //
    // arrays and pointers
    //
    //
    // arrays are pointers to the first value
    // any value access via the [] operator - gets the n element from that point
    //

    // to assign array to pointer - simply assign via identifier
    int arr[5] {1, 2, 3, 4, 5};
    int *arrp = arr;

    //
    std::cout << "Printing identifer of the array prints reference: " << arr << std::endl;

    // to get subsequent values - one can add n to the value in the pointer
    // this will access the element that neighbour that array
    std::cout << "The result of array + 1: " << (arr + 1) << std::endl;    

    // using this method to print of all elements in array
    for (int i = 0; i < 4; i++)  {
        std::cout << "Array + " << i << ": " << (arr + i) << std::endl;
        std::cout << "Value at array + " << i << ": " << *(arr + i) << std::endl;        
    }

    //
    // 
    // pointer arithmetic
    //
    //
    /**
     *  -   pointers to any data type points to memory address where data is stored
     *  -   the address also represents the section of the bytes the pointer takes up 
     *  -   the next piece of data will be (n * size) bytes along
    */
    //
    
    
    // for example - consider the following
    //

    // some data types
    char c = 'a';           // 1 byte - 8 bits
    short s = 64;           // 2 bytes - 16 bits
    int i = 128;            // 4 bytes - 32 bits 
    long l = 512;           // 8 bytes - 64 bits

    // the following are pointers
    // they all have the same size - no matter what the type
    // this is because address is dependant on the os/processor type
    // 32 bit os - 4 byte address, 64 bit os - 8 byte address
    //
    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long *pl = &l;

    // printing the sizes
    std::cout << "Pointers sizes" << std::endl; 
    std::cout << "char: " << sizeof(pc) << std::endl;
    std::cout << "short: " << sizeof(ps) << std::endl;
    std::cout << "int: " << sizeof(pi) << std::endl;            
    std::cout << "long: " << sizeof(pl) << std::endl;              

    // incrementing the pointers
    // chars are considered strings - so - use static cast to output their address
    std::cout << "Address of char " << static_cast<void *>(pc) << std::endl;   
    std::cout << "Address of short " << ps << std::endl;   
    std::cout << "Address of int " << pi << std::endl;       
    std::cout << "Address of long " << pl << std::endl;       

    // here the addresses have inc by their respec byte size
    std::cout << "Performing arithmetic" << std::endl;
    std::cout << "You can see they have increased by their respective byte size" << std::endl;    
    std::cout << "Address of char + 1 byte: " << static_cast<void *>(++pc) << std::endl;   
    std::cout << "Address of short + 2 bytes: " << (++ps) << std::endl;   
    std::cout << "Address of int + 4 bytes: " << (++pi) << std::endl;       
    std::cout << "Address of long + 8 bytes: " << (++pl) << std::endl;       

    // here the the values are printed but there are strange behaviours because
    // the values at those bytes have not been allocated
    std::cout << "Getting value after performing arithmetic" << std::endl;
    std::cout << "If we go too far - it causes segmentation" << std::endl;    
    std::cout << "Address of char + 1 byte: " << *(++pc) << std::endl;   
    std::cout << "Address of short + 2 bytes: " << *(++ps) << std::endl;   
    std::cout << "Address of int + 4 bytes: " << *(++pi) << std::endl;       
    std::cout << "Address of long + 8 bytes: " << *(++pl) << std::endl;       

    //
    // other pointer types
    //
    
    // const pointer
    // pointers that cannot be overwritten
    // provides immutability to addresses
    const int d = 256;
    const int *constPointer = &d;

    // null pointers 
    /**
     *  -   empty pointer
     *  -   this is to check if a pointer is pointing to a block of memory
     *  -   other aliases include 0, NULL
     *  -   when delete is used - point becomes null and ready to be reassigned
     * 
    */
    double *nullPointer = nullptr;

    // void pointers
    /**
     *  -   void pointers - special types of pointers
     *  -   represent the absence of type
     *  -   point to typeless value
     *  -   they can point to any data type
     *  -   limitation - must be cast to a type
     *  -   they may also be passed to functions as generic
     *      type
     *  -   however to convert back - the size is needed
    */
    //
    // data types
    char charToCast = 'c';
    int intToCast = 64;
    long longToCast = 256;  
    void *cvp = &charToCast;
    void *ivp = &intToCast;
    void *lvp = &longToCast;

    // checking/converting 
    manageType(cvp, sizeof(charToCast));
    manageType(ivp, sizeof(intToCast));
    manageType(lvp, sizeof(longToCast));    


    //
    //  char pointers
    // 
    /**
     *  -   string literals - null terminated array of chars
     *  -   const char pointers - string literals - immutable
     *  -   strings can be represented as char arrays
    */
    //
    // the const can come before or after type qualifier
    const char *stringLiteral = "This is a string literal";
    std::cout << stringLiteral << std::endl;

    // 
    // pointers to pointers 
    //
    // pointers can be set to hold the reference of pointers
    long longFoo = 4294967296;
    long *longPointer = &longFoo;
    std::cout << "Adress of long: " << longPointer << std::endl;
    std::cout << "Value of long: " << * longPointer << std::endl;
    long **longDoublePointer = &longPointer;
    std::cout << "Address of double pointer: " << longDoublePointer << std::endl;
    std::cout << "Value of double pointer: " << *longDoublePointer << std::endl;
    std::cout << "Value of value inside double pointer: " << **longDoublePointer << std::endl;    

    //
    //  pointers to functions
    //  
    //
    void (*functionPointer)(int &elem) = addOnePrint;
    forEach(arr, 5, functionPointer);

    //
    return 0;

}   