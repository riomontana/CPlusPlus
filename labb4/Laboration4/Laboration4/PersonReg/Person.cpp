#include "pch.h"
#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

string name;
string address;

Person::Person(string name, string address)
{
	this->name = name;
	this->address = address;
}

Person::~Person()
{
}

string Person::getNameAddress()
{
	return name + ", " + address;
}

string Person::getName()
{
	return name;
}

string Person::getAddress()
{
	return address;
}

void Person::print()
{
	if (name != "" && address != "")
	{
		cout << "Name: " << name << ", Address: " << address << endl << endl;
	}
	else
	{
		cout << "Nothing to print" << endl << endl;
	}
}

// Labb 4, uppgift 2a
bool Person::operator<(const Person& that)
{
	return this->name < that.name;
}

// Labb 4, uppgift 2b
//bool Person::operator<(const Person& that)
//{
//	return this->address > that.address;
//}


