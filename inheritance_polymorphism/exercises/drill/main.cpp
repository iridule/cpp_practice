//
//
//  inheritance drills
//
//

//
#include <iostream>
#include <string>

//--------------------------------------------------------------
// helpers
void printcow(std::string string) { 
    // std::cout << string << std::endl; 
    std::string out = "echo \"" + string + "\" | cowthink -f sheep   | lolcat";
    system(out.c_str());
}

void print(const char *string) { std::cout << string << std::endl; }

//--------------------------------------------------------------

// base class with virtual function
class B1 {
    public:
        virtual void vf();
        void f();
};

void B1::vf() {
    std::cout << "virtual void B1::vf()" << std::endl;
}

void B1::f() {
    std::cout << "void B1::f()" << std::endl;
}

//--------------------------------------------------------------

// derived class - virtual function
class D1 : public B1 {
    public:
        virtual void vf(); 
        void f();
};

    std::cout << "virtual void D1::vf()" << std::endl;
void D1::vf() {
}

void D1::f() {
    std::cout << "void D1::vf()" << std::endl;
}

//--------------------------------------------------------------

// abstract class
// cannot be instantiated - rather can only be derived from
class AB1 {
    public:

        // pure virtual function - makes class abstract
        virtual void pvf() = 0;
        virtual void vf();

};

//--------------------------------------------------------------

// dervied class from abstract class
// all virtual members of that inherited class must be override - otherwise:
// derived class -> ABSTRACT
class D2 : public AB1 {
    public:
        virtual void pvf();
        virtual void vf();
        void f();
};

void D2::pvf() {
    std::cout << "virtual void D2::pvf()" << std::endl;
}

void D2::vf() {
    std::cout << "virtual void D2::vf()" << std::endl;
}

void D2::f() {
    std::cout << "void D2::f()" << std::endl;
}

//--------------------------------------------------------------
//
int main() {
    
    // test base class 
    print(
        "\n"
        "Base class:\n"
        "TF: cotanins virtual members to be overriden and accessed across inheritance hierarchies\n"
        "Passes non-virtual members down to derived class\n"
    );

    B1 b1;
    b1.vf();
    b1.f();

    // derived class
    print(
        "\n"
        "Derived member - from base class:\n"
        "TF: contains both virtual and non virtual members from base class\n"
        "Any overriden base class members are available to derived class only\n"
    );
    D1 d1;
    d1.vf();
    d1.f(); 

    // reference object
    print(
        "\n"
        "Base class reference:\n"
        "TF: reference the members of base class only\n"
        "There are no non-virtual functions in reference to base\n"
    );
    B1 &br = d1;
    br.vf();
    br.f();

    // abstract virtual class cannot be instantiated
    // AB1 ab1;
    print(
        "\n"
        "Abstract base class: \n"
        "Implemented to be inherited from and to be overriden\n"
        "Uses pure virutal functions to do this\n"
        "Instantiating one causes a compilation error"
    );

    // dervied virtual class
    print(
        "\n"
        "Derived class from abstract base class: \n"
    );
    D2 d2;
    d2.pvf();
    d2.vf();
    d2.f();


    //
    return 0;

}