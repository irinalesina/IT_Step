#include <iostream>
#include <cstdlib>
#include "queue_list.h"

using namespace std;

int main()
{
    int i;
    Data x;
    for(i = 0; i < 6; i++)
    {
        x.a = i;
        Push(x);
    }
    while(!IsEmpty())
    {
        cout << Pop().a << ' ';
    }
    cout << endl;
    return 0;
}
