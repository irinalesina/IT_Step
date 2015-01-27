#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%d\n", Random()%15+7);
    printf("%d\n", Random());
    printf("%d\n", Random()%197+175);
    printf("%d\n", Random());
    printf("%d\n", Random());
    return 0;
}
