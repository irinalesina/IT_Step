#include <stdio.h>
#include <math.h>
#include <unistd.h>



int main()

{
    int i, j;
    short int buf[32];
    for(i = 0; i < 44100 * 10 / 32; i++)
    {
        for(j = 0; j < 32; j++)
        {
            buf[j] = 20000 * sin((i * 32 + j) * 440.0 * 2 * 3.14159265 / 44100.0);
        }
        write(1, buf, 32 * sizeof(short int));
    }

    return 0;
}
