//
// example header file for a class to set out the interface
//
#pragma once

// 
#include <iostream>
#include <string>
#include <cmath>
#include <initializer_list>

// star class 
class Star {

    //
    public:
    
        // constructors
        Star();
        Star(double x, double y, double z, double r, std::string n);
        Star(Star &star);

        // all classes should have set and get functions
        // to access the functions that we need
        std::string getName();
        void setName(std::string n);

        double getPositionX();
        void setPositionX(double x);

        double getPositionY();
        void setPositionY(double y);        
        
        double getPositionZ();                        
        void setPositionZ(double z); 
                      
        double getRadius();
        void setRadius(double r);

        // methods of this class 
        // also demonstrating overloaded functions
        double volume();
        double distance(Star &star);
        double distance(double x, double y, double z);     
        void print();
          

        // destructor
        ~Star();

    //
    private:
        
        //
        std::string name;
        double galX;
        double galY;
        double galZ;       
        double radius;

};