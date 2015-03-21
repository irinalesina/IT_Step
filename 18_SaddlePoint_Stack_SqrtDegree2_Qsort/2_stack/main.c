#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_f.h"

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    if(IsEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
    int i;
    for(i = 0; i < 7; i++)
    {
        Push(arr[i]);
    }
    if(IsEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
    int element;
    if(OnTop(&element))
    {
        printf("On top = %d \n", element);
    }
    else
    {
        printf("Stack is empty\n");
    }

    while(!IsEmpty())
    {
        printf("%d ", Pop());
    }
    return 0;
}
