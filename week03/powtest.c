#include<stdio.h>
#include<math.h>

int main(int argc, char **argv)
{
    int x;
    float f;

    f = pow(10.0, 0.0);
    printf("f = %f\n", f);
    
    x = (int) pow(10, 0);

    printf("x = %d\n", x);

    return 0;
}
