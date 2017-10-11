#include <stdio.h>

int rec_sum_c(int *a, int len);
int rec_sum_a(int *a, int len);

int main(int argc, char **argv)
{
    int a[] = {1, 2, 3, 4, 5};
    int len = 5;
    int s;

    s = rec_sum_c(a, len);
    printf("rec_sum_c({1, 2, 3, 4, 5}, 5) = %d\n", s);


    s = rec_sum_a(a, len);
    printf("rec_sum_a({1, 2, 3, 4, 5}, 5) = %d\n", s);

    return 0;
}

