#pragma once
#include "Person.h";
#include <iostream>
using namespace std;

class PersonMedTel : public Person
{
public:
	PersonMedTel(string name, string address, string telNr) : Person(name, address), telNr(telNr) {}
	PersonMedTel() : Person(), telNr("") {}
	void print();
	string getTelNr();

private:
	string telNr;
};
