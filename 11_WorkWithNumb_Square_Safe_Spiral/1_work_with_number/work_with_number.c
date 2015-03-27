
int AmountOfDigit(int number)
{
    if(number > 10)
    {
        return 1 + AmountOfDigit(number / 10);
    }
    else
    {
        return 1;
    }
}

int FirstDigit(int number)
{
    if(number > 10)
    {
        return FirstDigit(number / 10);
    }
    else
    {
        return number;
    }

}

int AllDigitsWithoutFirst(int number)
{
    if(number > 10)
    {
        return number % 10 + 10 * AllDigitsWithoutFirst(number / 10);
    }
    else
    {
        return 0;
    }
}

int NumberWithDigit(int number, int digit)
{
    return number * 10 + digit;
}

int CyclicShift(int number)
{
    return AllDigitsWithoutFirst(number) * 10 + FirstDigit(number);
}



