#include "functions.h"

const char *filename = "akinator.txt";

int ReadFromDatabase(Database *node)
{
    FILE *akinator;
    akinator = fopen(filename, "r");
    node->question = fgetc(akinator);
    do
    {
        node->yes = {0};
        node->yes = fgetc(akinator);
    }while(node->yes[0] != node->question[0]);
    do
    {
        node->no = {0};
        node->no = fgetc(akinator);
    }while(node->no[0] != node->question[0]);
}


void EnterNewKnowledge(Help *new_node, Database node)
{

}


