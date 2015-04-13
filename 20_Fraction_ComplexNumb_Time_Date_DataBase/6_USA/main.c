#include <stdio.h>
#include <stdlib.h>
#include "usa.h"

int main()
{
    printf("Hello. This database states of America\n\n");
    printf("Current database was loaded.\n"
           "When you exit, modified database will be saved\n\n");
    LoadData();
    int ection;
    char enter;
    do
    {
        printf("\nInstructions:\n");
        printf("0 - exit\n"
               "1 - add data\n"
               "2 - output database\n");
        printf("What you want to do?\n>> ");
        scanf("%d%c", &ection, &enter);
        switch(ection)
        {
        case 1:
            AddData();
            break;
        case 2:
            Output();
            break;
        case 3:

            break;
        case 4:

            break;
        }
    }while(ection);
    printf("Do you want to save a changes?\n"
           "1-yes\n0-no\n>> ");
    scanf("%c%c", &ection, &enter);
    if(ection)
        SaveData();
    return 0;
}
