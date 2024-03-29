// Laboration6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "MathInterpreter.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	cout << " - M@ interpreter - " << endl << endl;

	string line;
	stringstream ss(line);

	// Input from file
	ifstream test_file;
	test_file.open("Lab6_Test.txt");

	if (test_file.is_open()) {
		while (!test_file.eof()) {
			getline(test_file, line);
			ss << line << "\n";
		}
	}
	test_file.close();

	// Input from console
	/*while (getline(cin, line))
		ss << line << "\n";*/

	MathInterpreter mathInterpreter(ss);
}

