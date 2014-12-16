#include <stdio.h>
#include <stdlib.h>

int main()
{
    int diagonal;
    printf("Enter diagonal = ");
    scanf("%d", &diagonal);
    int i, j;
    for(i = 1; i <= diagonal; i++)
    {
       for(j = 1; j <= diagonal; j++)
       {
            if((i + j == diagonal/2+2) || (j - i == diagonal/2) ||
               (i - j == diagonal/2) || (i + j == diagonal + diagonal/2 + 1))
            {
                printf("#");
            }
            else
            {
                printf("  ");
            }
       }
       printf("\n");
    }

    return 0;
}
