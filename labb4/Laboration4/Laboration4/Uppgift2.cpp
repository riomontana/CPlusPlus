#include "pch.h"
#include "Uppgift2.h"
#include "PersonReg/PersonReg.h"
#include <algorithm>
#include <time.h>

// Uppgift 2a: sortera personregister efter namn
void Uppgift2::sortPersonRegByName()
{
	// skapa personregister med plats för 10 personer
	PersonReg* reg = new PersonReg(10);
	// lägg till personer i registret
	reg->addPerson(&Person("Linus","Sagagatan 11"));
	reg->addPerson(&Person("Mia", "Polisgatan 15"));
	reg->addPerson(&Person("Roger", "Aspgatan 18"));
	reg->addPerson(&Person("Gun-Britt", "Magasinsgatan 25"));
	reg->addPerson(&Person("Gun-Britt", "Bingogatan 11"));
	reg->addPerson(&Person("Linus", "Ostgatan 13"));
	reg->addPerson(&Person("Mia", "Gågatan 11"));
	reg->addPerson(&Person("Roger", "Långgatan 23"));
	reg->addPerson(&Person("Linus", "Korvgatan 1"));
	reg->addPerson(&Person("Mia", "Dillgatan 1"));

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	// sätt seed till current time för att inte få samma random shuffle varje gång
	srand(time(0));
	// randomisera personregistret
	random_shuffle(reg->begin(),reg->end());

	cout << "Randomiserat personregister:" << endl << endl;

	// skriv ut randomiserat personregister
	reg->printAllPersons();

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	cout << "Sorterat personregister:" << endl << endl;

	// sortera personregister
	sort(reg->begin(), reg->end());
	// skriv ut sorterat personregister
	reg->printAllPersons();

	cout << endl << "---------------------------------------------------------------" << endl << endl;
}

// Uppgift 2b: sortera baklänges efter address 
void Uppgift2::sortPersonRegByAddressDesc()
{
	cout << "Uppgift 2b: Sortera baklänges efter address" << endl << endl;

	// skapa personregister med plats för 10 personer
	PersonReg* reg = new PersonReg(10);
	// lägg till personer i registret
	reg->addPerson(&Person("Linus", "Sagagatan 11"));
	reg->addPerson(&Person("Mia", "Polisgatan 15"));
	reg->addPerson(&Person("Roger", "Aspgatan 18"));
	reg->addPerson(&Person("Gun-Britt", "Magasinsgatan 25"));
	reg->addPerson(&Person("Gun-Britt", "Bingogatan 11"));
	reg->addPerson(&Person("Linus", "Ostgatan 13"));
	reg->addPerson(&Person("Mia", "Gågatan 11"));
	reg->addPerson(&Person("Roger", "Långgatan 23"));
	reg->addPerson(&Person("Linus", "Korvgatan 1"));
	reg->addPerson(&Person("Mia", "Dillgatan 1"));

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	// sätt seed till current time för att inte få samma random shuffle varje gång
	srand(time(0));
	// randomisera personregistret
	random_shuffle(reg->begin(), reg->end());

	cout << "Randomiserat personregister:" << endl << endl;

	// skriv ut randomiserat personregister
	reg->printAllPersons();

	cout << endl << "---------------------------------------------------------------" << endl << endl;

	cout << "Sorterat personregister:" << endl << endl;

	// sortera personregister
	sort(reg->begin(), reg->end());
	// skriv ut sorterat personregister
	reg->printAllPersons();

	cout << endl << "---------------------------------------------------------------" << endl << endl;
}

Uppgift2::Uppgift2()
{
}


Uppgift2::~Uppgift2()
{
}
