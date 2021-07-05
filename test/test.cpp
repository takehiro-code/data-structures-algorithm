#include "test.h"

Hello::Hello() {
	str = "hello";
}


void Hello::printHelloPublic() {
	printHello();
}

void Hello::printHello() {
	cout << str << endl;
}

int main(){

	Hello h;
	h.printHelloPublic();

	return 0;
}