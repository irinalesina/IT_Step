#pragma once //���� ����� ��������� ������ ���� ���
#include "Animal.h"
#include <string>


class Cat : public Animal //��� ���������� �� ���������
{
public:
	Cat(string name_); //����������� � ���������� ��� ����
	void Voice();
};




