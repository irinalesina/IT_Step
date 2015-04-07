#ifndef QUEUE_LIST_H_INCLUDED
#define QUEUE_LIST_H_INCLUDED

struct Data
{
    int a;
};

struct Node
{
    Data data;
    struct Node *link;
};

void Push(Data data);
Data Pop();
int IsEmpty();

#endif // QUEUE_LIST_H_INCLUDED
