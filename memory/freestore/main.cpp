//
//
//  freestore under the hood
//
//

//
#include "point.hpp"

//
int main() {

    //  
    Point *point;

    // the relevant constructor is called
    point = new Point(10, 10);
    std::cout << (*point) << std::endl;
    delete point;

    //
    return 0;  

}