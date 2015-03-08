#include <stdio.h>
#include <stdlib.h>

int main()
{
    int length, height;
    printf("Enter length ( >0 ) = ");
    scanf("%d", &length);
    printf("Enter height ( >0 ) = ");
    scanf("%d", &height);

    int i, j;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < length; j++)
        {
            printf((i + j)%2 ? " " : "*");
        }
        printf("\n");
    }
    return 0;
}
