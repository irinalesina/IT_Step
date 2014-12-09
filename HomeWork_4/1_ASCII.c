#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    for(number; number <= 127; number++)
    {
        char a = number;
        if( number % 16 == 0)
        {
            printf("\n");
        }
        printf("%c ", a);
    }

    return 0;
}
