#include <stdio.h>
#include <stdlib.h>

int main()
{



    typedef struct Persona_//Persona-теперь тип, а не переменная
    {
        char name[128];
        int age;
        enum Sex{male, female} sex;//перечисление
        double tall;
    }Persona;
    Persona Vasia = {"Vasia Ivanova", 24, female, 1.74} /*etr =  {"Petr Ivanov", 23, male, 1.79},*/ ;


    FILE *file_persona;
    file_persona = fopen("Persona.bin", "wb");//wb-запись в бинарном режиме
    if(file_persona == NULL)
    {
        printf("File not open!\n");
        exit(-1);
    }

    fwrite(&Vasia, sizeof(Persona), 1, file_persona);

    fclose(file_persona);
    //size_t fread(void *buf, size_t size_Elem, size_t count, FILE *file);
    //size_t fwrite(const void *buf, size_t size_Elem, size_t count, FILE *file);
    //поолучают: откуда читать/писать,
    //возвращает число байт, которое записалось
    return 0;
}
