#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include <cstdlib>
#include <cstring>
#include <iostream>


void String::PrintStr(){
	std::cout << s << std::endl;
}


const char *String::Find(const char *substr){
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


const char *String::cstr(){
	return s;
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
	s = (char*)malloc(strlen(orig.s) + 1);
	strcpy(s, orig.s);
}

String::~String(){
	free(s);
}


void PrintStr(String str){
	str.PrintStr();
}
