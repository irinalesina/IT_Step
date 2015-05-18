#include <iostream>
#include "Cat.h"


using namespace std;

void Cat::Voice()
{
	cout << "Cat " << name <<  " said Meow :)" << endl;
}

Cat::Cat(string name_): //������������ Cat �� Animal
Animal(name_) //�������� ����������� Animal, ��������� ��� �������� name_
{
	cout << "Cat " << name << " has opened its eyes!" << endl;
}