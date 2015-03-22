#include <stdio.h>
#include <stdlib.h>

void list_of_latters();
int main()
{
    srand(time(NULL));
    int i;
    for(i = 0; i < 10; i++)
    {
        list_of_latters();
    }
    return 0;
}
void list_of_latters()
{
    char letters[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; //string
    printf("%c\n", letters[rand()%26]);
}
