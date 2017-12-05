// exploring the basics of classses
/**
 *  -   this is the implementation / the code for the
 *      class functionality it.
 *  -   the BSRO - binary scope resolution operator "::"
 *      can be used to access the members within the class and
 *      assign them actualy values
 *  -   eg: a function needs a body - so the defining code 
 *      is all written here 
*/
//--------------------------------------------------------------


//
#include "class.h"

//
// "empty constructor"
Vector::Vector() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

// constructor with arguments
Vector::Vector(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
}

// adding two vectors together
Vector Vector::add(Vector &vector) {
    // add the respective components and return a copy
    // of that vector
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return Vector(x, y, z);
}

// subtracting two vectors
Vector Vector::sub(Vector &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return Vector(x, y, z);
}

// magnitude
Vector Vector::normalise() {
    double m = mag();
    x /= m;
    y /= m;
    z /= m;
    return Vector(x, y, z);
}

// normalise 
double Vector::mag() {
    return sqrt(x * x + y * y + z * z);
}

// dot product of two vectors
double Vector::dot(Vector &vector) {
    return  (x * vector.x) + 
            (y * vector.y) + 
            (z * vector.z);
}

// cross product
Vector Vector::cross(Vector &vector) {
 
    // calculate components the return a vector
    double i = (y * vector.z) - (z * vector.y);
    double j = (x * vector.z) - (z * vector.x);
    double k = (x * vector.y) - (y * vector.y);
    
    // fix the j component
    j == -0.0 ? 0.0: -j; 

    //
    return Vector(i, j, k);

}

// print the vector
std::string Vector::toString() {
    return  std::to_string(x) + " " +    
            std::to_string(y) + " " +
            std::to_string(z);
}

// log to console
void Vector::log() {
    std::cout << toString() << std::endl;
}