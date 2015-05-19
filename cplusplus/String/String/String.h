#pragma once


class String
{
private:
	char *s;
	int length;
public:
	void PrintStr();
	const char *Find(const char *substr);
	int Plus(const char *source);
	const char *cstr(); //������ ��� ������
	//ctor
	String();
	String(const char *p);
	String(char c, size_t n);
	String(const String &orig); //����������� �����������
	//dtor
	~String();
};

void PrintStr(String str);

