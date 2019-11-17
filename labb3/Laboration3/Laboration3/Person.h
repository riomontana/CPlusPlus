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
private:
	string name;
	string address;
};
