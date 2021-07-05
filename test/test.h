#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Hello {
public:
	Hello();
	void printHelloPublic();
private:
	string str;
	void printHello();
};