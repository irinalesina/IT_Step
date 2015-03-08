#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int r, h;
    printf("Enter radius of the base: r = ");
    scanf("%d",&r);
    printf("Enter height: h = ");
    scanf("%d",&h);
    printf("volume = %lf\n", (1.0/3.0)*3.14*h*r );
    printf("area = %lf\n", 3.14*r*(r+sqrt(r*r+h*h)));
    return 0;
}
