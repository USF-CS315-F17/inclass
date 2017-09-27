#include <stdio.h>

int count_zeros_a(int *array, int len);

int array_static[] = {1, 0, 2, 0, 3};

int count_zeros_index(int *array, int len)
{
    int i;
    int count = 0;

    for (i = 0; i < len; i++) {
        if (array[i] == 0) {
            count += 1;
        }
    }

    return count;
}

int count_zeros_ptr(int *array, int len)
{
    int i;
    int count = 0;

    for (i = 0; i < len; i++) {
        if (*array == 0) {
            count += 1;
        }
        array += 1;
    }

    return count;
}
    

int main(int argc, char **argv)
{
    int count;
    int array_stack[] = {100, 0, 0, 200, 0};

    count = count_zeros_index(array_static, 5);
    printf("count_zeros_index({1, 0, 2, 0, 3}, 5) = %d\n", count);
    count = count_zeros_index(array_stack, 5);
    printf("count_zeros_index({100, 0, 0, 200, 0}, 5) = %d\n", count);

    count = count_zeros_ptr(array_static, 5);
    printf("count_zeros_ptr({1, 0, 2, 0, 3}, 5) = %d\n", count);
    count = count_zeros_ptr(array_stack, 5);
    printf("count_zeros_ptr({100, 0, 0, 200, 0}, 5) = %d\n", count);

    count = count_zeros_a(array_static, 5);
    printf("count_zeros_a({1, 0, 2, 0, 3}, 5) = %d\n", count);
    count = count_zeros_a(array_stack, 5);
    printf("count_zeros_a({100, 0, 0, 200, 0}, 5) = %d\n", count);            

    return 0;
}
