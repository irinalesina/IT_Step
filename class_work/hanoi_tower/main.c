#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amount_of_disks;
    char from = 'A', to = 'B', helper = 'C';
    printf("Enter amount of disks: ");
    scanf("%d", &amount_of_disks);
    Hanoi(amount_of_disks, from, to, helper);
    printf("Congratulation!!!");
    return 0;
}
