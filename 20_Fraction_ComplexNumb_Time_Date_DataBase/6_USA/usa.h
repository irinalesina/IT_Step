#ifndef USA_H_INCLUDED
#define USA_H_INCLUDED



typedef struct _USA
{
    char state[20];
    char capital[20];
    int area;
    int population;
}USA;


void Output();
void SaveData();
int LoadData();
void DeleteData();
void AddData();


#endif // USA_H_INCLUDED
