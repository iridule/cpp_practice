// experiment with file ios -> using a ppm image to write to
/**
 *  -   experiment with file output
 *  -   pure learning/fun experience
*/
//--------------------------------------------------------------
//
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#define TWO_PI 6.28318530718

//
int WIDTH = 500;
int HEIGHT = 500;

//
int clamp(float value) {
    if (value > 255) value = 255;
    else if (value < 0) value = 0;
    else value = value;
    return (int)value;
}

//
std::string color(int r, int g, int b) {
    return std::to_string(clamp(r)) + " " 
        + std::to_string(clamp(g))  + " " 
        + std::to_string(clamp(b)) + "\n";
}

//
int main() {

    //
    std::ofstream out("image.ppm");    
    out << "P3\n" << WIDTH << ' ' << HEIGHT << ' ' << "255\n";

    //
    // outputing values to an empty ppm image    
    for (int j = 0; j < HEIGHT; j++)  {
        for (int i = 0; i < WIDTH; i++) {

            //
            int col = 255 * std::sin(TWO_PI/WIDTH * i);

            //
            out << color(col, col, col);
    
        }
    }

}