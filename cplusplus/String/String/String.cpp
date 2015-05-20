#define _CRT_SECURE_NO_WARNINGS //для strcpy(), тк она не безопасна

#include "String.h"
#include <cstdlib>
#include <cstring>
#include <iostream>


void String::PrintStr() const{
	std::cout << s << std::endl;
}


const char *String::Find(const char *substr) const{
	return strstr(s, substr);
}


int String::Plus(const char *source){
	length += strlen(source);
	s = (char*)realloc(s, length + 1);
	if (s == 0){
		length -= strlen(source);
		return 0;
	}
	strcat(s, source);
	return 1;
}


String String::PlusNewStr(const String &source) const{
	String new_str(s);
	new_str.length += source.length;
	new_str.s = (char*)realloc(new_str.s, new_str.length + 1);
	strcat(new_str.s, source.s);
	return new_str;
}


String::String(){
	s = (char*)malloc(sizeof(char));
	s[0] = 0; // *s = '\0'
	length = 0;
}


String::String(const char *p){
	length = strlen(p);
	s = (char*)malloc(length * sizeof(char)+1);
	strcpy(s, p);
}


String::String(char c, size_t n){
	s = (char*)malloc(n * sizeof(char) + 1);
	memset(s, c, n);
	s[n] = 0;
	length = n;
}


//явно указываем способ создания копии для функций
String::String(const String &orig){
	length = strlen(orig.s);
	s = (char*)malloc(length + 1);
	strcpy(s, orig.s);
}

String::~String(){
	free(s);
}


void PrintStr(String str){
	str.PrintStr();
}


void String::operator=(const String &sourse){
	free(s);
	length = sourse.length;
	s = (char*)malloc(length + 1);
	strcpy(s, sourse.s);
}


void String::UpReg(){
	int size_str = strlen(s);
	for (int i = 0; i <= size_str; i++){
		if (s[i] >= 'a' && s[i] <= 'z'){
			s[i] -= 32;
		}
	}
}


bool String::FirstNChar(int n, String &result){
	if (n > length){
		std::cout << "n > length of string!\n";
		return false;
	}
	result.length = n;
	free(result.s);
	result.s = (char*)malloc(n + 1);
	strncpy(result.s, s, n);
	result.s[n] = 0;
	return true;
}


bool String::EndNChar(int n, String &result){
	if (n > length){
		std::cout << "n > length of string!\n";
		return false;
	}
	result.length = n;
	free(result.s);
	result.s = (char*)malloc(n + 1);
	strncpy(result.s, s + length - n, n);
	result.s[n] = 0;
	return true;
}


bool String::Substr(int n, int position, String &result){
	if (n > length - position + 1){
		std::cout << "n > length of string!\n";
		return false;
	}
	result.length = n;
	free(result.s);
	result.s = (char*)malloc(n + 1);
	strncpy(result.s, s + position - 1, n);
	result.s[n] = 0;
	return true;
}


bool String::DeleteSpace(String &result){
	if (s[0] != ' ' && s[length - 1] != ' '){
		std::cout << "Inline no space!\n";
		return false;
	}
	int begin = 0, end = 0, i = 0;
	while (s[i] == ' '){
		begin++;
		i++;
	}
	i = length - 1;
	while (s[i] == ' '){
		end++;
		i--;
	}
	result.length = length - begin - end;
	result.s = (char*)malloc(result.length + 1);
	strncpy(result.s, s + begin, result.length);

	result.s[result.length] = 0;
	return true;
}

