#pragma once
#include <string>
using namespace std;

class Person
{
public:
	Person() : name(""), address("") {}
	Person(string name, string address);
	virtual ~Person();
	virtual void print();
	string getName();
	string getAddress();
	string getNameAddress();
	bool operator<(const Person& that); // labb 4 uppgift 2a och 2b
private:
	string name;
	string address;
};
