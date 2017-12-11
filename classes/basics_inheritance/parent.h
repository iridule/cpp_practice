
//
#include <iostream>
#include <string>

//
#ifndef PARENT_H
#define PARENT_H

//
class Parent {
    public:
        Parent();
        virtual void sayThing();
    private:
        std::string name;
        int age;
};

#endif