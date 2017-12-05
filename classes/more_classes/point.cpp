//
//  point implementation 
//  detailed notes in the header file
//

//
#include "point.h"

// default constructor
// Point::Point()
// {}

// default constructor with init list
Point::Point():
x{0}, y{0}
{
    std::cout << "Constructing the object" << std::endl;
}

// copy 
Point::Point(const Point &point):
x{point.x}, y{point.y}
{
    std::cout << "Copying the object" << std::endl;
}

// move

// copy init constructor
// setting the assigned value to each spec member
Point::Point(int v):
x{v}, y{v}
{
    std::cout << "Copy initialisation" << std::endl;
}

// helpers
std::ostream& operator<< (std::ostream &ostream, const Point &point) {
    return (ostream << "Point(" << point.x << ", " << point.y << ")"); 
}