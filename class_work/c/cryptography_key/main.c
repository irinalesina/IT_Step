#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *file_name;
    file_name = fopen(argv[1], "r");

    int size_of_file;
    fseek(file_name, 0, SEEK_END);
    size_of_file = ftell(file_name);
    fseek(file_name, 0, SEEK_SET);

    char *file_copy;
    file_copy = (char*)malloc(size_of_file * sizeof(char));
    memcpy(file_copy, file_name, size_of_file);
    fclose(file_name);

    double match_index = 0;
    int i, j;
    for(i = 0; i < size_of_file; i++)
    {
        for(j = 0)
    }

    free(file_copy);
    file_copy = NULL;
    return 0;
}
