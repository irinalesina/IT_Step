
int Random()
{
    static int random = 1;
    random = (18 * random + 29) % 17;
}
