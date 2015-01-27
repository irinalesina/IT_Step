
int Factorial_fanc(int n)
{
    if(n > 0)
    {
        return n*Factorial_fanc(n-1);
    }
    else
    {
        return 1;
    }
}
