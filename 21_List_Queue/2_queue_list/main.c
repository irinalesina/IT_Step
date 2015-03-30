#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

int main()
{
    int i;
    Data x;
    for(i = 0; i < 6; i++)
    {
        x.a = i;
        Push(x);
    }
    while(!IsEmpty())
    {
        printf("%d ", Pop().a);
    }
    printf("\n");
    return 0;
}
