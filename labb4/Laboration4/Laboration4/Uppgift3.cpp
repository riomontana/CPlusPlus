#include "pch.h"
#include "Uppgift3.h"
#include <algorithm>
#include <iostream>
#include "time.h"
using namespace std;


bool Even(int i) { return i % 2 == 0; }

// Lösning på Laboration 4 uppgift 3: ta bort alla jämna tal
void Uppgift3::removeAddNumbers()
{
	cout << "Före borttaging av jämna nummer:" << endl << endl;

	// sätt seed till current time för att undvika att samma tal genereras
	srand(time(0));
	// skapa array för 10 element
	int arrayNums[10];
	// variabel som håller storleken på array
	int arraySize = sizeof(arrayNums) / sizeof(*arrayNums);
	// pekarvariabel för början av array
	int *ptrBegin = arrayNums;
	// pekarvariabel för slut av array
	int *ptrEnd = arrayNums + sizeof(arrayNums) / sizeof(int);

	// sätt in slumpmässiga tal i array och skriv ut dem
	for (int i = 0; i != arraySize; i++)
	{
		int randomNbr = rand() % 100;
		arrayNums[i] = randomNbr;
		cout << arrayNums[i] << endl;
	}

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	// ta bort alla jämna tal i array
	ptrEnd = remove_if(ptrBegin, ptrEnd, Even);

	cout << "Efter borttagning av jämna nummer:" << endl << endl;

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
