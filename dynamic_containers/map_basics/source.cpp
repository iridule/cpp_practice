// more on dynamic containers - maps
/**
 *  -   associative containers 
 *  -   key value and a mapped value
 *  -   following specific containers
 * 
 *  -   key value - store and unique id for
 *      elements
 *  -   look up value based on a key
 *  -   eg: phone_numbers is a mapped container
 *  -   we can look up a person - phone_number["name"]
 *  -   returns the appropriate value
 *  
 *  -   other assoc conts are - 
 *      hash-tables, red-black trees
 *  
 *  -   maps/unordered maps 
 *      
 *  -   maps stores key s.t the key or it's
 *      value is present or not
 *  -   as opposed to vector - indexed
 * 
 *  -   take knowledge from here and develop
 *      a markov model
 *     
 */
//--------------------------------------------------------------

// 
// need map for map & utility for pair
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <fstream>
#include <iomanip>
#include <climits>

//
int main() {
    
    //
    // example - finding the key value link
    /**
     *  -   we want to find the frequence of letters
     *      within a string
     *  -   split the string into letters etc 
     */
    //
    // string to count letters in
    std::string stringToAnalyse = "Hello there this is some test string";

    // declare a map of letter counts
    std::map <char, int> letters;

    // here we cut the string and then insert into the map
    // given a char - the map can give the resulting string
    //
    /**
     *  -   if map finds a char in the string that is
     *      not in the map - it will add it and assign
     *      it a value
     *  -   inserts a ("word", 0) into the map
     * 
     *  -   to access the key of map pair: use first
     *  -   to access the value of the map pair: use second    
     *  
    */
    //
    for (char c : stringToAnalyse)
        ++letters[c];   

    //
    //
    std::cout << "\nFor the string: \n";
    std::cout << '"' + stringToAnalyse + '"' + '\n';    
    std::cout << "the mapped letter count is..\n\n";

    // we can read each pair in the map with for-each loop    
    for (std::pair<char, int> pair : letters) {
        std::cout << 
            "Letter: " << pair.first << 
            "\tCount: " << pair.second << 
        std::endl;
    }
    
    //
    // in the same way we can map the amount of n chars in user input
    // let's ask the user for a string to map 
    //
    bool userInput = true;
    std::string userString;

    //
    while (userInput) {
        
        //
        std::cout << "\nPlease enter a valid sentence\n";
        std::getline(std::cin, userString);

        //
        if (std::cin.bad() || std::cin.fail())
            std::cout << "Try again please\n";
        else if (std::cin.good())
            break;
        

        std::cin >> userString;
        //

    }

    //
    std::cout << "\nYou entered: " + userString + '\n';  
      
    //
    // now map out the occurance of chars
    //
    std::map <char, int> userLetters;
    for (char c : userString)
        ++userLetters[c];

    //
    std::cout << "\nFor the string you entered: \n";
    std::cout << '"' + userString + '"' + '\n';    
    std::cout << "the mapped letter count is..\n\n";

    // print out the pairs
    for (std::pair<char, int> pair : userLetters) {
        std::cout << 
            "Letter: " << pair.first << 
            "\tCount: " << pair.second << 
        std::endl;
    }

    //
    // the next application - to read a file
    // count the words and occurances of the words in
    // the file  
    //
    // word map for the file
    //
    std::map <std::string, int> wordMap;

    // open up a filestream  
    std::fstream fileStream;
    
    //
    std::cout << "Opening file\n";
    fileStream.open("aliens_text.txt", std::fstream::in);

    //
    // tokenise the string with spaces as the delimiter
    // from the file
    // 
    std::string word;
    while (fileStream >> word) {
        ++wordMap[word];
    }

    fileStream.close();
    std::cout << "Done reading file\n";
    //

    // print out the words
    std::cout << "\nFor the file in current directory: \n";
    std::cout << "the mapped letter count is..\n\n";
    
    for (std::pair <std::string, int> pair : wordMap) {
            std::cout <<
                std::setw(8) << std::left << "Phrase:" << std::left <<
                std::setw(15) << std::left << pair.first << std::left <<
                std::setw(15) << std::left << "Count: " << std::left <<
                std::setw(5) << std::left << pair.second 
            << std::endl;
    }
    //

    //
    // here is some analysis
    // get the most common character
    //
    int highest = INT_MIN;
    std::string mostCommon;
    for (std::pair <std::string, int> pair : wordMap) {
        if (pair.second > highest) {
            highest = pair.second;
            mostCommon = pair.first;
        }
    }
    std::cout << "\nThe most common item in the file is: " << mostCommon << std::endl;
    //
    
    // user quit
    std::cout << "Press any key to continue...\n";
    std::cin.get();
    
    //
    return 0;
}