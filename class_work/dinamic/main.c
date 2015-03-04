#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ar;
    ar = (int*)malloc(20 * sizeof(int));
    if(ar == NULL)
    {
        fprintf(stderr, "No free memory!\n");
        exit(1);
    }

    return 0;
}
