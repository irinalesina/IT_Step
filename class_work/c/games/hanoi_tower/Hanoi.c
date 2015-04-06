
void Hanoi(int amount_of_disks, char from, char to, char helper)
{
    if(amount_of_disks > 0)
    {
        Hanoi(amount_of_disks-1, from, helper, to);
        printf("%c-->%c\n", from, to);
        Hanoi(amount_of_disks-1, helper, to, from);
    }
}
