#pragma once


class String
{
private:
	char *s;
	int length;
public:
	void PrintStr() const; //���� ����� �� �������� ������
	const char *Find(const char *substr) const;
	int Plus(const char *source);


	//classwork
	String PlusNewStr(const String &source) const;
	void UpReg();
	bool FirstNChar(int n, String &result); 
	bool EndNChar(int n, String &result); 
	bool Substr(int n, int position, String &result);
	bool DeleteSpace(String &result);




	const char *c_str() const{//������ ��� ������, inline-�����
		return s;
	} 

	//���������� ��������� ������������
	void operator=(const String &sourse);

	//ctor
	String();
	String(const char *p);
	String(char c, size_t n);
	String(const String &orig); //����������� �����������
	//dtor
	~String();
};

void PrintStr(String str);



inline int sqr(int x){
	return x*x;
}