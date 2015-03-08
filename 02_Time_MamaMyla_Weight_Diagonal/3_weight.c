#include <stdio.h>
#include <stdlib.h>

int main()
{
    double w_Jack, w_Wiiliam, w_Sue, w_Judith;
    char a[]="Jack", b[]="Wiiliam", c[]="Sue", d[]="Judith";

    printf("enter weight of Jack = ");
    scanf("%lf",&w_Jack);


    printf("enter weight of Wiiliam = ");
    scanf("%lf",&w_Wiiliam);

    printf("enter weight of Sue = ");
    scanf("%lf",&w_Sue);

    printf("enter weight of Judith = ");
    scanf("%lf",&w_Judith);

    printf("%10s | %10.3f\n%10s | %10.3f\n%10s | %10.3f\n%10s | %10.3f\n",a,w_Jack,b,w_Wiiliam,c,w_Sue,d,w_Judith);
    return 0;
}
