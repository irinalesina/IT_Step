#ifndef QUEUE_LIST_H_INCLUDED
#define QUEUE_LIST_H_INCLUDED

typedef struct _Data
{
    int a;
}Data;

typedef struct _Node
{
    Data data;
    struct _Node *link;
}Node;

void Push(Data data);
Data Pop();
int IsEmpty();

#endif // QUEUE_LIST_H_INCLUDED
