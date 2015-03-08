#include <stdio.h>
#include <stdlib.h>
#include "my_function_len_cmp_cpy.h"
#define N 100

int main()
{
    char str_1[N] = {0}, str_2[N] = {0};

    printf("Enter string 1:\n");
    gets(str_1);

    printf("Enter string 2:\n");
    gets(str_2);

    printf("\nLength of string 1 = %d\n\n", LengthOfString(str_1));

    int result = CompareOfStrings(str_1, str_2);
    if(result == 1)
    {
        printf("String 1 > string 2!\n");
    }
    else if(result == -1)
    {
        printf("String 1 < string 2!\n");
    }
    else
    {
        printf("String 1 equal string 2!\n");
    }

    printf("\nString 1 after copy string 2 in string 1:\n%s\n", CopyString(str_1, str_2));

    return 0;
}
