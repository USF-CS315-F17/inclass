#include <stdio.h>

int add_a(int x, int y);

int main(int argc, char **argv)
{
    int x;

    x = add_a(1,2);

    printf("x = %d\n", x);

    x = add_a(100,99);

    printf("x = %d\n", x);

    x = add_a(-1, 1);

    printf("x = %d\n", x);


}
