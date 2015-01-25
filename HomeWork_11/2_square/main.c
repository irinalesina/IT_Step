#include <stdio.h>
#include <stdlib.h>
#include "animation.h"

int main()
{
    int size_of_square;
    printf("Enter size of square: ");
    scanf("%d", &size_of_square);
    int n = 0;
    Animation(size_of_square, n);
    return 0;
}
