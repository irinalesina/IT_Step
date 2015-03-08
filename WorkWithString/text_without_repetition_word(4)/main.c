#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text_without_repetition_word.h"


int main()
{
    FILE *file;
    char str[N] = {0};

    file = fopen("../test(4).txt", "r");
    if(file == NULL)
    {
        printf("Error open file!\n");
        return -1;
    }
    fread(str, sizeof(char), N-1, file);

    printf("Text without repetition word:\n%s\n", TextWithoutRepeatitionWord(str));

    fclose(file);



    return 0;
}
