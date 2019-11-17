#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello World! Nice to see you, ";

	for(int i = 1; i <  argc; i++) {
		cout << argv[i];
		if(i < argc-1) {
			cout << " ";
		}
	}
	
	cout << "!" << endl;

	return 0;
}