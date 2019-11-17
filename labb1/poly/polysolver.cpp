#include <iostream>
#include <vector>
#include "poly2.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Root-finding started..." << endl << endl;

	float x = 2;
	Poly2 polyTest1(3, 4, 5);

	float x2 = 0.5;
	Poly2 polyTest2(1.2, 2.4, 3.2);

	float x3 = 1;
	Poly2 polyTest3(0.3, 1.1, 0.9);

	float x4 = 1.5;
	Poly2 polyTest4(0.9, 0.1, 2.4);

	float x5 = 0.25;
	Poly2 polyTest5(0.15, 0.29, 0.11);
	
	// uppgift 8

	cout << "Test Uppgift 8: " << endl;

	cout << "Result of equation where x = " << x << " is: " << polyTest1.eval(x) << endl;
	polyTest1.findRoots();

	cout << "Result of equation where x = " << x2 << " is: " << polyTest2.eval(x2) << endl;
	polyTest2.findRoots();

	cout << "Result of equation where x = " << x3 << " is: " << polyTest3.eval(x3) << endl;
	polyTest3.findRoots();

	cout << "Result of equation where x = " << x4 << " is: " << polyTest4.eval(x4) << endl;
	polyTest4.findRoots();

	cout << "Result of equation where x = " << x5 << " is: " << polyTest5.eval(x5) << endl;
	polyTest5.findRoots();



	// uppgift 9

	cout << "Test Uppgift 9: " << endl << endl;

	vector<Poly2> polyList = { polyTest1,polyTest2,polyTest3,polyTest4,polyTest5 };
	int nbrOfRoots = 0;
	float root1;
	float root2;

	for (int i = 0; i < polyList.size(); i++)
	{
		if (polyList[i].findRoots2(nbrOfRoots, root1, root2) == 1)
		{
			cout << "Polynom root = " << root1 << endl;
			cout << "Root eval = " << polyList[i].eval(root1) << endl << endl;
		}
		else if (polyList[i].findRoots2(nbrOfRoots, root1, root2) == 2)
		{
			cout << "Polynom root1 = " << root1 << ", and root2 = " << root2 << endl;
			cout << "Root1 eval = " << polyList[i].eval(root1) << " and root2 eval = " << polyList[i].eval(root2) << endl << endl;
		}
		else
		{
			cout << "Polynom has no roots" << endl << endl;
		}
	}


	// uppgift 10 & 11

	float a, b, c;

	cout << "Test Uppgift 10: " << endl << endl;
	cout << "Input 3 numbers in sequence" << endl << endl;

	while (cin >> a >> b >> c)
	{
		Poly2 poly = Poly2(a, b, c);

		if (poly.findRoots2(nbrOfRoots, root1, root2) == 1)
		{
			cout << "Polynom root = " << root1 << endl;
			cout << "Root eval = " << poly.eval(root1) << endl << endl;
		}
		else if (poly.findRoots2(nbrOfRoots, root1, root2) == 2)
		{
			cout << "Polynom root1 = " << root1 << ", and root2 = " << root2 << endl;
			cout << "Root1 eval = " << poly.eval(root1) << " and root2 eval = " << poly.eval(root2) << endl << endl;
		}
		else
		{
			cout << "Polynom has no roots" << endl << endl;
		}
		cout << "Input 3 numbers in sequence" << endl << endl;
	}

	return 0;
}