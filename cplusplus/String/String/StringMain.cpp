#include "String.h"
#include <iostream>


int main(){
	const String a('*', 7);
	String b = "Hello";
	String c; //��������� ����������� �����������
	/*
	b.FirstNChar(2, c);
	c.PrintStr();
	b.EndNChar(3, c);
	c.PrintStr();
	

	b.Substr(3, 2, c);
	c.PrintStr();

	b.DeleteSpace(c);
	*/
	b.DeleteSpace(c);
	c.PrintStr();

	//b = a; //������������
	/*
	b.UpReg();
	b.PrintStr();
	*/
	//c = b.PlusNewStr(a);
	//c.PrintStr();

	/*
	b.Plus(" world!");

	a.PrintStr();

	if (b.Find("lo")){
		std::cout << "lo is found in Hello!" << std::endl;
	}


	b.PrintStr();
	*/

	std::getc(stdin);
	return 0;
}