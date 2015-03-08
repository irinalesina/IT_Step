#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;
    file = fopen("../test(5).txt", "r");
    if(file == NULL)
    {
        printf("File is not open!\n");
        exit(-1);
    }
    fseek(file, 0, SEEK_END);//указатель в конец файла
    int size_of_file = ftell(file) + 1;
    fseek(file, 0, SEEK_SET);//указатель в начало файла
    //выделение памяти под массив для записи содержимого файла
    char *text = (char*)malloc(size_of_file*sizeof(char));
    if(text == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    memset(text, 0, size_of_file);//зануление всех элементов массива
    fread(text, sizeof(char), size_of_file, file);
    fclose(file);

    int amount_of_vowel = 0, amount_of_consonant = 0, i, number_of_string = 0;
    char vowel[] = "AEIOUYaeiouy", end_of_string[] = "!?.", consonant[] = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    for(i = 0; i < size_of_file; i++)
    {
        if(strchr(end_of_string, text[i]) != NULL  && amount_of_consonant && amount_of_vowel)//проверка на конец предложения
        {
            number_of_string++;
            if(amount_of_consonant > amount_of_vowel)
            {
                printf("In %d string consonant(%d) more then vowel(%d)!\n", number_of_string, amount_of_consonant, amount_of_vowel);
            }
            else if(amount_of_consonant < amount_of_vowel)
            {
                printf("In %d string vowel(%d) more then consonant(%d)!\n", number_of_string, amount_of_vowel, amount_of_consonant);
            }
            else
            {
                printf("In %d string consonant(%d) equal vowel(%d)!\n", number_of_string, amount_of_consonant,  amount_of_vowel);
            }
            amount_of_consonant = 0;
            amount_of_vowel = 0;
        }
        else if(strchr(vowel, text[i]) != NULL)
        {
            amount_of_vowel++;
        }
        else if(strchr(consonant, text[i]) != NULL)
        {
            amount_of_consonant++;
        }
    }
    free(text);
    text = NULL;

    return 0;
}
