
void Kubik(int number)
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        if( i == 0 || i == 2)
        {
            printf("+---+\n");
        }
        else
        {
            switch(number)
            {
                case 1:
                    printf("|   |\n| 0 |\n|   |\n");
                    break;

                case 2:
                    printf("|0  |\n|   |\n|  0|\n");
                    break;

                case 3:
                    printf("|0  |\n| 0 |\n|  0|\n");
                    break;

                case 4:
                    printf("|0 0|\n|   |\n|0 0|\n");
                    break;

                case 5:
                    printf("|0 0|\n| 0 |\n|0 0|\n");
                    break;

                case 6:
                    printf("|000|\n|   |\n|000|\n");
                    break;

            }
        }

    }
    printf("\n");
}
