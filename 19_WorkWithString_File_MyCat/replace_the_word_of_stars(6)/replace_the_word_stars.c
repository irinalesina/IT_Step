
int SimpleNumber(int number);
char* ReplaceWordOfStar(char *str)
{
    int i = 0, j = 0, k;
    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            j++;
            continue;
        }
        while(str[i] != ' ' && str[i] != '\0')
        {
            i++;
        }
        if(SimpleNumber(i - j) == 0)
        {
            for(k = i; k > j; k--)
            {
                str[k-1] = '*';
            }
        }
        j = ++i;
    }
    return str;
}

int SimpleNumber(int number) //if number simple - return 0
{
    int i, answer = 0;
    for(i = 2; i < number && answer < 1; i++)
    {
        if(number % i == 0)
        {
            answer++;
        }
    }
    return answer;
}
