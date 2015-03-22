#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    UniversalStack test;
    Initialize(&test, sizeof(int), 10);
    int i;
    for(i = 0; i < 7; i++)
    {
        Push(&test, &arr[i]);
    }
    int element;
    OnTop(&test, &element);
    printf("Element on top = %d\n", element);
    while(!IsEmpty(&test))
    {
        Pop(&test, &element);
        printf("%d ", element);
    }
    Uninitialize(&test);

    return 0;
}
