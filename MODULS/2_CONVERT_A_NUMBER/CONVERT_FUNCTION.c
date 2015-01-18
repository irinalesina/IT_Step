
void Convert(int number, int system_of_number)
{
    printf("%d in %d-system = ", number, system_of_number);

    int denominator = system_of_number, number_trash;
    while(denominator <= number)
    {
        denominator *= system_of_number;
    }
    denominator /= system_of_number;

    while(denominator)
    {
        char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        number_trash = number / denominator;
        number = number % denominator;
        denominator /= system_of_number;

        if(number_trash > 9)
        {
            printf("%c", letter[number_trash - 10]);
        }
        else
        {
            printf("%d", number_trash);
        }
    }
}
