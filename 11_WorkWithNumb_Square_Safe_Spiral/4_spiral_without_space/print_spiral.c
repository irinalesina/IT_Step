
void PrintSpiral(int size, char letter, int direction)
{
    int i, j = (int)(letter - 'A'), k;
    for(i = 0; i < size; i++)
    {
        if(i < j || size - j == i)
        {
            i += j-1;
            if(i == j-1)
            {
                for(k = 0; k < j; k++)
                {
                    printf("%c", 'A' + k);
                }
            }
            else
            {
                for(k = j-1; k >= 0; k--)
                {
                    printf("%c", 'A' + k);
                }
            }

        }
        else
        {
            printf("%c", letter);
        }
    }
    printf("\n");

    if(direction == size)//выход с рекурсии
    {
        return;
    }
    if(size % 2 == 0)
    {
        if(size / 2 == direction)
        {
            return PrintSpiral(size, letter, ++direction);
        }
        else if(size / 2 >= direction)
        {
            return PrintSpiral(size, letter + 1, ++direction);
        }
        return PrintSpiral(size, letter - 1, ++direction);
    }
    else
    {
        if(size / 2 + 1 > direction)
        {
            return PrintSpiral(size, letter + 1, ++direction);
        }
        return PrintSpiral(size, letter - 1, ++direction);
    }

}
