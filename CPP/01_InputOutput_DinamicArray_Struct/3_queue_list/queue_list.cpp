#include "queue_list.h"
#include <stddef.h>


Node *head = 0, *tail = 0;

void Push(Data data)
{
    Node *element_list;
    element_list = new Node;
    element_list->data.a = data.a;
    element_list->link = NULL;
    if(tail)
    {
        tail->link = element_list;
    }
    tail = element_list;
    if(!head)
    {
        head = element_list;
    }
}


Data Pop()
{
    Data element_list = {0};
    if(!tail)
    {
        return element_list;
    }
    element_list.a = head->data.a;
    Node *help = head;
    head = head->link;
    delete help;
    help = NULL;
    if(head == NULL)
    {
        tail = NULL;
    }
    return element_list;
}


int IsEmpty()
{
    if(head == NULL)
    {
        return 1;
    }
    return 0;
}
