#include "pch.h"
#include "String.h"
#include <cassert>
using namespace std;

// konstruktor
String::String()
{
	String("");
	Invariant(); // anropa i slutet på konstruktor
}

// konstruktor
String::String(const String& rhs)
{
	*this = rhs;
	Invariant(); // anropa i slutet på konstruktor
}

//För teständamål
String::String(const char* cstr)
{
	strCapacity = (sizeof(cstr) / sizeof(char));
	string = new char[strCapacity];

	int i = 0;
	while (cstr[i] != '\0')
	{
		push_back(cstr[i]);
		i++;
	}

	Invariant(); // anropa i slutet på konstruktor
}

String& String::operator=(const String& rhs)
{
	if (&rhs != this)
	{
		if (string)
			delete[] string;

		strSize = rhs.size();
		strCapacity = rhs.capacity();
		string = new char[strCapacity];

		for (int i = 0; i < rhs.size(); i++)
			string[i] = rhs[i];
	}
	return *this;
}

//indexerar utan range check
char& String::operator[](size_t i)
{
	return string[i];
}

//indexerar utan range check
const char& String::operator[](size_t i) const
{
	return string[i];
}

//Hur många tecken i strängen
size_t String::size() const
{
	return strSize;
}

//Hur mycket plats finns det
size_t String::capacity() const
{
	return strCapacity;
}

//lägger till ett tecken sist
void String::push_back(char c)
{
	if (size() == 0)
		allocMemory(1);
	else if (size() >= capacity())
		allocMemory(capacity() * 2);

	string[strSize++] = c;
}

//global function
bool operator==(const String& lhs, const String& rhs)
{
	// return lhs == rhs
	return equal(lhs.string, lhs.string + lhs.size(), rhs.string);
}

//global function
bool operator!=(const String& lhs, const String& rhs)
{
	return lhs != rhs;
}

//För testning : Ger en pekare till arrayen som innehåller strängen.
const char* String::data() const
{
	return string;
}

//För testning
std::ostream& operator<< (std::ostream& out, const String& rhs)
{
	for (size_t i = 0; i < rhs.size(); ++i)
		out << rhs[i];
	return out;
}

//Allokera minne på heapen
void String::allocMemory(size_t length)
{
	strCapacity = length;

	// allokera minne för temporär sträng
	char* tempStr = new char[strCapacity];

	// kopiera från string till tempString
	for (int i = 0; i < strSize; i++)
		tempStr[i] = string[i];

	// deallokera minne för föregående container
	if (string)
		delete[] string;

	// allokera minne för ny string
	string = new char[strCapacity];

	// kopiera tecken från tempStr till string
	for (int i = 0; i < strSize; i++)
		string[i] = tempStr[i];

	// deallokera minne för tempStr
	delete[] tempStr;
}

//Destruktor
String::~String()
{
	Invariant(); // anropa i början på destruktor
	delete[] string; // deallokera minne från heapen
}

void String::Invariant()
{
	assert(strSize <= strCapacity);
}
