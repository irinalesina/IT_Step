
int Random()
{
    static int random = 1;
    random = (4096 * random + 150889) % 714025;
    return random;
}
