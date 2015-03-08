
int LengthOfString(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

int CompareOfStrings(char *str_1, char *str_2)
{
    int i = 0;
    while(str_1[i] != '\0' || str_2[i] != '\0')
    {
        if(str_1[i] - str_2[i] == 0)
        {
            i++;
        }
        else
        {
            break;
        }
    }
    if(str_1[i] == '\0' && str_2[i] == '\0')
    {
        return 0;
    }
    else
    {
        return str_1[i] - str_2[i] > 0 ? 1 : -1;
    }
}

char* CopyString(char *str_1, char *str_2)
{
    int i = 0;
    do
    {
        str_1[i] = str_2[i];
    }while(str_2[i++] != '\0');
    return str_1;
}
