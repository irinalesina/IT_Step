#ifndef STACK_LIST_H_INCLUDED
#define STACK_LIST_H_INCLUDED


typedef struct _Data
{
    int some_data;
}Data;

typedef struct _ListElement
{
    Data data;
    struct _ListElement *next;
}ListElement;

void Push(Data data);
Data Pop();
int IsEmpty();

#endif // STACK_LIST_H_INCLUDED
