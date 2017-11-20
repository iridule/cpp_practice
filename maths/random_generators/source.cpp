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
#include <string> 
#include <random> 
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
    // if (higher == lower) higher = lower + 1;

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
    // first seed - then call rand
    unsigned int seed = time(NULL);
    srand(seed);

    std::cout << "Producing seeded numbers..." << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << lower + rand() % (higher - lower + 1) << " ";
    }
    std::cout << "\n" << std::endl;

    // exploring gaussian random
    /**
     *  -   gaussian distribution gives natural random numbers
     *  -   where there is a 'mean' at which the numbers gather
     *  -   distribution of numbers such that there is an optimal
     *      or average point where the numbers gather - forming a bell curve
     * 
     *  -   mean in the middle position of the average - what value is the average
     *  -   standard deviation is the amount the values spread across the curve
     *      a higher deviation means the values are closer to each other.
     *  
    */
    //

    // first we need a number generator engine
    std::default_random_engine randomEngine;

    // then a distributor class
    // this is the standard normal - has mean 1 and std dev 0
    const double MEAN = 5.0;
    const double STD_DEV = 3.0;
    std::normal_distribution <double> distribution(MEAN, STD_DEV);

    // keep on experimenting - eg - rolling the number generator n times to get
    // a certain amount of values
    const int MAX_TRIALS = 1000;
    const int MAX_VALUES = 10;

    // output some test values into an array and count
    // do not forget to initialise the array 
    const int PLOT_MIN = 0;
    const int PLOT_MAX = 10;
    int plot[PLOT_MAX] = {};
   
    // for debug using 5
    for (int i = 0; i < MAX_TRIALS; i++) {

        // create a random number with the normal distribution transformation
        // pass the engine to the distributor
        int number = distribution(randomEngine);
        std::cout << "iteration: " << i << '\n'; 

        // keep numbers within a range and count 
        // preincrement counts the number of times that number occure
        if (number >= PLOT_MIN && number < PLOT_MAX) {
            ++plot[number];            
            std::cout << "number " << number << '\n';
            std::cout << "count for " << number << " is: " << plot[number] << std::endl;
        }

    }
    
    // draw the array
    for (int number : plot) {
        std::string bar = std::string(number, '=');
        std::cout << bar << std::endl;
    }

    //
    return EXIT_SUCCESS;
}
