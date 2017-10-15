//FUNDEMENTALS OF C++
//STRUCUTURE OF A PROGRAM
/*

	The basic strucutre of a C++ program, all C++ programs contain:
		statements, 
		expressions,
		output/input,
		main function,
		standard library use,
		preprocessor directives


	Statements:
		-	smallest unit of code.
		-	specifies a task/instruction to the compiler.
		-	ends with semi-colon.
		-	types:
				Declaration statements:
					-	initialises variables/creates space in memory for variable of any data type.
							Eg: int x;
				Assignment statments:
					-	assigns a value to a variable of the same data type.
					-	can declare and assign in one statement (initalising the variable to a value).
							Eg:	x = 0;
								float pi = 3.14;
				Output/Input statements:
					-	output/input a value/char/data type
							Eg:	char c = "a";
								std::cout << c << endl;

	Expressions:
		-	mathematical entites that evaluate to a value.
		-	compiler can resolve any expression written with correct syntax.
				Eg: int x = 2 + 3;
					// Evalutaes to 5
		-	brackets change order of evaluation
				Eg: int x = 10, y = 2;
					int n = (x + 3) + (2 + 5 * (x - (y + 5)));
						
						Order of evaluation:
							(y + 5) = (2 + 5) = 7;
							(x - (y + 5)) = (x - 7) = (10 - 7) = 3;
							5 * (x - (y + 5)) = 5(x - 7) = 5(3) = 15;
							(2 + 5 * (x - (y + 5)) = (2 + 15) = 17;
							(x + 3) = (10 + 3) = 13;
							(x + 3) + (2 + 5 * (x - (y  + 5)) = 17 + 13 = 30

	Main Function:
		-	every C++ program needs a main() function of data type int
		-	all code is executed here
		-	returns 0 if code is exectured successfully
		-	if main returns other integers, there is an error

	Preprocessor directives:
		-	modify source files before compiling,
		-	conditional: #ifdef,
		-	constants: #define,
		-	include header: #include
		-	#include "" or #include:
				Fetches header of specified name, copies code into source file.
				-	searches current/standard/given directiories.
	
	C++ standard library:
		-	bulit in c++ functionality - in header files 
		-	"<iostream>" header directive/file: 
			-	part of the c++ standard library.
			-	allows input/ouput to the console/screen - using std object.
			-	contains:
					std::cout -  standard output
					std::cin - standard input
					std::cerr - standard error
					std:: clog - standard log
					std:: wcout - wide char output
					std:: wcin - wide char input
					std:: wcerr - wide char err
					std:: wclog - wide char log
			-	understands any communication via output "<<" and input ">>" operators.	

*/
//PREPROCESSOR DIRECTIVE - INCLUDE BASIC INPUT/OUTPUT OBJECT
#include <iostream>

//MAIN FUNCTION
int main() {

	//OUTPUT
	/*
		
		This is a standard output statement to the console.
			-	std::cout - gives access to "cout" - which is in the scope of the "std" namespace/class. 
			-	outputing a string literal, enclosed in the "" quote-symbols.
			-	"\n" - special string literal, creates new line in console.

		Note:
			-	The "::" - Binary scope resolution operator, allows access to members from a CLASS/NAMESPACE
			-	The "." - Dot operator, allows access to members from an object - that has been instantiated

	*/
	std::cout << "First C++ Program! Hello, World! " << "\n" << "\n";

	//STATEMENTS
	//DELCARTION STATEMENT
	int integer; 
	float floatingPointNumber;

	//ASSIGNMENT
	integer = 10;
	floatingPointNumber = 1.1618;

	//DECLARING AND ASSIGNING
	int integer2 = 789;

	//LARGEST AND SMALLEST REPRESENTABLE VALUES FOR STD INT AND FLOAT
	int smallestInt = -32676, largestInt = 32676;
	float smallestFloat = 0.000000, largestFloat = 340282346638528859811704183484516925440.000000;

	//OUTPUT
	//CAN GROUP COUT STATEMENTS LIKE THIS
	std::cout << "Integer 1: " << integer << "\n"
		<< "Integer 2: " << integer2 << "\n"
		<< "Sum of intergers: " << integer + integer2 << "\n"
		<< "Floating point number: " << floatingPointNumber << "\n" << "\n"
		<< "Min limit for type int: " << smallestInt << "\n"
		<< "Max limit for type int: " << largestInt << "\n"
		<< "Min limit for type float: " << smallestFloat << "\n"
		<< "Max limit for type float: " << largestFloat << "\n" << "\n";

	//INPUT
	int year = 2017, age = 0;
	std::cout << "Please enter your age - rounded to nearest integer: ";
	std::cin >> age;
	std::cout << "You were born in the year: " << year - age << "\n" << "\n";

	//EXPRESSIONS
	int x = 10, y = 2;
	int n = (x + 3) + (2 + 5 * (x - (y + 5)));
	std::cout << "The expression: (x + 3) + (2 + 5 * (x - (y + 5)))" << "\n"
       << "Where x = 10 and y = 2, n evaluates to: " << n << "\n" << "\n";

	//PAUSE SYSTEM
	// system("PAUSE"); SHOULD NOT BE USED
	std::cout << "Press any key to exit..." << "\n";
	std::cin.get();

	//DEBUG INTEGER RETURN
	return 0;

}