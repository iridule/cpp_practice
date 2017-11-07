// exploring random number generators
/**
 *  -   the cstdlib provides a C function to be able to produce
 *      random values
 * 
 *  -   it provides the same values each time because it is not seeded 
 *  -   to produce the same set - use rand
 *  -   to produce different values each time
 *      use srand() 
 * 
 *  -   the <random> std library gives us access
 *      to random number generators 
 *  -   utilises generators and distributions
 * 
*/
//--------------------------------------------------------------

//
// get our random function
// get the C rand and srand - seeded rand 
// also include the time lib to get time for seeding
#include <iostream>
#include <random> 
#include <stdlib.h>
#include <time.h>


//
int main() {

    // lower and higher bounds for the range
    int lower;
    int higher;

    //
    std::cout << std::endl;
    std::cout << "Exploring random numbers and random number generators" << std::endl;

    // ask user for a range of random numbers
    std::cout << "You are asked to give a range for random numbers" << std::endl;

    std::cout << std::endl;
    std::cout << "Please enter the lower bound: " << std::endl;
    std::cin >> lower;

    std::cout << std::endl;
    std::cout << "Please enter the higher bound: " << std::endl;
    std::cin >> higher;

    std::cout << std::endl;
    std::cout << "Your range is: " + std::to_string(lower) + "-" + std::to_string(higher) << std::endl;
    //

    // process that input and generate random numbers
    /**
     *  -   this process produces random numbers between lower and higher bounds
     *  -   to get numbers between lower and higher... 
     *      -   do lower + rand() % (higher - lower)
     *      -   eg: [10, 100]
     *      -   10 + rand() % (100 - 10) = 10 + rand() % 90 ->
     *          the resulting numbers are between 10 and 90
    */
    //
    std::cout << "Producing unseeded numbers..." << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << lower + (rand() % (higher - lower)) << " ";
    }
    std::cout << "\n" << std::endl; 

    // following process generates seeded numbers
    /**
     *  -   the numbers are seeded with time
    */
    //

    // seeding the numbers with the current time
    unsigned int seed = 0;

    std::cout << "Producing seeded numbers..." << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << lower + (srand(time(NULL)) % (higher - lower)) << " ";
    }
    std::cout << "\n" << std::endl;

    //
    return EXIT_SUCCESS;

}