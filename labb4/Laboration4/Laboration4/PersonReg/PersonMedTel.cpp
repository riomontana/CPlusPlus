#include "pch.h"
#include "PersonMedTel.h"
#include "Person.h"
#include <string>

using namespace std;

string telNr;

string PersonMedTel::getTelNr()
{
	return telNr;
}

void PersonMedTel::print()
{
	cout << "Person: " << Person::getNameAddress() << ", Telnr: " << telNr << endl << endl;
}

