#include <stdio.h>
#include <stdlib.h>
#include <string.h> //стандартные функции работы со строками

int main()
{
    /*long long int a = 0xFEFEFEFEFEFEFEFE;
    char str[9] = "mamarama";
    long long int b = 0xDADADADADADADADA;
    printf("%s\n", str);
    for(char *p = str; *p; ++p)
    {
        printf("%c\t%#X\n", *p, *p);
    }*/

    /*char *str1 = "mama";//мжем объявить, но изменять в дальнейшем нельзя
    char str2[5] = "mama";
    printf("%s\n%s\n", str1, str2);
    str2[0] = 'r';
    printf("\n%s\n%s\n", str1, str2);*/

    char str[20];
    fgets(str, 20, stdin);
    printf("%s\n", str);
    return 0;
}
