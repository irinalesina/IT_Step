#include <stdio.h>
#include <stdlib.h>
#include "NOD_NOK_FUNCTION.h"

void contur(int);
int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);
    contur(n);
    return 0;
}

void contur(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(nod(i+1, j+1) == 1)
            {
                printf("#");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
}
