#include <stdio.h>
#include <stdlib.h>

void print_rombus(int ident, int width);

int main()
{
    //int ident, width;
    //printf("Enter ident, width: ");
    //scanf("%d %d", &ident, &width);
    print_rombus(3, 3);
    print_rombus(0, 9);
    print_rombus(3, 3);
    print_rombus(1, 7);
    print_rombus(3, 3);
    print_rombus(0, 9);
    print_rombus(3, 3);

    return 0;
}

void row(int ident, int width, int i);

void print_rombus(int ident, int width)
{
    for(int i = 1; i <= width; i += 2)
    {
        row(ident,width,i);
    }

    for(int i = width-2; i >= 1; i -= 2)
    {
        row(ident,width,i);
    }
}

void row(int ident, int width, int i)
{
    for(int j = 1; j <= (width-i)/2+ident; ++j)
        {
            printf(" ");
        }
        for(int j = 1; j <= i; ++j)
        {
            printf("*");
        }
        printf("\n");
}



