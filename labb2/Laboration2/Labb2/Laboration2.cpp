// Labb2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Uppgift1.h"
#include "Uppgift2.h"
#include "Uppgift3.h"
#include <iostream>
#include <string>
using namespace std;

// Main metod för testning av uppgifterna 1 - 3

int main()
{
	#ifndef DBG_NEW
_	CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif

	locale::global(locale("swedish"));

	// Testkörning av uppgift 1:

	Uppgift1 test1;
	cout << endl << "Laboration 2:" << endl << endl << "Uppgift 1: skriv ut alla primtal mellan 2 till N" << endl << endl;
	test1.printPrimes();
	cout << endl << "--------------------------------------------------------------------------------" << endl;

	// Testkörning av uppgift 2:

	Uppgift2 test2;
	cout << "Uppgift 2: Strängmanipulation med std::string" << endl << endl;
	string str("Hejjj");
	cout << "Sträng före manipulation: " << str << endl << endl;
	test2.substitute_str(str, "ej", "eje");
	cout << "Sträng efter manipulation: " << str << endl << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	// Testkörning av uppgift 3:

	Uppgift3 test3;
	cout << "Uppgift 3: Manipulation med char*" << endl << endl;
	char str2[] = "Hejjj";
	cout << "Sträng före manipulation: " << str2 << endl << endl;
	char str3[] = "eje";
	char* const strEdited = test3.substitute_cstr(str2, 'e', str3);
	cout << "Sträng efter manipulation: " << strEdited << endl << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	delete[] strEdited; // deallokera sträng på heapen

	return 0;
}