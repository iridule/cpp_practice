// exploring input/output streams with iostream
/**
 * 
 *  -   most data stored on hard drive - data is persistent
 *  -   files store large data in preformatted style
 *  -   files are sequence of bytes numbered 0 - n
 * 
 *  -   file formats decide what the bytes inside mean
 *  -   in a simple text file - the first n bytes represent
 *      the first n characters in that text file
 *  -   format serves role - similar to types in objects/classes
 * 
 *  -   ostream - converts objects in main memory (program) in streams of bytes
 *  -   istream - converts stream of bytes from disk into objects
 *      
 *  -   process: (order represents communication)
 *          -   disk (files/strings/sequence of bytes)
 *          -   iostreams (communicates between systems)
 *          -   program memory/RAM (objects/data types)
 * 
 *  -  to read a file:
 *          -   know its name
 *          -   open it to read
 *          -   read in the characters
 *          -   close the file
 * 
 *  -   write a file:   
 *          -   open it to write/create a new file of that name
 *          -   write out our objects
 *          -   close it
 * 
 */
//--------------------------------------------------------------

// include fstream to read to our files
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


//
int main() {

    // ask user for the file name - store in string
    std::string fileInName;
    std::cout << "Please enter file name" << std::endl; 
    std::cin >> fileInName;

    // create instance of FILE input stream object
    // check error
    // scoped streaming
    std::ifstream inputStream {fileInName};

    // 
    if (!inputStream) 
        std::cout << "Can't open input file" << std::endl;

    // create a std::vector to store the values into
    std::vector <int> inputFileResult;
    int numberFromFile;

    // interate throught file and store results
    // the >> operator stores into the file
    // keep pushing into our data structure
    while (inputStream >> numberFromFile) {
        inputFileResult.push_back(numberFromFile);
    }

    // 
    std::cout << "File read - here is the content" << std::endl;
    for (int value : inputFileResult) {
        std::cout << value << std::endl;
    }

    // read through the file of words
    fileInName = "";
    std::cout << "Please enter words file name" << std::endl; 
    std::cin >> fileInName;
    std::ifstream inputStreamWords {fileInName};

    // error
    if (!inputStreamWords) 
    std::cout << "Can't open input file" << std::endl;

    // stream through that words file and store the result
    std::vector <std::string> inputWordsFileResult;
    std::string wordFromFile;
    
    //
    while (inputStreamWords >> wordFromFile) {
        inputWordsFileResult.push_back(wordFromFile);
    }

    // 
    std::cout << "File of words read - here is the content" << std::endl;
    for (std::string value : inputWordsFileResult) {
        std::cout << value << std::endl;
    }   

    //
    /**
     * -    more to do than just read files
     * -    writing user data onto file
     */
    //
    // create an outstream
    std::string userDataFile;
    std::cout << "Enter name of file to write data to..." << std::endl;
    std::cin >> userDataFile;
    
    // output file stream object
    std::ofstream userDataOutputStream{userDataFile};

    // check error 
    if (!userDataOutputStream) 
        std::cout << "Invalid file name" << std::endl;

    // clear cin
    std::cin.ignore();        
    std::cin.clear();

    // ask user for three phrases to push into stream
    bool userInput = true;
    int amountPhrases = 0;

    
    // simple input loop
    while (userInput && amountPhrases < 3) {

        //
        std::string currentPhrase;
        std::cout << "Enter a phrase" << std::endl;         
    

        // get the string data from user
        std::getline(std::cin, currentPhrase);
        
        // use the output operator to stream into the output file
        userDataOutputStream << currentPhrase + "\n";

        //
        amountPhrases++;
        if (amountPhrases == 3) break;

    }
    
    // we MUST flush before the data is written
    userDataOutputStream.flush();

    //
    std::cout << "You entered three phrases" << std::endl;    

    std::cout << "Reading those phrases" << std::endl;        

    //
    std::vector <std::string> userData;
    std::string userDataPhrase;
    std::ifstream userDataInputStream {userDataFile};

    while (userDataInputStream >> userDataPhrase) {
        userData.push_back(userDataPhrase);
    }

    // output that data
    for (std::string data : userData) {
        std::cout << data << std::endl;
    }
    std::cout << std::endl;    

    // above was the scoped way of doing it
    /**
     *  -   this is is simpler way
     *  -   using open and close
     *  -   all operations happen in between
     *  
     *  -   use an instance of fstream
     * 
     */
    //

    // open auto gens the file if it doesn't exist
    // create the fstream
    std::fstream gameSavesStream;
    
    // all happens here
    gameSavesStream.open("game_saves.txt", std::fstream::out | std::fstream::in);

    //
    std::cout << "Add some data to the file..." << std::endl;        

    // clear cin
    std::cin.ignore();
    std::cin.clear();

    //
    userInput = true;
    amountPhrases = 0;

    while (userInput && amountPhrases <= 3) {

        //
        std::string currentPhrase = "";
        std::cout << "Enter some data..." << std::endl;
        
        //
        std::getline(std::cin, currentPhrase);
        gameSavesStream << currentPhrase + '\n';

        //
        amountPhrases++;
        if (amountPhrases == 3) {
            userInput = false; 
            break;
        }

    }

    // flush again
    gameSavesStream.flush();
    
    // change to read pointer
    gameSavesStream.seekg(0, std::ios_base::beg);

    //
    std::cout << "Reading the file..." << '\n' << std::endl;        
    std::vector <std::string> gameSavesData;
    std::string gameSaveUnit;

    while (gameSavesStream >> gameSaveUnit) {
        std::cout << gameSaveUnit << std::endl;
        gameSavesData.push_back(gameSaveUnit);
    }

    gameSavesStream.close();    
    //  


    std::cout << "\nFinished reading the file..." << std::endl;            

    // get user input to end the program
    std::cout << "\nPress any key to continue... " << std::endl;
    std::cin.get();

    //
    return 0;

}