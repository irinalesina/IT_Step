#define stack_size 100

char stack[stack_size];
int stack_top = -1;

int IsStackEmpty()
{
    if(stack_top == -1)
    {
        return 1;
    }
    return 0;
}

void Push(char element)
{
    stack_top++;
    stack[stack_top] = element;
}

char Pop()
{
    return stack[stack_top--];
}
