#pragma once
#include "Person.h"
#include "PersonMedTel.h"
using namespace std;

class PersonReg
{
public:
	PersonReg(int maxSize);
	~PersonReg();
	void addPerson(Person* person);
	void deletePerson(Person* person);
	Person* findPersonByName(string name);
	Person* findPersonByText(string name, Person* person);
	void printAllPersons();

	// lab 4
	Person* begin();
	Person* end();


private:
	Person* personer; // pekare till själva registret
	int nbrOfPersons;
	int maxSize;
};



