#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NodeOfList_
{
    int number_of_node;
    struct NodeOfList_ *link;
} NodeOfList;


int main()
{
    FILE *graph_test;
    graph_test = fopen("graph_test.txt", "r");

    if(graph_test == NULL)
    {
        printf("File not open!\n");
        exit(1);
    }
    int size_of_file;
    fseek(graph_test, 0, SEEK_END);
    size_of_file = ftell(graph_test);
    fseek(graph_test, 0, SEEK_SET);
    int *data = (int *)malloc(size_of_file * sizeof(int));

    memcpy(data, graph_test, size_of_file);





    fclose(graph_test);
    return 0;
}
