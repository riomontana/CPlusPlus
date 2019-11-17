#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include "PersonReg.h"

#if 1
	#define PN(x) cout << x
	#define DN(x) x
	#define PD(x) cout << x
#else
	#define PN(x)
	#define DN(x)
	#define PD(x) (x)
#endif

void Init(PersonReg& tr) {
	tr.T�m();
	PD(tr.L�ggTillTest("olle","0703955123"));
	PD(tr.L�ggTillTest("olle","123"));
	PD(tr.L�ggTillTest("kurt�ke","12345"));
	PD(tr.L�ggTillTest("olle", "456"));
    PD(tr.L�ggTillTest("sven", "456"));
    PD(tr.L�ggTillTest("kurt", "95815"));
    PN(endl);
	PN(("fullt reg "));
	PN((endl));
	DN((tr.Print()));
}	

#include <fstream>
bool ReadReg(PersonReg& reg, string fileName) {
	string line;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			while (line.length() == 0 && getline(myfile, line))
				;
			string name(line);
			string adress;
			getline(myfile, adress);
			reg.L�ggTill(&Person(name, adress));
		}
		myfile.close();
		return true;
	}
	else {
		cout << "Unable to open file";
		return false;
	}
}

void Test1() {
    PersonReg reg(10);
    ReadReg(reg, "PersonExempel.txt");
    reg.Print(); cout << "\n\n";
    reg.T�m();
    reg.Print();

}

void Test2() {
    PersonReg reg(10);
    Init(reg);
    string namn, adress;
    Person te, *tep;

    tep = reg.S�kNamn("olle");
    if (tep)
        cout << tep->adress << endl;
    else
        cout << "not found \n";
    reg.TaBortEntry(tep);

    tep = reg.S�kNamn("olle");
    if (tep)
        cout << tep->adress << endl;
    else
        cout << "not found \n";
    reg.TaBortEntry(tep);

    tep = reg.S�kNamn("olle");
    if (tep)
        cout << tep->adress << endl;
    else
        cout << "not found \n";
    reg.TaBortEntry(tep);

    tep = reg.S�kNamn("olle");
    if (tep)
        cout << tep->adress << endl;
    else
        cout << "not found \n";
    reg.TaBortEntry(tep);

    reg.Print();

    reg.T�m();
    reg.Print();

}


void Test3() {
    PersonReg reg(10);

    Init(reg);
    reg.Print();
    string namn, adress;
    Person te, *tep;
    
    tep = nullptr;
    while (tep = reg.S�kFritt("olle", tep)) {
        tep->Print();
//        cout << tep->adress << endl;
    }
    cout << "not found \n";
}

int main() {
#ifndef DBG_NEW
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    locale::global(locale("swedish"));
    PersonReg pr(5);
    Init(pr);
    Test1();
    Test2();
    Test3();
    cin.get();
}