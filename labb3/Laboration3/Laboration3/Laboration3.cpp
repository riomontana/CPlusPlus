// Laboration3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Laboration3.h"
#include "PersonReg.h";
#include <fstream>
#include <string>

bool readReg(PersonReg& reg, std::string fileName);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	locale::global(std::locale("swedish"));

	// Uppgift 1: Personregister
	cout << "- Uppgift 1: Personregister -" << endl << endl;

	// skapa register från fil 
	cout << "Läsa in personer från fil: " << endl << endl;
	int registerSize = 10;
	PersonReg* reg = new PersonReg(registerSize);
	string fileName = "E:/Skola/c++/laborationer/labb3/Laboration3/PersonExempel.txt";
	readReg(*reg, fileName);
	reg->printAllPersons();
	cout << "----------------------------------------------------------------------------" << endl << endl;

	// lägga till person
	cout << "Lägga till person:" << endl << endl;
	Person* testPerson1 = new Person("Linus Forsberg", "Rönnblomsgatan 11, 21422 Malmö");
	Person* testPerson2 = new Person("Mia Löfstedt", "Möllevångstorget 6D, 21216 Ankeborg");
	reg->addPerson(testPerson1);
	reg->addPerson(testPerson2);
	reg->printAllPersons();
	cout << "----------------------------------------------------------------------------" << endl << endl;
	// ta bort person
	cout << "Ta bort person:" << endl << endl;
	reg->deletePerson(&Person("Gustav Sandberg", "Hagag 77, 443 65  STENKULLEN"));
	reg->deletePerson(&Person("Göran Person", "Regeringsgatan 3, 12345 STHLM"));
	reg->printAllPersons();
	cout << "----------------------------------------------------------------------------" << endl << endl;

	// söka efter person via namn
	cout << "Söka efter person via namn: " << endl << endl;
	Person* searchTest1 = reg->findPersonByName("Linus Forsberg");
	searchTest1->print();
	Person* searchTest2 = reg->findPersonByName("Göran Persson");
	searchTest2->print();
	cout << "----------------------------------------------------------------------------" << endl << endl;

	// Uppgift 2: Fritextsökning
	cout << "- Uppgift 2: Fritextsökning -" << endl << endl;
	cout << "Sökning efter sson" << endl << endl;
	Person* x1 = reg->findPersonByText("sson", nullptr); //x1 blir första träffen
	Person* x2 = reg->findPersonByText("sson", x1); //x2 blir andra träffen
	Person* x3 = reg->findPersonByText("sson", x2); //x3 blir tredje träffen
	cout << "----------------------------------------------------------------------------" << endl << endl;

	// Uppgift 3: Arv
	cout << "- Uppgift 3: Arv -" << endl << endl;
	// person med tel-nr
	Person* personMedTel = new PersonMedTel("Leif Johansson","Strågatan 25, 44144 Partille","0765-778899");
	cout << "Print person med tel-nr:" << endl << endl;
	personMedTel->print();

	reg->addPerson(personMedTel);
	reg->printAllPersons();
	cout << "----------------------------------------------------------------------------" << endl << endl;

	// deallokera objekt från heapen
	delete testPerson1;
	delete testPerson2;
	delete searchTest2;
	delete personMedTel;
	delete reg;
}

bool readReg(PersonReg& reg, string fileName) {
	string line;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			while (line.length() == 0 && getline(myfile, line));
			string name(line);
			string adress;
			getline(myfile, adress);
			reg.addPerson(&Person(name, adress));
		}
		myfile.close();
		return true;
	}
	else {
		cout << "Unable to open file";
		return false;
	}
}

Laboration3::Laboration3()
{
}


Laboration3::~Laboration3()
{
}
