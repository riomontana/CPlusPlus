#include "pch.h"
#include <iostream>
#include <string>
#include "Uppgift3.h"
using namespace std;

// L�sning f�r Laboration 2, uppgift 3

char* Uppgift3::substitute_cstr(char* const input, const char before, char* const after)
{
	size_t inputLength = strlen(input);
	int counter = 0;

	// r�kna hur m�nga g�nger before f�rekommer i input
	for (int i = 0; i < inputLength; i++)
	{
		if (input[i] == before)
		{
			counter++;
		}
	}

	size_t afterLength = strlen(after);

	// ta reda p� hur l�ng den nya str�ngen m�ste vara
	size_t newStrLength = (inputLength + (counter*afterLength) - counter);

	// allokering p� heapen d� storlek p� str�ng �r ok�nd vid runtime
	char* const newStr = new char[newStrLength + 1];

	// iterera genom str�ngen och s�tt in r�tt tecken i den nya str�ngen
	for (int i = 0, k = 0; input[i] != '\0'; i++)
	{
		// om before finns i input
		if (input[i] == before)
		{
			// s�tt in after i den nya str�ngen
			for (int j = 0; j < afterLength; j++)
			{
				newStr[k++] = after[j];
			}
		}
		// annars s�tt in de gamla tecknen
		else
		{
			newStr[k++] = input[i];
		}
	}
	newStr[newStrLength] = '\0';

	return newStr;
}