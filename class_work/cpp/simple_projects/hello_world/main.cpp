#include <iostream>
#include <iomanip>

int foo(int i, int &j);
int main()
{
    using namespace std; //раскрытие пространства имен с 11 стандарта
                        //раньше можно было только до ф-ий(т.е. это пространство имен исп-ся во всем файле)
    cout << "Hello world!\n";
    cout << 'A' << '-' << int('A') + (int)'A'/*более правильно*/ << endl;

    //манипуляторы
    cout << hex << 27 << endl;//16-e
    cout << oct << 27 << endl;//8-e
    cout << true << endl;
    cout << boolalpha << true << endl;
    cout<<dec;//переключение в 10-ю систему

    //заполнить пробелами
    cout.width(5);
    cout.fill('*');//заполнить *
    cout << 345 << endl;
    cout.precision(5);//округляет по кол-ву значащих цифр
    cout << 357.357 << endl;

    //iomanip
    cout << setw(5) << setfill('*') << 23 << endl;

    //ввод
    int a;
    cout << "Enter number: ";
    cin >> a;
    cout << a << endl;

    //ссылки
    int x, &y = x;
    x = 5;
    y = 7;
    cout << x << endl;
    int i = 1, j = -5;
    cout << foo(i, j) << endl;
    cout << "j = " << j << endl;

    //структура(в с++ класс)
    struct Persona
    {
        int age;
    };
    Persona Vasia;
    cin >> Vasia.age;
    cout << "Vasia are " << Vasia.age << " old!" << endl;

    //выделение и удаление памяти: new, delete
    int *arr = nullptr;
    arr = new int[5]();//со ()-конструктор, иниициализирует 0
    if(!arr)
    {
        cout << "Error, memori allocation failed!\n";
    }
    delete [] arr;
    arr = nullptr;

    int *node = nullptr;
    node = new node;
    delete node;
    node = nullptr;

    return 0;
}
//cout-класс

//собственное пространство имен, должно быть в h-ке
namespace zuzu
{

}

//сылки
int foo(int i, int &j)
{
    i += 3;
    j += 4;
    return i*j;
}

