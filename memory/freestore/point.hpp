//
// test point
// 

#include <iostream>

//
#ifndef POINT_H
#define POINT_H 

//
class Point {

    //
    public: 

        //
        Point(int a, int b): x{a}, y{b}{ std::cout << "Constructing" << std::endl; }
        ~Point() { std::cout << "Destructing" << std::endl; }

        // override the new and delete
        // creating new memory
        // *operator because it is operating on a pointer
        // size_t - device dependant unsigned integral type
        void *operator new(size_t size) {
            // new/delete use malloc under hood
            // allocate new memory with malloc
            std::cout << "Allocating new memory - overloaded new" << std::endl;
            void *m = malloc(size);
            return m;
        }
        
        //
        void operator delete(void *m) {
            std::cout << "Deallocating memory - overloaded delete" << std::endl;
            free(m);
        }

        //
        friend std::ostream& operator<< (std::ostream &os, Point &point) {
            return os << point.x << ", " << point.y;
        }
    

    //
    private:
        
        //
        int x;
        int y;

};

#endif