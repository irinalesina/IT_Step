
int nod(int a, int b)
{
    int max, min, answer;
    max = a > b ? a : b;
    min = a < b ? a : b;

    while(max % min != 0)
    {
        answer = max % min;
        max = min;
        min = answer;

    }
    return min;
}
int nok(int a, int b)
{
    return a*b/nod(a, b);
}
