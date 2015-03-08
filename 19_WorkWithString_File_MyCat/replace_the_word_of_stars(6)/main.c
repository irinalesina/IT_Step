#include <stdio.h>
#include <stdlib.h>
#include "replace_the_word_stars.h"
#include <string.h>
#define N 100


int main()
{
    char str[N] = {0};

    FILE *file;
    file = fopen("../test.txt", "r");
    if(file == NULL)
    {
        printf("Error open file!\n");
        return -1;
    }
    fread(str, sizeof(char), N-1, file);
    fclose(file);

    printf("String after replace:\n%s\n", ReplaceWordOfStar(str));

    return 0;
}
