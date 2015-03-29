#include "stack_list.h"
#include <stddef.h>

ListElement *top = NULL;

void Push(Data data)
{
    //выделение памяти для нового элемента списка
    ListElement *new_element = (ListElement*)malloc(sizeof(ListElement));

    //копирование данных в новый элемент
    new_element->data.some_data = data.some_data;

    //вставка нового элемента в список
    new_element->next = top;
    top = new_element;
}


Data Pop()
{
    Data data;
    data.some_data = 0;
    if(!top)
    {
        return data;
    }

    //копируем значение элемента списка в возвращаемое
    data.some_data = top->data.some_data;

    //передвигаем указатель на предыдущий элемент списка
    ListElement *copy_top = top;
    top = top->next;
    free(copy_top);
    copy_top = NULL;
    return data;
}


int IsEmpty()
{
    return top == NULL ? 1 : 0;
}
