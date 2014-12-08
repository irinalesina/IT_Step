#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1, b=2, c=3, max;
    //scanf("%d %d %d",&a,&b,&c);
    max = /*(a>b?a:b)>c?(a>b?a:b):c;*/a>b?(a>c?a:c):(b>c?b:c);
    printf("%d",max);
    return 0;
}

