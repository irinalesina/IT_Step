#include <stdio.h>
#include <stdlib.h>
#include "usa.h"

int main()
{
    printf("Hello. This database states of America.\n\n");
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
               "3 - delete data\n"
               "4 - sort database\n"
               "5 - save changes\n");
        printf(">> ");
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
            {
                int field, direction;
                printf("Enter Number of field for sorting:\n"
                       "1 - state\n"
                       "2 - capital\n"
                       "3 - area\n"
                       "4 - population\n>> ");
                scanf("%d", &field);
                printf("Enter direction for sorting\n"
                       "1 - up\n"
                       "0 - down\n>> ");
                scanf("%d", &direction);

                if(field > 4 || field < 1 || direction > 1 || direction < 0)
                    printf("Error. You enter invalid command!\n");
                else
                    SortDatabase(field, direction);
                break;
            }
        case 5:
            SaveData();
            break;
        default:
            if(action)
                printf("You enter invalid command!\n");
        }
    }while(action);

    return 0;
}
