#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int SaddlePoint(int **matrix, int m, int n, int *result);
int MinElementInRow(int *matrix, int n);
void OutputMatrix(int **matrix, int m, int n);

int main()
{
    int **matrix = NULL, m, n, i, j, *result = NULL, count;
    srand(time(NULL));
    printf("Emter size of matrix: ");
    scanf("%d%d", &m, &n);

    //��������� ������ ��� �������
    matrix = (int**)malloc(m*sizeof(int*));//��� ���������
    for(i = 0; i < m; i++)
    {
        matrix[i] /* int* */ = (int*)malloc(n*sizeof(int));//��� ��������
    }

    //���������� �������
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            matrix[i][j] = rand()%10;
        }
    }

    //����� ������� �� �����
    printf("Your matrix:\n");
    OutputMatrix(matrix, m, n);


    //��������� ������ �� ������ ����������

    result = (int*)malloc(m*n*sizeof(int));

    count = SaddlePoint(matrix, m, n, result);
    if(count == 0)
    {
        printf("You don't have saddle point!");
    }
    else
    {
        printf("You have saddle point: ");
        for(i = 0; i < count; i++)
        {
            printf("%d ", result[i]);
        }
    }

    //������������ ������
    for(i = 0; i < m; i++)
    {
        free(matrix[i]);//��� ��������
        matrix[i] = NULL;
    }
    free(matrix);//��� ���������
    matrix = NULL;

    //������������ ������ ��� ���������
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
                    if(k == j)
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
                    result[count++] = min;
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


