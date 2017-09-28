#include <stdio.h>

void array_times_s_a(int *array, int len, int s);

int array1[100];
int array2[100];

void array_copy(int *array1, int *array2, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        array1[i] = array2[i];
    }
}

void array_times_s(int *array, int len, int s) {
    int i;

    for (i = 0; i < len; i++) {
        array[i] = array[i] * s;
    }
}

void print_array(int *array, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}
        

int main(int argc, char **argv)
{
    int i;
    int n = 4;

    for (i = 0; i < n; i++) {
        array2[i] = i;
    }

    print_array(array2, n);
    printf("\n");

    array_copy(array1, array2, n);
    print_array(array1, n);
    printf("\n");

    array_times_s(array1, n, 2);
    print_array(array1, n);
    printf("\n");

    array_copy(array1, array2, n);
    array_times_s_a(array1, n, 2);
    print_array(array1, n);
    printf("\n");
    
    return 0;
}
