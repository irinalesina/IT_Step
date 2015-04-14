#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

int main()
{
    ifstream file("test(5).txt");//open file

    //length of file
    file.seekg(0, file.end);
    int size_of_file = file.tellg() + 1;
    file.seekg(0, file.beg);

    char *text = new char[size_of_file]();//memory allocation

    file.read(text, size_of_file);//read file
    file.close();//close file

    int amount_of_vowel = 0, amount_of_consonant = 0, i, number_of_string = 0;
    char vowel[] = "AEIOUYaeiouy", end_of_string[] = "!?.", consonant[] = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    for(i = 0; i < size_of_file; i++)
    {
        if(strchr(end_of_string, text[i]) != nullptr  && amount_of_consonant && amount_of_vowel)
        {
            number_of_string++;
            if(amount_of_consonant > amount_of_vowel)
            {
                cout << "In " << number_of_string << " string consonant(" << amount_of_consonant;
                cout << ") more then vowel(" << amount_of_vowel << ")!" << endl;
            }
            else if(amount_of_consonant < amount_of_vowel)
            {
                cout << "In " << number_of_string << " string vowel(" << amount_of_vowel;
                cout << ") more then consonant(" << amount_of_consonant << ")!" << endl;
            }
            else
            {
                cout << "In " << number_of_string << " string vowel(" << amount_of_vowel;
                cout << ") equal consonant(" << amount_of_consonant << ")!" << endl;
            }
            amount_of_consonant = 0;
            amount_of_vowel = 0;
        }
        else if(strchr(vowel, text[i]) != nullptr)
        {
            amount_of_vowel++;
        }
        else if(strchr(consonant, text[i]) != nullptr)
        {
            amount_of_consonant++;
        }
    }

    delete[]text;
    text = nullptr;

    return 0;
}
