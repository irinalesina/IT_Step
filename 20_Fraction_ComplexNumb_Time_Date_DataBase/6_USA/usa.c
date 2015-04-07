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

    if(element_count_in_arr == NULL)
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


int SaveData()
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



