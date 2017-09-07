#include <stdio.h>

int main(int argc, char **argv)
{
    int x = -7;
    unsigned int v;

    v = (unsigned int) x;
    printf("%d\n", x);
    printf("%u\n", v);
    
    return 0;
}
