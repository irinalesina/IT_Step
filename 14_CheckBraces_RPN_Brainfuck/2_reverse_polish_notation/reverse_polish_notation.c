#define stack_size 100
#include <stdbool.h>

double stack[stack_size];
int stack_top = -1;

void PushStack(double element)
{
    stack_top++;
    stack[stack_top] = element;
}


double PopStack(double element)
{
    return stack[stack_top--];
}


bool StackIsEmpty()
{
    if(stack_top == -1)
    {
        return true;
    }
    return false;
}
