//FIRST C++ PROGRAM
/*

	First basic C++ program,
		- intro to program structure, pre-included libraries.
		- coded very basic algorthims - arithmetic, making a random string. 

*/

//INCLUDE 
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

//NAMESPACE
using namespace std;

//MAIN
int main() {

	//MY DETAILS
	int age = 21;
	string name = "Waqas";
	string loc = "London";
	
	//OUTPUT
	cout << "Hello Earth, my name is " + name << endl << "I am " + to_string(age) + " years old";

	//SOME ARITHMETIC
	//ADD
	int a = 10, b = 15;
	int sum = a + b;
	cout << endl << to_string(sum) << endl;

	//DIVISIBLITY
	srand(time(NULL));
	int r = rand() % 100;
	r = floor(r);
	
	if (r % 2 == 0) {
		cout << to_string(r) << " is an even number";
	} else {
		cout << to_string(r) << " is an odd number";
	}

	//RANDOM STRING
	string c = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string randstring = "";
	int len = 10;
	for (int l = 0; l < len; l++) {
		randstring += c[rand() % sizeof(c)];
	}
	cout << endl << randstring;

	//CHECK USER HITS ENTER
	/*
		Using system("PAUSE") is bad practice
			-	hack for IDE closing the window
	*/

	//ASK USER TO EXIT PROGRAM
	cout << endl << endl << "Hit enter to exit program.";
	
	cin.get();
	return 0;

}