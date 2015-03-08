#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //проверка на наличие комманд
    int i = 1, exit_ = 0;
    for (; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0)
        {
            printf("This is Cat program written by Lesina Irina. (c) 2015 :)\n");
            exit_ = -1;
            break;
        }
        else if(strcmp(argv[i], "--number") == 0 || strcmp(argv[i], "-n") == 0)
        {
            exit_ = i;
        }
    }
    //выполнение
    if(exit_ != -1)
    {
        FILE *file;
        int additive = 1;
        for(i = 1; i < argc; i++)
        {
            file = fopen(argv[i], "r");
            if(file == NULL)//если не файл, а просто текст
            {
                if(exit_ == 0)
                {
                    printf("%s\n", argv[i]);
                }
                else if(i != exit_)
                {
                    printf("%d. %s\n", additive++, argv[i]);
                }
            }
            else//если файл
            {
                fseek(file, 0, SEEK_END);
                int size_of_file = ftell(file) + 1;
                fseek(file, 0, SEEK_SET);
                char *text = (char*)malloc(size_of_file*sizeof(char));
                if(text == NULL)
                {
                    printf("Memory allocation failed!\n");
                    exit(-1);
                }
                memset(text, 0, size_of_file);
                fread(text, sizeof(char), size_of_file, file);
                fclose(file);
                int exit_text = 1;
                char *space_pointer, *prev_pointer = text;
                while(exit_text)//обработка текста на строки
                {
                    char *j;
                    space_pointer = strchr(prev_pointer, '\n');
                    if(space_pointer == NULL)
                    {
                        exit_text = 0;
                        space_pointer = strchr(prev_pointer, '\0');
                    }
                    if(exit_ == 0)//вывод без нумерации
                    {
                        for(j = prev_pointer; j <= space_pointer; j++)
                        {
                            printf("%c", *j);
                        }
                    }
                    else//вывод с нумерацией
                    {
                        for(j = prev_pointer; j <= space_pointer; j++)
                        {
                            if(j == prev_pointer)
                            {
                                printf("%d. %c", additive++, *j);
                            }
                            else
                            {
                                printf("%c", *j);
                            }
                        }
                    }
                    if(*space_pointer == '\0')
                    {
                        printf("\n");
                    }
                    prev_pointer = space_pointer + 1;
                }
                free(text);
                text = NULL;
            }

        }
    }

    return 0;
}
