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
        for(i = 1; i < argc; i++)
        {
            file = fopen(argv[i], "r");
            if(file == NULL)
            {
                if(exit_ == 0)
                {
                    printf("%s\n", argv[i]);
                }
                else if(i != exit_)
                {
                    printf("%d. %s\n", i, argv[i]);
                }
            }
            else
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
                if(exit_ == 0)
                {
                    printf("%s\n", text);
                }
                else
                {
                    printf("%d. %s\n", i, text);
                }
                free(text);
                text = NULL;
            }

        }
    }

    return 0;
}
