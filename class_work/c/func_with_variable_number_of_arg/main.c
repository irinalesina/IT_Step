#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>



int FindMax(int n, ...);

int main()
{
    int max = FindMax(3, 1, 2, -1);
    printf("%d\n", max);
    return 0;
}


int FindMax(int n, ...)
{
    int largest;
    va_list the_list;
    va_start(the_list, n);
    largest = va_arg(the_list, int);
    int i;
    for(i = 1; i < n; i++)
    {
        int val = va_arg(the_list, int);
        largest = largest > val ? largest : val;
    }
    va_end(the_list);
    return largest;
}
