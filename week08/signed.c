#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned ux = 10;
    unsigned uy = 20;
    int x = 10;
    int y = -20;

    if (ux < uy) {
        printf("ux < uy\n");
    }    

    if (x < y) {
        printf("x < y\n");
    }

    return 0;
}
