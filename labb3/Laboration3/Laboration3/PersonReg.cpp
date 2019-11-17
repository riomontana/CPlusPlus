#include "pch.h"
#include "PersonReg.h"
#include <string>

using namespace std;

int maxSize; // max storlek för personregister
int nbrOfPersons; // antalet personer som finns i register
Person* persons; // pekare för personregister

// konstruktor
PersonReg::PersonReg(int maxSize)
{
	this->maxSize = maxSize;
	this->nbrOfPersons = 0;

	// Allokera på heap
	persons = new Person[maxSize];
}

// destruktor
PersonReg::~PersonReg()
{
	// Deallokering av heap
	delete[] persons;
}

// metod för att skriva ut alla personer i registret
void PersonReg::printAllPersons()
{
	cout << endl << "Print person register:" << endl << endl << "Number of persons: " << nbrOfPersons << endl << endl;

	// itererar igenom alla element i registret med hjälp av pekare
	for (Person* personPtr = persons; personPtr != persons + nbrOfPersons; ++personPtr)
	{
		personPtr->print(); // anropar print-metoden i klassen Person som skriver ut en persons namn och address
	}
}

// metod för att söka efter en person via namn
Person* PersonReg::findPersonByName(string name)
{
	Person* foundPerson = 0; // pekare för person som ska hittas

	// loopar igenom array med hjälp av pekare
	for (Person* personPtr = persons; personPtr != persons + nbrOfPersons; ++personPtr)
	{
		// om elementet som pekar-iteratorn pekar på har samma namn som det som skickats med som parameter har rätt person hittats
		if (personPtr->getName() == name)
		{
			foundPerson = personPtr; // sätter found person pekaren till rätt pekare
			cout << "Found person: " << foundPerson->getName() << endl << endl; // skriver ut info till användaren
		}
	}
	// om ingen person hittats
	if (foundPerson == 0)
	{
		cout << "No person found." << endl << endl; // skriv ut info till användaren
		foundPerson = new Person("", "");
	}
	return foundPerson; // returnera pekare till den hittade personen
}

// metod för att söka efter person via fritext
Person* PersonReg::findPersonByText(string searchString, Person* foundPerson)
{	
	string strToCompare; // temporär sträng som ska jämföras med söksträngen
	size_t foundPos; // position för den hittade strängen vid matchning

	// om inte pekaren som skickas in via parameter är en nullpointer
	if (foundPerson != 0)
	{
		foundPerson = (foundPerson)+1; // öka pekare med ett så inte samma person returneras som förra gången
	}
	// annars sätt pekare till persons för att iterera från början
	else
	{
		foundPerson = persons;
	}

	// iterera genom array genom att använda pekare
	// istället för att sätta personPtr till persons sätts den till foundPersons ifall hela arrayen inte ska gås igenom 
	for (Person* personPtr = foundPerson; personPtr != persons + nbrOfPersons; ++personPtr)
	{
		strToCompare = personPtr->getNameAddress(); // temporär sträng som ska jämföras hämtas från element som personPtr pekar på
		foundPos = strToCompare.find(searchString); // temporär sträng jämförs med fritextsträng som skickas in via parameter, sätts till npos om ingen matchning.
		
		// om foundPos inte är nPos, dvs matchning har hittats i temporär sträng
		if (foundPos != string::npos)
		{
			foundPerson = personPtr; // sätt foundPerson till aktuell pekare i iterationen.
			cout << "Found person: " << foundPerson->getName() << endl << endl; // skriver ut info till användaren
			return foundPerson; // returnerar pekaren till den funna personen
		}
	}
	return 0; // returnerar nullpointer om ingen matchning hittas
}

// metod för att lägga till person i register
void PersonReg::addPerson(Person* person)
{
	// kollar om person går att casta till personMedTel
	PersonMedTel* persMedTel = dynamic_cast<PersonMedTel*>(person);
	
	// platsen efter sista elementet i arrayen sätts till det element som parameter-pekaren pekar på
	persons[nbrOfPersons] = *person;

	// om person är persMedTel skrivs namn, address och telefonnummer ut
	if (persMedTel)
	{
		cout << "Person added: " << persMedTel->getNameAddress() << ", Tel: " << persMedTel->getTelNr() << endl << endl;
	}
	// annars skrivs endast namn och address ut
	else
	{
		cout << "Person added: " << person->getNameAddress() << endl << endl;
	}
	nbrOfPersons++; // inkrementerar räknaren för det totala antalet personer i registret med ett
}

// metod för att ta bort person ur register
void PersonReg::deletePerson(Person* person)
{
	Person* personToDelete = 0; // pekare för person som ska tas bort
	int index = 0; // räknare för index där person ska tas bort

	// itererar igenom arrayen med personer med hjälp av pekare
	for (Person* personPtr = persons; personPtr != persons + nbrOfPersons; ++personPtr)
	{
		// om pekariteratorns element har samma namn och address som pekarens element som skickats med som parameter
		if (personPtr->getNameAddress() == person->getNameAddress())
		{	
			personToDelete = personPtr; // sätt personToDelete till iteratorpekaren 
			break; // hoppa ur loopen när rätt person hittats
		}
		index++; // räknare inkrementeras tills rätt person hittats
	}

	// om pekaren inte är 0 så har en person hittats som ska tas bort
	if (personToDelete != 0)
	{
		cout << "Person deleted: " << personToDelete->getNameAddress() << endl << endl; // info till användare
		// itererar igenom person arrayen från index som ska bytas ut tills index är lika med antalet personer i arrayen
		while(index != nbrOfPersons)
		{
			persons[index] = persons[index + 1]; // elementet på index som ska tas bort ersätts med elementet som ligger på platsen efter
			index++; // inkrementerar räknare
		}
		nbrOfPersons--; // slutligen minskar räknaren för det totala antalet personer i arrayen med ett
	}
	else
	{
		cout << "There is no " << person->getName() << " to delete" << endl << endl; // info till användare
	}
}



