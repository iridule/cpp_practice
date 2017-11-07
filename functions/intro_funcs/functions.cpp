//functions - implementation
//this is where we shall implement the functions that we plan to use
/***/
//--------------------------------------------------------------

//we must always include the file that has the prototypes
#include "functions.h"

//these don't do much vastly different
//sum
//but they are here for example
int sum(int a, int b) { return a + b; }
double sum(double a, double b, double c) { return a + b + c; }

//square
//int square
int square(int a) { return a * a; };
double square(double a) { return a * a; };

//distance 
//int distance between 2 2d points
//utilising the functions that we defined above 
int distance(int a, int b, int c, int d) {
    int dx = c - a;
    int dy = d - b;
    return std::sqrt(square(dx) + square(dy));
}

//double distance b/w 2 3d points
double distance(double a, double b, double c, double d, double e, double f) {
    double dx = d - a;
    double dy = e - b;
    double dz = f - c;
    return std::sqrt(square(dx) + square(dy) + square(dz));
}

//divisiblity
bool isDivisibleInt(int n, int m) {
    if (n % m == 0) {
        return true;
    } else {
        return false;
    }
}

//print
void printString(std::string a) {
    std::cout << a << std::endl;
}

//the following functions demonstrate passing values

//pass by value
//here the function also shows what is happening inside
//this is not something one would do in a real scenario
void swapInts(int a, int b) {
    printString("Inside func -> before swap: " + std::to_string(a) + " " + std::to_string(b));    
    int temp = a;
    a = b;
    b = temp;
    printString("Inside func -> before swap: " + std::to_string(a) + " " + std::to_string(b));    
}

//pass by reference
int sumArray(std::array <int, 10> &arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
    }
    return sum;
}

//pass by const reference
//this func prints the array but also returns message
std::string printArray(const std::array <int, 10> &arr) {
    std::string out = "";
    for (int i = 0; i < arr.size(); i++) {
        out += " " + std::to_string(arr.at(i)) + " "; 
    }
    printString(out);
    return out;
}

