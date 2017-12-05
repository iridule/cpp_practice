//
// here the individual methods of the star / constructors
// will be initialised

//
#include "star.h"

// helper macros
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062 
#define log(x) { std::cout << x << std::endl; }

//
// implement the constructors
//

//
// default/empty constructor
//
Star::Star():
galX{0}, galY{0}, galZ{0}, radius{0}, name{"none"} {
    log("Empty Star is constructed");
}

//
// a constructor with an initialisation list
// initialiser list works by assigning the values individually
// to the members of the class
//
Star::Star(double x, double y, double z, double r, std::string n)
:galX{x}, galY{y}, galZ{z}, radius{r}, name{n} {
    log("Star is constructed");
}

//
// copy constructor
// these must be a constant pointer or reference
// to the object from which we wish to copy the data
//

Star::Star(Star &star) {
    galX = star.getPositionX();
    galY = star.getPositionY();
    galZ = star.getPositionZ();            
    radius = star.getRadius();
}

//
// destructor
//
Star::~Star() {
    std::string out = (name == "none") ? "Star": name;
    log(out + " was destroyed");
}

// the class interface is defined here
// some methods
double Star::volume() {
    return 4 * (PI * radius * radius * radius) / 3;
}

//
// this is because classes need an interface to allow 
// communcation with the outside world
// setter and getter functions 
// to access the functions that we need
// this is to keep control of what gets used in the public scope
//
std::string Star::getName() { return name; }
void Star::setName(std::string n) { name = n; }

double Star::getPositionX() { return galX; }
void Star::setPositionX(double x) { galX = x; }

double Star::getPositionY() { return galY; }
void Star::setPositionY(double y) { galY = y; }        

double Star::getPositionZ() { return galZ; }   
void Star::setPositionZ(double z) { galZ = z; }                

double Star::getRadius() { return radius; }
void Star::setRadius(double r) { radius = r; }

// demonstrating class overloaded functions
//
// distance between two stars
//
double Star::distance(Star &star) {
    double dX = star.getPositionX() - galX; 
    double dY = star.getPositionY() - galY;
    double dZ = star.getPositionZ() - galZ;
    return std::sqrt(dX * dX + dY * dY + dZ * dZ);
}

//
double Star::distance(double x, double y, double z) {
    double dX = x - galX; 
    double dY = y - galY;
    double dZ = z - galZ;
    return std::sqrt(dX * dX + dY * dY + dZ * dZ);
}

// 
void Star::print() {
    std::string output =    
        name + ": " +  
        "\nX: " + std::to_string(galY) + 
        "\nY: " + std::to_string(galZ) +     
        "\nZ: " + std::to_string(galZ) + 
        "\nRadius: " + std::to_string(radius) + "\n"; 
    std::cout << output << std::endl;
}