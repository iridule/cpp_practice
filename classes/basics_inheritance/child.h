
#include "parent.h"    

//
#ifndef CHILD_H
#define CHILD_H

// inherit the Parent
class Child : public Parent {
    public:
        virtual void sayThing();
    private:
        std::string name;
        int age;
};

#endif