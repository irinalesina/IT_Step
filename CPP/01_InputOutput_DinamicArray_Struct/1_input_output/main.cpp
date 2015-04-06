#include <iostream>

using namespace std;
int SizeOfNumber(int number);

int main()
{
    int arr[4];
    cout << "Enter numbers from space: ";
    for(int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < 4; i++)
    {
        cout.width(SizeOfNumber(arr[i] * 2) + i);
        cout << arr[i]*2 << endl;
    }
    return 0;
}

int SizeOfNumber(int number)
{
    int size_of_number = 0;
    while(number)
    {
        number /= 10;
        size_of_number += 1;
    }
    return size_of_number;
}



