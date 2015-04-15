#include <iostream>


template <typename T>
void Swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <>
void Swap<int>(int &x, int &y)
{
    x ^= y;
    y ^= x;
    x ^= y;
}

template <int n>//factorial, подсчитывается в момент компиляции
int f()
{
    return n * f < n-1 > ();
}

template <>
int f<0>()
{
    return 1;
}


using namespace std;

int main()
{
    const int x = f<7>();
    //Swap(x, y);//передача по ссылке
    cout << "x = " << x << endl;
    //cout << "y = " << y << endl;
    return 0;
}


