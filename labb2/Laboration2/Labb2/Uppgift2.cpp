#include "pch.h"
#include <iostream>
#include <string>
#include "Uppgift2.h"
using namespace std;

// Lösning för Laboration 2, uppgift 2

void Uppgift2::substitute_str(std::string& iostring, const std::string& before, const std::string& after)
{
	// hitta position för första förekomsten av substring
	size_t pos = iostring.find(before);

	// iterera till slutet av strängen
	while (pos != string::npos)
	{
		// ersätt från positionen för förekomst av substring med ny substring
		iostring.replace(pos, before.length(), after);

		// hitta nästa position av substring från nuvarande position
		pos = iostring.find(before, pos + after.size());
	}
}

