#include "pch.h"
#include <iostream>
#include <string>
#include "Uppgift3.h"
using namespace std;

// Lösning för Laboration 2, uppgift 3

char* Uppgift3::substitute_cstr(char* const input, const char before, char* const after)
{
	size_t inputLength = strlen(input);
	int counter = 0;

	// räkna hur många gånger before förekommer i input
	for (int i = 0; i < inputLength; i++)
	{
		if (input[i] == before)
		{
			counter++;
		}
	}

	size_t afterLength = strlen(after);

	// ta reda på hur lång den nya strängen måste vara
	size_t newStrLength = (inputLength + (counter*afterLength) - counter);

	// allokering på heapen då storlek på sträng är okänd vid runtime
	char* const newStr = new char[newStrLength + 1];

	// iterera genom strängen och sätt in rätt tecken i den nya strängen
	for (int i = 0, k = 0; input[i] != '\0'; i++)
	{
		// om before finns i input
		if (input[i] == before)
		{
			// sätt in after i den nya strängen
			for (int j = 0; j < afterLength; j++)
			{
				newStr[k++] = after[j];
			}
		}
		// annars sätt in de gamla tecknen
		else
		{
			newStr[k++] = input[i];
		}
	}
	newStr[newStrLength] = '\0';

	return newStr;
}