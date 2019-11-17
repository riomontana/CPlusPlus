#include "pch.h"
#include "PersonReg.h"
#include <string>

using namespace std;

int maxSize; // max storlek f�r personregister
int nbrOfPersons; // antalet personer som finns i register
Person* persons; // pekare f�r personregister

// konstruktor
PersonReg::PersonReg(int maxSize)
{
	this->maxSize = maxSize;
	this->nbrOfPersons = 0;

	// Allokera p� heap
	persons = new Person[maxSize];
}

// destruktor
PersonReg::~PersonReg()
{
	// Deallokering av heap
	delete[] persons;
}

// metod f�r att skriva ut alla personer i registret
void PersonReg::printAllPersons()
{
	cout << endl << "Print person register:" << endl << endl << "Number of persons: " << nbrOfPersons << endl << endl;

	// itererar igenom alla element i registret med hj�lp av pekare
	for (Person* personPtr = persons; personPtr != persons + nbrOfPersons; ++personPtr)
	{
		personPtr->print(); // anropar print-metoden i klassen Person som skriver ut en persons namn och address
	}
}

// metod f�r att s�ka efter en person via namn
Person* PersonReg::findPersonByName(string name)
{
	Person* foundPerson = 0; // pekare f�r person som ska hittas

	// loopar igenom array med hj�lp av pekare
	for (Person* personPtr = persons; personPtr != persons + nbrOfPersons; ++personPtr)
	{
		// om elementet som pekar-iteratorn pekar p� har samma namn som det som skickats med som parameter har r�tt person hittats
		if (personPtr->getName() == name)
		{
			foundPerson = personPtr; // s�tter found person pekaren till r�tt pekare
			cout << "Found person: " << foundPerson->getName() << endl << endl; // skriver ut info till anv�ndaren
		}
	}
	// om ingen person hittats
	if (foundPerson == 0)
	{
		cout << "No person found." << endl << endl; // skriv ut info till anv�ndaren
		foundPerson = new Person("", "");
	}
	return foundPerson; // returnera pekare till den hittade personen
}

// metod f�r att s�ka efter person via fritext
Person* PersonReg::findPersonByText(string searchString, Person* foundPerson)
{	
	string strToCompare; // tempor�r str�ng som ska j�mf�ras med s�kstr�ngen
	size_t foundPos; // position f�r den hittade str�ngen vid matchning

	// om inte pekaren som skickas in via parameter �r en nullpointer
	if (foundPerson != 0)
	{
		foundPerson = (foundPerson)+1; // �ka pekare med ett s� inte samma person returneras som f�rra g�ngen
	}
	// annars s�tt pekare till persons f�r att iterera fr�n b�rjan
	else
	{
		foundPerson = persons;
	}

	// iterera genom array genom att anv�nda pekare
	// ist�llet f�r att s�tta personPtr till persons s�tts den till foundPersons ifall hela arrayen inte ska g�s igenom 
	for (Person* personPtr = foundPerson; personPtr != persons + nbrOfPersons; ++personPtr)
	{
		strToCompare = personPtr->getNameAddress(); // tempor�r str�ng som ska j�mf�ras h�mtas fr�n element som personPtr pekar p�
		foundPos = strToCompare.find(searchString); // tempor�r str�ng j�mf�rs med fritextstr�ng som skickas in via parameter, s�tts till npos om ingen matchning.
		
		// om foundPos inte �r nPos, dvs matchning har hittats i tempor�r str�ng
		if (foundPos != string::npos)
		{
			foundPerson = personPtr; // s�tt foundPerson till aktuell pekare i iterationen.
			cout << "Found person: " << foundPerson->getName() << endl << endl; // skriver ut info till anv�ndaren
			return foundPerson; // returnerar pekaren till den funna personen
		}
	}
	return 0; // returnerar nullpointer om ingen matchning hittas
}

// metod f�r att l�gga till person i register
void PersonReg::addPerson(Person* person)
{
	// kollar om person g�r att casta till personMedTel
	PersonMedTel* persMedTel = dynamic_cast<PersonMedTel*>(person);
	
	// platsen efter sista elementet i arrayen s�tts till det element som parameter-pekaren pekar p�
	persons[nbrOfPersons] = *person;

	// om person �r persMedTel skrivs namn, address och telefonnummer ut
	if (persMedTel)
	{
		cout << "Person added: " << persMedTel->getNameAddress() << ", Tel: " << persMedTel->getTelNr() << endl << endl;
	}
	// annars skrivs endast namn och address ut
	else
	{
		cout << "Person added: " << person->getNameAddress() << endl << endl;
	}
	nbrOfPersons++; // inkrementerar r�knaren f�r det totala antalet personer i registret med ett
}

// metod f�r att ta bort person ur register
void PersonReg::deletePerson(Person* person)
{
	Person* personToDelete = 0; // pekare f�r person som ska tas bort
	int index = 0; // r�knare f�r index d�r person ska tas bort

	// itererar igenom arrayen med personer med hj�lp av pekare
	for (Person* personPtr = persons; personPtr != persons + nbrOfPersons; ++personPtr)
	{
		// om pekariteratorns element har samma namn och address som pekarens element som skickats med som parameter
		if (personPtr->getNameAddress() == person->getNameAddress())
		{	
			personToDelete = personPtr; // s�tt personToDelete till iteratorpekaren 
			break; // hoppa ur loopen n�r r�tt person hittats
		}
		index++; // r�knare inkrementeras tills r�tt person hittats
	}

	// om pekaren inte �r 0 s� har en person hittats som ska tas bort
	if (personToDelete != 0)
	{
		cout << "Person deleted: " << personToDelete->getNameAddress() << endl << endl; // info till anv�ndare
		// itererar igenom person arrayen fr�n index som ska bytas ut tills index �r lika med antalet personer i arrayen
		while(index != nbrOfPersons)
		{
			persons[index] = persons[index + 1]; // elementet p� index som ska tas bort ers�tts med elementet som ligger p� platsen efter
			index++; // inkrementerar r�knare
		}
		nbrOfPersons--; // slutligen minskar r�knaren f�r det totala antalet personer i arrayen med ett
	}
	else
	{
		cout << "There is no " << person->getName() << " to delete" << endl << endl; // info till anv�ndare
	}
}



