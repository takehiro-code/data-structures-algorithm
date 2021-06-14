#include <iostream> // for cout
#include "ArrayClass.h"

using namespace std;

// Function Prototype
void arrayClassTest();
void exceptionTest();

// Main function that is called when the program is executed
int main() {
	//arrayClassTest();
	//exceptionTest();

	return 0;
}

void arrayClassTest() {
	ArrayClass ac;
	ac.insert(1);
	ac.insert(2);

	cout << "ac.size()  = " << ac.size() << endl;

	// Insert the values 1 to 7 in ac1
	for (int i = 3; i <= 40; ++i) {
		ac.insert(i);
	}

	cout << "ac.size()  = " << ac.size() << endl;
	cout << "ac.sum() = " << ac.sum() << endl;
}

void exceptionTest() {
	ArrayClass ac;

	// Insert 1 to 10 integers in ac
	int n = 10;
	for (int i = 0; i < n; ++i) {
		ac.insert(i + 1);
	}


	// test .get
	try {
		// "Accidentally" access the 11th element
		for (int i = 0; i <= ac.size(); ++i) {
			cout << ac.get(i) << endl;
		}
	}
	catch (std::out_of_range& oor) // better to use & passing by reference 
	{
		cout << oor.what() << endl;
	}
	catch (...) // generally don't use this 
	{
		cout << "Undefined exceptions!" << endl;
	}

	// test .set
	try {
		ac.set(105, 10);
	}
	catch (std::out_of_range&oor) {
		cout << oor.what() << endl;
	}
	catch (...) // generally don't use this 
	{
		cout << "Undefined exceptions!" << endl;
	}

}

