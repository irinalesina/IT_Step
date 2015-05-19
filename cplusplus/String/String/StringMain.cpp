#include "String.h"
#include <iostream>


int main(){
	String a('*', 7), b = "Hello";
	b.PrintStr();
	a.PrintStr();
	PrintStr(b);

	if (b.Find("lo")){
		std::cout << "lo is found in Hello!" << std::endl;
	}

	b.Plus(" world!");
	b.PrintStr();

	std::getc(stdin);
	return 0;
}