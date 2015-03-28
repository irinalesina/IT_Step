#include <stdio.h>
#include <stdlib.h>
#include "print_spiral.h"

int main()
{
    int size_of_spiral, indicator = 1;
    printf("Enter size of spiral > 3:\n");
    scanf("%d", &size_of_spiral);
    char letter = 'A';
    if(size_of_spiral < 3)
    {
        printf("Error, you enter size < 3!\n");
    }
    else
    {
        PrintSpiral(size_of_spiral, letter, indicator);
    }
    return 0;
}
