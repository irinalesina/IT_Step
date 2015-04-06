#include <stdio.h>
#include <stdlib.h>
#include "compatibity.h"

int main()
{
    printf("Hello world!\n");
    char enter;
    scanf("%c", &enter);
    Universal_clear();
    printf("Farawell we all :( \n");
    Universal_sleep(2.5);
    Universal_clear();
    return 0;
}
