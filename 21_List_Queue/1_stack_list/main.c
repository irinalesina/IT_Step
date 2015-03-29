#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

int main()
{
    int i;
    Data data;
    for(i = 0; i < 5; i++)
    {
        data.some_data = i;
        Push(data);
    }
    while(!IsEmpty())
    {
        data = Pop();
        printf("%d", data.some_data);
    }
    return 0;
}
