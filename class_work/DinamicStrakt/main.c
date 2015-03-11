#include <stdio.h>
#include <stdlib.h>


/*typedef struct Anything_
    {
        int x;
        struct Anything_ *s;
    } Anything;*/

typedef int Data;
typedef struct Node_
{
    Data data;
    struct Node_ *link;//указатель на следующий узел
} Node;


void Push(Node **top, Data data);
void Pop(Node **top);
bool OnTop(Node *top, Data *data);
bool IsEmpty(Node *top);
void Clear(Node **top);

int main()
{
    Node *top;

    Push(&top, 27);

    return 0;
}

void Push(Node **top, Data data)
{
    Node *p = NULL;
    p = (Node *)mulloc(sizeof(Node));
    p -> data = data;//
    p -> link = *top;
    *top = p;
    p = NULL;
}


void Pop(Node **top)
{
    if(*top)
    {
        Node *p = *top;
        *top = (*top) -> link; /*(**top).link-одна и та же запись*/
        p -> data = 0;
        p -> link = NULL;
        free(p);
        p = NULL;
    }
}

bool OnTop(Node *top, Data *data)
{
    if(!top)
    {
        return false;
    }
    *data = (*top).data;
    return true;
}


bool IsEmpty(Node *top)
{
    return top == NULL;
}


void Clear(Node **top)
{
    while(*top)
    {
        pop(top);
    }
}
