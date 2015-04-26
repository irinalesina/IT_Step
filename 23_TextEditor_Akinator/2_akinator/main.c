#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int answer;
    Database data;
    FILE *akinator;
    akinator = fopen(filename, "r");
    data.question = fgetc(akinator);
    printf("%s?(yes/no)", data.question);
    scanf("%d", &answer);
    if(answer)
    {

    }


    return 0;
}
