// Laboration4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include "Uppgift1.h"
#include "Uppgift2.h"
#include "Uppgift3.h"
using namespace std;

// Testkörning av laboration4
int main()
{
	locale::global(locale("swedish"));

	cout << endl << "Laboration 4:" << endl << endl;

	// Uppgift 1
	Uppgift1 uppgift1;

	// Testkörning av uppgift 1a
	cout << "Uppgift 1a: sortera vector" << endl << endl;
	uppgift1.vectorSort();

	// Testkörning av uppgift 1b
	cout << "Uppgift 1b: sortera c-array" << endl << endl;
	uppgift1.cArraySort();

	// Testkörning av uppgift 1c
	cout << "Uppgift 1c: sortera vector i sjunkande ordning" << endl << endl;
	uppgift1.vectorSortDesc();

	// Testkörning av uppgift 1d
	cout << "Uppgift 1d: sortera c-array i sjunkande ordning" << endl << endl;
	uppgift1.cArraySortDesc();

	// Uppgift 2
	Uppgift2 uppgift2;
	
	// Testkörning av uppgift 2a
	uppgift2.sortPersonRegByName();

	// Testkörning av uppgift 2b
	//uppgift2.sortPersonRegByAddressDesc(); // OBS: avmarkera i Person också

	// Uppgift 3
	Uppgift3 uppgift3;

	// Testkörning av uppgift 3
	uppgift3.removeAddNumbers();
}
