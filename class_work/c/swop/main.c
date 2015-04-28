#include <stdio.h>
#include <stdlib.h>

#define N 12
#define S_RAM 3





typedef struct _Process
{
    int element;
    int flag;
}Process;


Process ram[S_RAM];
int Min(int element_count, Process *elements);


int main()
{
    int elem_t[N] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};//запрашиваемые страницы памяти

    //заполнение поля флаг нуялми(изначально озу пуста)
    int i, j;
    for(i = 0; i < S_RAM; i++)
    {
        ram[i].flag = 0;
    }

    int position;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < S_RAM; j++)
        {
            if(ram[j].flag == 0)
            {
                ram[j].element = elem_t[i];
                ram[j].flag ++;
                int k;
                for(k = 0; k < S_RAM; k++)
                {
                    if(k != j)
                    {
                        if(ram[k].flag != 0)
                            ram[k].flag++;
                    }
                }
                printf("%d  ", ram[j].element);
                break;
            }

            if(elem_t[i] == ram[j].element)
            {
                break;
            }

            if(j == S_RAM - 1)
            {
                position = Min(S_RAM, ram);
                ram[position].element = elem_t[i];
                ram[position].flag = 1;

                printf("%d!  ", ram[position].element);

                int k;
                for(k = 0; k < S_RAM; k++)
                {
                    if(k != position)
                    {
                        ram[j].flag--;
                    }
                }

            }
        }
    }


    return 0;
}




int Min(int element_count, Process *elements)
{
    int i;
    for(i = 0; i < element_count; i++)
    {
        if(elements[i].flag == 1)
            return i;
    }

}



