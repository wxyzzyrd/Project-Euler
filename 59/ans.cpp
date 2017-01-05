#include <iostream>
#include <fstream> //File stream
#include <cstdlib> //Gives exit()
#include <string>
#include <vector>
#include <array>

using namespace std;

//That's a lie. This first function will print the contents o' th' file
void printFile(char* inf) {
	//Convert char* of file path to ifstream var
	ifstream file (inf, ifstream::in); //This is the weirdest declaration.
	if (!file) {
		cerr << "Could not read file!! xD\n";
		exit(EXIT_FAILURE);
	}
	//While the file is opened, print every line to stdout
	while (file) {
		string strInput;
		getline(file, strInput);
		cout << strInput << endl;
	}
}

//Aahaa! Let's convert the csv data to actual usable stuff
vector<string> getCSVs(char* inf) {
	//Convert char* of file path to ifstream var
	ifstream file (inf, ifstream::in);
	if (!file) {
		cerr << "Could not read file!! xD\n";
		exit(EXIT_FAILURE);
	}
	vector<string> CSV;
	while (file) {
		string strInput;
		// The last input in getLine() is the delim character.
		// It must be single quoted to denote that it is a character const, not
		// a string literal.
		getline(file, strInput, ',');
		CSV.push_back(strInput);
	}
	return CSV;
}

void bruteImpl(char abc[], int lenPass) {
	for ( i : abc ) {

	}
	return bruteImpl(abc, lenPass - 1)
}
// Herein lies the function that even God fears -- the terrible, ghastly
// brute force.
void bruteForce(vector<string> CSV, int lenPass) {
	if (lenPass < 0) {
		cerr << "Invalid pass length!\n";
		exit(EXIT_FAILURE);
	}
	// recursively generate every combo of abcs starting with 1 going to x

	}
	return bruteForce()
}

//Let's actually utilize the command line parameters
int main(int argc, char* argv[]) {
	//Let's define our characters
	vector<char> abc = "abcdefghijklmnopqrstuvwxyz";
	// If there are less than two arguments (which is one and the program)
	if ( argc > 2 ) {
		cerr << "Too many arguments!\n";
		exit(EXIT_FAILURE);
	}
	if ( argc < 2 ) {
		cerr << "Specify a file path!\n";
		exit(EXIT_FAILURE);
	}
	//Read teh fil3 that's inputt3d
	//printFile(argv[1]);
	for ( value : getCSVs(argv[1]) ) {
		std::cout << value;
	}
	return 0;
}
