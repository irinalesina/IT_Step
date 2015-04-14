#include "usa.h"

const char *file_name = "USA.bin";
USA *arr_of_data = NULL;
USA *helper = NULL;
int element_count_in_arr = 0;

int LoadData()
{
    FILE *file;
    file = fopen(file_name, "rb");
    if(file == NULL)
    {
        printf("Open file error!\n");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    element_count_in_arr = ftell(file) / sizeof(USA);
    fseek(file, 0, SEEK_SET);

    if(element_count_in_arr == 0)
    {
        printf("File is empty!\n");
        fclose(file);
        return 1;
    }

    arr_of_data = (USA*)malloc(element_count_in_arr * sizeof(USA));
    if(arr_of_data == NULL)
    {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 0;
    }

    fread(arr_of_data, sizeof(USA), element_count_in_arr, file);
    fclose(file);
    return 1;
}


void SaveData()
{
    FILE *file;
    file = fopen(file_name, "wb");
    fwrite(arr_of_data, sizeof(USA), element_count_in_arr, file);
    fclose(file);
    free(arr_of_data);
    arr_of_data = NULL;
}


void AddData()
{
    helper = (USA*)malloc(element_count_in_arr*sizeof(USA));
    if(helper == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    int i;
    for(i = 0; i < element_count_in_arr; i++)
    {
        helper[i] = arr_of_data[i];
    }
    ++element_count_in_arr;
    free(arr_of_data);
    arr_of_data = (USA*)malloc(element_count_in_arr*sizeof(USA));
    if(arr_of_data == NULL)
    {
        printf("Memory allocation failed!\n");
        free(helper);
        helper = NULL;
        return;
    }
    memset(arr_of_data, 0, element_count_in_arr*sizeof(USA));
    for(i = 0; i < element_count_in_arr - 1; i++)
    {
        arr_of_data[i] = helper[i];
    }
    free(helper);
    helper = NULL;


    printf("state: ");
    gets(&arr_of_data[element_count_in_arr - 1].state);
    printf("capital of state: ");
    gets(&arr_of_data[element_count_in_arr - 1].capital);
    printf("area of state(km^2): ");
    scanf("%d", &arr_of_data[element_count_in_arr - 1].area);
    printf("population in state: ");
    scanf("%d", &arr_of_data[element_count_in_arr - 1].population);
}


void Output()
{
    if(!element_count_in_arr)
    {
        printf("Database is empty!\n");
        return;
    }
    int i;
    printf("| p |     state       |      capital     |   area, km^2   |    population    |\n\n");
    for(i = 0; i < element_count_in_arr; i++)
    {
        printf("|%3d|", i+1);
        printf("%17s|", arr_of_data[i].state);
        printf("%18s|", arr_of_data[i].capital);
        printf("%16d|", arr_of_data[i].area);
        printf("%18d|\n", arr_of_data[i].population);
    }
}


int DeleteData(int position)
{
    if(position > element_count_in_arr)
        return 0;
    int i;
    for(i = position - 1; i < element_count_in_arr - 1; i++)
    {
        /*arr_of_data[i].area = arr_of_data[i+1].area;
        strcpy(arr_of_data[i].capital, arr_of_data[i+1].capital);
        arr_of_data[i].population = arr_of_data[i+1].population;
        strcpy(arr_of_data[i].state, arr_of_data[i+1].state);*/
        arr_of_data[i] = arr_of_data[i+1];//cool
    }
    --element_count_in_arr;
    return 1;
}



int CompareInt(const void *a, const void *b);
int CompareString(const void *a, const void *b);
int copy_dierction, copy_field;

void SortDatabase(int field, int direction)
{
    copy_dierction = direction;
    copy_field = field;
    if(field == 1 || field == 2)
        qsort(arr_of_data, element_count_in_arr, sizeof(USA), CompareString);
    else if(field == 3 || field == 4)
        qsort(arr_of_data, element_count_in_arr, sizeof(USA), CompareInt);
    Output();
}


int CompareString(const void *a, const void *b)
{
    USA *x = (USA*)a, *y = (USA*)b;
    if(copy_field == 1)
        return copy_dierction ? (strcmp(x->state, y->state)) : (strcmp(y->state, x->state));
    else
        return copy_dierction ? (strcmp(x->capital, y->capital)) : (strcmp(y->capital, x->capital));
}


int CompareInt(const void *a, const void *b)
{
    USA *x = (USA*)a, *y = (USA*)b;
    if(copy_field == 3)
        return copy_dierction ? (x->area - y->area) : (y->area - x->area);
    else
        return copy_dierction ? (x->population - y->population) : (y->population - x->population);
}






