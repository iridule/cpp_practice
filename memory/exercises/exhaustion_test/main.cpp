//
//
//  testing memory exhaustion
//
//

//
#include <iostream>

//
int main() {
    
    //
    std::cout << "Testing memory exhaustion" << std::endl;
    std::cout << "Must be careful of this" << std::endl;    
    std::cout << "Press any key to continue" << std::endl;        
    if (std::cin.get()) {
        while(true) {
            int *i = new int[1000];
                std::cout << i << std::endl;
        }
    }
    //
    return 0;

}