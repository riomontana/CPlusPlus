#include "poly2.h"
#include <cmath>
#include <iostream>
using namespace std;

Poly2::Poly2(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

// uppgift 8: returnerar värdet av en ekvation för ett visst x
float Poly2::eval(float x)
{
	double result;
	
	// y(x) = ax2 + bx + c,
	result = a * pow(x, 2) + b * x + c;

	return result; 
}

// uppgift 8: skriver ut eventuella rötter om det finns några
void Poly2::findRoots()
{
	// Uttrycket inuti kvardratroten kallas för diskriminant, d = b2 - 4ac.
	float d = pow(b, 2) - 4 * a * c;
	float root;
	float root2;

	if (d == 0)
	{
		root = ((-b) + sqrt(abs(d))) / (2 * a);
		cout << "Polynom root = " << root << endl << endl;
	}
	else if (d > 0)
	{
		root = ((-b) + sqrt(abs(d))) / (2 * a);
		root2 = (-b - sqrt(abs(d))) / (2 * a);
		cout << "Polynom root1 = " << root << ", and root2 = " << root2 << endl << endl;
	}
	else
	{
		cout << "Polynom has no roots" << endl << endl;
	}
}

// uppgift 9: returnera rötter till användaren
int& Poly2::findRoots2(int& nbrOfRoots, float& root1, float& root2)
{
	float d = pow(b, 2) - 4 * a * c;

	if (d == 0)
	{
		root1 = ((-b) + sqrt(abs(d))) / (2 * a);
		nbrOfRoots = 1;
	}
	else if (d > 0)
	{
		root1 = ((-b) + sqrt(abs(d))) / (2 * a);
		root2 = (-b - sqrt(abs(d))) / (2 * a);
		nbrOfRoots = 2;
	}
	else
	{
		nbrOfRoots = 0;
	}
	return nbrOfRoots;
}