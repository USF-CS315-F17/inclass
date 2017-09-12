#include <stdio.h>

int main(int argc, char **argv)
{
    /* test casting */
    int x = -7;
    unsigned int v;

    v = (unsigned int) x;
    printf("%d\n", x);
    printf("%u\n", v);

    /* test sign extension */
    unsigned int y = 224;
    int b = 8;
    /*
    unsigned int m16 = 0xFFFF0000;
    unsigned int m8  = 0xFFFFFF00;
    unsigned int m4  = 0xFFFFFFF0;
    */
    
    unsigned int mask = ~((0b1 << b) - 1);
    printf("mask = %X\n", mask);
    
    unsigned int r;
    int sb;

    if ((y >> (b-1)) & 0b1) {
        r = mask | y;
    } else {
        r = y;
    }        
            
    sb = (int) r;
    
    printf("y = %u\n", y);
    printf("r = %d\n", r);
    
    return 0;
}
