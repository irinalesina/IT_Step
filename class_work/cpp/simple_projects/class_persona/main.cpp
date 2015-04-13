#include <iostream>

using namespace std;

/*
enum Sex{male, female}sex;
class Persona
    {
    private:
        char name[128];
        int age;
        Sex sex;
    public:
        char *WhatIsYourName()const;
        int HowOldAreYou()const;
        void CelebrateBirthay();
        Persona(char *name, int age, Sex sex);
    };

int main()
{
    Persona Sam("Sam Long", 21, Sex::male);

    cout << Sam. WhatIsYourName();
    cout << Sam.HowOldAreYou();
    Sam.CelebrateBirthay();
    return 0;
}
*/


class A
{
public:
    int getX()const;
    void setX(int value);
private:
    int x;
};

int A::getX()const
{
    return x;
}

void A::setX(int value)
{
    x = value;
}

int main()
{
    A a;
    a.setX(5);
    cout << a.getX();
    return 0;
}


