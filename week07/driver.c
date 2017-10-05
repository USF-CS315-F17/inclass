#include <stdio.h>

int sum_array_c(int *a, int len);

int fact_rec_c(int n);
int fact_rec_a(int n);


void test_sum_array(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int sum;

    sum = sum_array_c(a, 5);
    printf("sum_array_c({1,2,3,4,5}, 5) = %d\n", sum);

    return;
}

void test_fact_rec(void)
{
    int i;
    int v;

    for (i = 0; i < 5; i++) {
        v = fact_rec_c(i);
        printf("fac_rec_c(%d) = %d\n", i, v);
        v = fact_rec_a(i);
        printf("fac_rec_a(%d) = %d\n", i, v);
    }

    return;
}

int main(int argc, char **argv)
{
    printf("=== test_sum_array()\n");
    test_sum_array();
    printf("=== test_fac_rec()\n");    
    test_fact_rec();

    return 0;
}
