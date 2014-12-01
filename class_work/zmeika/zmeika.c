#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int i;
    printf("enter a number: a = \n");
    for(int i = 0; i < 9; i++)
    {
        int a;

        scanf("%d", &a);
        if (a == 0)
        {
            break;
        }
       // printf("%d\n", a);
        printf(" %d\n", a+1);
        printf("  %d\n", a+2);
        printf(" %d\n", a+3);
        printf("%d\n", a+4);
        printf(" %d\n", a+5);
        printf("  %d\n", a+6);
        printf(" %d\n", a+7);
        //printf("%d\n", a+8);

    }
    return 0;
}
