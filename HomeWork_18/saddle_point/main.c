#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


int SaddlePoint(int **matrix, int m, int n, int *result);
int MinElementInRow(int *matrix, int n);
void OutputMatrix(int **matrix, int m, int n);

int main()
{
    int **matrix = NULL, m, n, i, j, *result = NULL, count;
    srand(time(NULL));
    printf("Emter size of matrix: ");
    scanf("%d%d", &m, &n);

    //выделение памяти под матрицу
    matrix = (int**)malloc(m*sizeof(int*));//под указатели

    //обработка ошибок и освобождение выделенной памяти
    if(matrix == NULL)
    {
        fprintf(stderr, "No free memory!\n");
        exit(1);
    }
    for(i = 0; i < m; i++)
    {
        matrix[i] = NULL;
        matrix[i] /* int* */ = (int*)malloc(n*sizeof(int));//под элементы
        if(matrix[i] == NULL)
        {
            for(int index = i; index > 0; index--)
            {
                free(matrix[index-1]);
                matrix[index-1] = NULL;
            }
            free(matrix);
            matrix = NULL;
            fprintf(stderr, "No free memory!\n");
            exit(1);
        }
    }

    //заполнение матрицы
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            matrix[i][j] = rand()%10;
        }
    }

    //вывод матрицы на экран
    printf("Your matrix:\n");
    OutputMatrix(matrix, m, n);


    //выделение памяти на массив результата

    result = (int*)malloc(m*n*2*sizeof(int));

    count = SaddlePoint(matrix, m, n, result);
    if(count == 0)
    {
        printf("You don't have saddle point!");
    }
    else
    {
        printf("You have saddle point:\n");
        for(i = 0; i < count; i+=2)
        {
            printf("%d, [%d][%d]\n",matrix[result[i]][result[i+1]], result[i], result[i+1]);
        }
    }

    //освобождение памяти
    for(i = 0; i < m; i++)
    {
        free(matrix[i]);//под элементы
        matrix[i] = NULL;
    }
    free(matrix);//под указатели
    matrix = NULL;

    //освобождение памяти под результат
    free(result);
    result = NULL;

    return 0;
}

int SaddlePoint(int **matrix, int m, int n, int *result)
{
    int i, j, k, min, count = 0;
    for(i = 0; i < m; i++)
    {
        min = MinElementInRow(matrix[i], n);
        for(j = 0; j < n; j++)
        {
            if(matrix[i][j] == min)
            {
                for(k = 0; k < m; k++)
                {
                    if(k == i)
                    {
                        continue;
                    }
                    if(min < matrix[k][j])
                    {
                        break;
                    }

                }
                if(k == m)
                {
                    result[count++] = i;
                    result[count++] = j;
                }
            }
        }
    }
    return count;
}


int MinElementInRow(int *matrix, int n)
{
    int j, min = matrix[0];
    for(j = 1; j < n; j++)
    {
        min = matrix[j] < min ? matrix[j] : min;
    }
    return min;
}

void OutputMatrix(int **matrix, int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}


