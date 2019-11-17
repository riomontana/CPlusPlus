#include "pch.h"
#include "Uppgift1.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include "time.h"
using namespace std;

// Uppgift 1a: sortera vector
void Uppgift1::vectorSort()
{
	cout << "Före sortering:" << endl <<endl; 

	// sätt random seed till current time för att unvika att samma tal genereras
	srand(time(0));
	// skapa vector
	vector<int> vectorNums(10);

	// fyll vector med slumpmässiga tal och skriv ut dem
	for (vector<int>::iterator it = vectorNums.begin(); it != vectorNums.end(); it++)
	{
		int randNbr = rand() % 100;
		*it = randNbr;
		cout << *it << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	// sortering av vector
	sort(vectorNums.begin(), vectorNums.end());

	cout << "Efter sortering:" << endl << endl;

	// skriv ut sorterad vector
	for (auto v : vectorNums)
	{
		cout << v << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;
}

// Uppgift 1b: sortera c-array
void Uppgift1::cArraySort()
{
	cout << "Före sortering:" << endl << endl;

	// sätt random seed till current time för att unvika att samma tal genereras
	srand(time(0));
	// skapa array
	int arrayNums[10];
	// ta reda på storlek av array
	int arraySize = sizeof(arrayNums) / sizeof(*arrayNums);

	// fyll array med slumpmässiga tal och skriv ut dem
	for(int i = 0; i != arraySize; i++)
	{
		int randomNbr = rand() % 100;
		arrayNums[i] = randomNbr;
		cout << arrayNums[i] << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	// sortering av c-array
	sort(arrayNums, arrayNums + arraySize);

	cout << "Efter sortering:" << endl << endl;
	
	// skriv ut sorterad array
	for (int i = 0; i != arraySize; i++)
	{
		cout << arrayNums[i] << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;
}

// Uppgift 1c: sortera vector i sjunkande ordning
void Uppgift1::vectorSortDesc()
{
	cout << "Före sortering:" << endl << endl;

	// sätt random seed till current time för att unvika att samma tal genereras
	srand(time(0));
	// skapa vector
	vector<int> vectorNums(10);

	// fyll vector med slumpmässiga tal och skriv ut dem
	for (vector<int>::iterator it = vectorNums.begin(); it != vectorNums.end(); it++)
	{
		int randNbr = rand() % 100;
		*it = randNbr;
		cout << *it << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	// sortera vector i sjunkande ordning
	sort(vectorNums.rbegin(), vectorNums.rend());

	cout << "Efter sortering:" << endl << endl;

	// skriv ut sorterad vector
	for (auto v : vectorNums)
	{
		cout << v << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;

}

// jämförelse-funktion för uppgift 1d
bool Greater(int x, int y)
{
	return x > y;
}

// Uppgift 1d: sortera c-array i sjunkande ordning
void Uppgift1::cArraySortDesc()
{
	cout << "Före sortering:" << endl << endl;

	// skapa array
	int arrayNums[10];
	// storlek på array
	int arraySize = sizeof(arrayNums) / sizeof(*arrayNums);

	// fyll array med slumpmässiga tal och skriv ut dem
	for (int i = 0; i != arraySize; i++)
	{
		int randomNbr = rand() % 100;
		arrayNums[i] = randomNbr;
		cout << arrayNums[i] << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	// sortering av c-array i sjunkande ordning
	sort(arrayNums, arrayNums + arraySize, Greater);

	cout << "Efter sortering:" << endl << endl;

	// skriv ut sorterad array
	for (int i = 0; i != arraySize; i++)
	{
		cout << arrayNums[i] << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;

}

Uppgift1::Uppgift1()
{
}


Uppgift1::~Uppgift1()
{
}
