#include "universal_stack.h"
#include <string.h>

int Initialize(UniversalStack *us, int element_size, int element_max_count)
{
    us->stack_memory = malloc(element_size*element_max_count);
    if(us->stack_memory == NULL)
    {
        return 0;
    }
    us->element_size = element_size;
    us->element_max_count = element_max_count;
    us->top = -1;
    return 1;
}

void Uninitialize(UniversalStack *us)
{
    free(us->stack_memory);
    us->stack_memory = NULL;
}

int Push(UniversalStack *us, void *element)
{
    if(us->top >= us->element_max_count)
    {
        return 0;
    }
    us->top++;
    memcpy((char*)us->stack_memory + us->top * us->element_size, element, us->element_size);
    return 1;
}

int Pop(UniversalStack *us, void *element)
{
    if(us->top < 0)
    {
        return 0;
    }
    memcpy(element, (char*)us->stack_memory + us->top * us->element_size, us->element_size);
    us->top--;
    return 1;
}


int OnTop(UniversalStack *us, void *element)
{
    int result = Pop(us, element);
    if(result)
    {
        us->top++;
    }
    return result;
}


int IsEmpty(UniversalStack *us)
{
    return us->top == -1 ? 1 : 0;
}
