#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    write(1, "Hello world!\n", 13);
    return 0;
}
