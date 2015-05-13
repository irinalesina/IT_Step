#include <stdio.h>
#include <stdlib.h>
#include "../UniversalStack_lib/universal_stack.h"

int main()
{
    //check with int
    int arr1[7] = {1, 2, 3, 4, 5, 6, 7};
    printf("Initial data with int:\n");
    int i;
    for(i = 0; i < 7; i++)
    {
        printf("%d ", arr1[i]);
    }

    UniversalStack test1;
    Initialize(&test1, sizeof(int), 7);

    for(i = 0; i < 7; i++)
    {
        Push(&test1, &arr1[i]);
    }

    int element1;
    OnTop(&test1, &element1);
    printf("\nElement on top = %d\n", element1);

    printf("Data after push and pull to stack with int:\n");
    while(!IsEmpty(&test1))
    {
        Pop(&test1, &element1);
        printf("%d ", element1);
    }

    Uninitialize(&test1);

    //check with char
    char arr2[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    printf("\nInitial data with char:\n");
    for(i = 0; i < 7; i++)
    {
        printf("%c ", arr2[i]);
    }

    UniversalStack test2;
    Initialize(&test2, sizeof(char), 7);

    for(i = 0; i < 7; i++)
    {
        Push(&test2, &arr2[i]);
    }

    char element2;
    OnTop(&test2, &element2);
    printf("\nElement on top = %c\n", element2);

    printf("Data after push and pull to stack with char:\n");
    while(!IsEmpty(&test2))
    {
        Pop(&test2, &element2);
        printf("%c ", element2);
    }
    Uninitialize(&test2);

    return 0;
}
