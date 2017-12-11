//

//
#include <iostream>
#include <string>
#include <sstream>

//
class Point {
    public:
        friend std::ostream& operator<< (std::ostream &ostream, Point &point) {
            ostream << point.x << " " << point.y;
            return ostream;
        }
    private:
        int x;
        int y;
};

//
int main() {

    //
    unsigned int size = 0;
    Point *points = nullptr;

    //
    while (true) {

        //
        std::string a, b;
        std::cout << "Enter first number" << std::endl;
        std::getline(std::cin, a);
        std::cout << "Enter second number" << std::endl;
        std::getline(std::cin, b);
        
        //
        size++;
        std::cout << size << std::endl;
        Point *temp = new Point[size];
        delete[] points;
        points = temp;

    }    

    //
    std::cin.get();
    return 0;
}