#pragma once
#include <iostream>

class String
{
public:
	String();
	~String();
	String(const String& rhs);
	String(const char* cstr); //För teständamål
	String& operator=(const String& rhs);
	char& operator[](size_t i); //indexerar utan range check
	const char& operator[](size_t i) const; //indexerar utan range check
	size_t size() const; //Hur många tecken i strängen
	size_t capacity() const; //Hur mycket plats finns det
	void push_back(char c); //lägger till ett tecken sist
	friend bool operator==(const String& lhs, const String& rhs); //global function
	friend bool operator!=(const String& lhs, const String& rhs); //global function
	const char* data() const; //För testning : Ger en pekare till arrayen som innehåller strängen.
	friend std::ostream& operator<<(std::ostream& out, const String& rhs); //För testning, se nedan för kodexempel.
	void allocMemory(size_t length);
private:
	char *string = 0;
	size_t strSize = 0;
	size_t strCapacity = 1;
	void Invariant();
};

