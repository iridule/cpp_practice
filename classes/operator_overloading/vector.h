//
//  vector header
//


//
#include <iostream>

//
#ifndef VECTOR_H
#define VECTOR_H

//
class Vector {

    //
    public:

        //
        Vector(void);
        Vector(double a, double b, double c);
        Vector& operator-= (Vector &vector);
        Vector& operator+= (Vector &vector);
        friend std::ostream& operator<< (std::ostream &ostream, const Vector &vector);


    //
    private:

        double x;
        double y;
        double z;

};

#endif



