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
               "1 - add data in database\n"
               "2 - output database\n");
        printf("What you want to do?\n");
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
    SaveData();
    return 0;
}
