#include <stdio.h>
#include <stdlib.h>
#include "usa.h"

int main()
{
    printf("Hello. This database states of America\n\n");
    printf("Current database was loaded.\n");

    LoadData();
    int action;
    char enter;
    do
    {
        printf("\nInstructions:\n");
        printf("0 - exit\n"
               "1 - add data\n"
               "2 - output database\n"
               "3 - delete data\n");
        printf("What do you want to do?\n>> ");
        scanf("%d%c", &action, &enter);
        switch(action)
        {
        case 1:
            AddData();
            break;
        case 2:
            Output();
            break;
        case 3:
            {
                int position;
                printf("Enter position of element in table:\n>> ");
                scanf("%d", &position);
                if(DeleteData(position))
                    printf("Data deleted!\n");
                else
                    printf("You enter invalid position!\n");
                break;
            }
        case 4:

            break;
        default:
            printf("You enter invalid command!\n");
        }
    }while(action);

    printf("Do you want to save a changes?\n"
           "1-yes\n0-no\n>> ");
    scanf("%c%c", &action, &enter);
    if(action)
        SaveData();

    return 0;
}
