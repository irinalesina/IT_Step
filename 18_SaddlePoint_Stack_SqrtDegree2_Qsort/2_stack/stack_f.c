#include <stdbool.h>
#define N 100
#include <assert.h>

static int stack[N] = {0}, top = -1;

void Push(int element)
{
    if(top < N)
    {
        stack[++top] = element;
    }
}


int Pop()
{
    if(top > -1)
    {
        return stack[top--];
    }
}


int OnTop(int *element)
{
    if(IsEmpty())
    {
        return 0;
    }
    *element = stack[top];
    return 1;
}

int IsEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}
