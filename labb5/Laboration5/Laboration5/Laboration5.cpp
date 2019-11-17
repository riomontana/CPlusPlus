// Laboration5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
#include <stdlib.h>
#include <crtdbg.h>
#include "String.h"
#include <string>
#include <iostream>
#include <cassert>
#include <utility>
using namespace std;

void AssertStrEqual(String lhs,const char* rhs) {
	for (size_t i = 0; i < lhs.size() && *rhs != '\0'; ++i) {
		assert(lhs[i] == rhs[i]);
		assert(rhs[i] != 0);
	}
	assert(rhs[lhs.size()] == 0);
}

	void TestPushBackReallocation() {
		String str("hej");
		assert(str.size() <= str.capacity());
		assert(str.size() == 3);
		auto hej = "hej";
		AssertStrEqual(str, hej);
		AssertStrEqual(str, "hej");
	
		auto internalBuf = &str[0];
		auto cap = str.capacity();
		auto siz = str.size();
		size_t i;
		for (i = siz + 1; i <= cap; ++i) {
			str.push_back(char(i) + 'a');
			assert(internalBuf == &str[0]);
			assert(cap == str.capacity());
			assert(i == str.size());
		}
		str.push_back(char(i));
		assert(internalBuf != &str[0]);
		assert(cap < str.capacity());
		assert(i == str.size());
	}

void TestFörGodkäntString() {
	//-	String()
	String str0;	AssertStrEqual(str0, "");

	//-	String(Sträng sträng)
	String s1("foo"); assert(s1 == "foo");
	String str(s1); assert(str == "foo");
	String s3("bar");  assert(s3 == "bar");

	//-	~String() Kom ihåg destruktorn!
	delete new String("hej");

	//	-	operator =(Sträng sträng)
	str = "hej";
	assert((str = s3) == s3);
	assert((str = str) == s3);	//self assignment

	//Ej samma buffert
	str = "hej"; s3 = str;
	str[0] = 'x'; assert(s3[0] == 'h');
	s3[1] = 'y'; assert(str[1] == 'e');


	String str1("foo"), str2("bar"), str3("hej");
	str3 = str = str1;
	assert(str3 == str);
	assert(str1 == str);

	//No extra realloc
	AssertStrEqual(str1, "foo");
	auto xxx = str1.data();
	str1 = String("huj");
	assert(xxx == str1.data());

	//-	operator== 
	//testas överallt!

	//-	operator[](size_t i) som indexerar utan range check.
	str = "bar";
	str[-1]; str[1000];	//No error
	assert(str[1] == 'a');
	str[1] = 'y';
	assert(str[1] == 'y');

	const String sc(str);
	assert(sc[1] == 'y');
	assert(std::is_const<std::remove_reference< decltype(sc[1])>::type>::value); //Kolla att det blir en const resultat av indexering

	//-	push_back(char c) lägger till ett tecken sist.
	str = "bar";
	str.push_back('a');
	assert(str == "bara");

	// data
	const char* temp = str.data();
	assert(temp == &str[0]);

	//-	size(), capacity() and reloccation test;
	TestPushBackReallocation();

	cout << String("hej\n");
	cout << "Om det står hej på föregående rad så är TestFörGodkänt klar\n";

}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	locale::global(locale("swedish"));
	TestFörGodkäntString();
}