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




    fclose(graph_test);
    return 0;
}
