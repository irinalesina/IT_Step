#include <stdio.h>
#include <stdlib.h>

int main()
{
    int length, width;
    printf("Enter length = ");
    scanf("%d", &length);
    printf("Enter width = ");
    scanf("%d", &width);

    int k = 1;
    for(k; k <= width; k++)
    {
        int i = 1;
        for(i; i <= length; i++)
        {
            if((i == 1 || i == length) || (k == 1 || k == width))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");

    }


    return 0;
}
