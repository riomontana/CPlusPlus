#include "pch.h"
#include <iostream>
#include "Uppgift1.h"
using namespace std;

// Lösning för Laboration 2, uppgift 1: Skriv ut alla primtal från 2 - N

void Uppgift1::printPrimes()
{
	int n = 100; // n antal tal
	int size = n - 1; // storlek på arrayen ska vara från 2 till n dvs n-1 element
	int *primes = new int[size]; // allokera minne på heapen då antal element är okänt vid runtime
	int number = 2; // tal som används vid heltalsdivision för att stryka ut tal som inte är primtal

	// 	1. Gör en lista över alla tal från två till n.
	for (int i = 0; i < size; i++)
	{
		primes[i] = i + number; // lägg in element i listan från 2 upp till n
	}

	//	2. Stryk ut från listan alla jämna tal som är större än två (4, 6, 8 osv.).
	for (int i = 1; i < size; i++) // räknare börjar på 1 för att hoppa över första elementet som är 2.
	{
		// alla element som inte får någon rest vid heltalsdivision med 2 sätts till noll
		if (primes[i] % number == 0)
		{
			primes[i] = 0;
		}
	}

	// nummer som används för heltalsdivision inkrementeras med ett
	number++;

	//	5. Upprepa stegen 3 och 4 tills du har nått ett nummer som är större än
	// 	   kvadratroten av n(det största talet i listan).	
	while (number < sqrt(size))
	{
		//  3. Listans nästa tal som inte är utstruket är ett primtal.
		//	4. Stryk ut alla tal, som är både större än det primtalet du hittade i föregående
		//     steget och multiplar av det.
		for (int i = number; i < size; i++)
		{
			// alla element som inte får någon rest vid heltalsdivision med number sätts till noll
			if (primes[i] % number == 0)
			{
				primes[i] = 0;
			}
		}
		// nummer som används för heltalsdivision inkrementeras med ett
		number++;
	}

	//  6. Alla kvarstående tal i listan är primtal.
	for (int i = 0; i < size; i++)
	{
		// skriver ut alla element som inte blivit satta till noll
		if (primes[i] != 0)
			cout << primes[i] << endl;
	}

	delete[] primes; // deallokera minne från heapen
}

