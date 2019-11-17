#include "pch.h"
#include <iostream>
#include <string>
#include "Uppgift2.h"
using namespace std;

// L�sning f�r Laboration 2, uppgift 2

void Uppgift2::substitute_str(std::string& iostring, const std::string& before, const std::string& after)
{
	// hitta position f�r f�rsta f�rekomsten av substring
	size_t pos = iostring.find(before);

	// iterera till slutet av str�ngen
	while (pos != string::npos)
	{
		// ers�tt fr�n positionen f�r f�rekomst av substring med ny substring
		iostring.replace(pos, before.length(), after);

		// hitta n�sta position av substring fr�n nuvarande position
		pos = iostring.find(before, pos + after.size());
	}
}

