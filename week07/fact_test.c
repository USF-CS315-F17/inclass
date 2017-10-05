#include <stdio.h>

int fact_rec_a(int n);


int main(int argc, char **argv)
{
    int x;

    x = fact_rec_a(1);

    printf("x = %d\n", x);

    return 0;
}
