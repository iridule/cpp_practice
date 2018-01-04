// 
//  operator overloading with vectors
//

//
#include "vector.h"

//
Vector::Vector(void):
x{0}, y{0}, z{0}
{}

//
Vector::Vector (double a, double b, double c):
x{a}, y{b}, z{c}
{}

//
Vector& Vector::operator-= (Vector &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;    
    return *this;
}

//
Vector& Vector::operator+= (Vector &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}

// input/output
std::ostream& operator<< (std::ostream &ostream, const Vector &vector) {
    return ostream << "< " << vector.x << ", " << vector.y << ", " << vector.z << " >";
}

