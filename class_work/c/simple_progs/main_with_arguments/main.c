#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    for(int i = 0; i < argc; ++i)
    {
        if(strcmp(argv[1], "--help") == 0)
        {
            printf("This is your help!\n");
            break;
        }
        printf("%s\n", argv[i]);
    }

    FILE *fopen(const char *filename, const char *mode);
    return 0;
}
