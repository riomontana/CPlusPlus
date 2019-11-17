#include "pch.h"
#include "Uppgift3.h"
#include <algorithm>
#include <iostream>
#include "time.h"
using namespace std;


bool Even(int i) { return i % 2 == 0; }

// L�sning p� Laboration 4 uppgift 3: ta bort alla j�mna tal
void Uppgift3::removeAddNumbers()
{
	cout << "F�re borttaging av j�mna nummer:" << endl << endl;

	// s�tt seed till current time f�r att undvika att samma tal genereras
	srand(time(0));
	// skapa array f�r 10 element
	int arrayNums[10];
	// variabel som h�ller storleken p� array
	int arraySize = sizeof(arrayNums) / sizeof(*arrayNums);
	// pekarvariabel f�r b�rjan av array
	int *ptrBegin = arrayNums;
	// pekarvariabel f�r slut av array
	int *ptrEnd = arrayNums + sizeof(arrayNums) / sizeof(int);

	// s�tt in slumpm�ssiga tal i array och skriv ut dem
	for (int i = 0; i != arraySize; i++)
	{
		int randomNbr = rand() % 100;
		arrayNums[i] = randomNbr;
		cout << arrayNums[i] << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	// ta bort alla j�mna tal i array
	ptrEnd = remove_if(ptrBegin, ptrEnd, Even);

	cout << "Efter borttagning av j�mna nummer:" << endl << endl;

	// skriv ut alla kvarvarande element
	for (int *pit = ptrBegin; pit != ptrEnd; ++pit)
	{
		cout << *pit << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;
}

Uppgift3::Uppgift3()
{
}


Uppgift3::~Uppgift3()
{
}
