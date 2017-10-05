#include <stdio.h>
#include <stdlib.h>

void print_char_bits(char c)
{
    int i;
    int len = sizeof(char) * 8;
    int b;

    for (i = 0; i < len; i++) {
        b = (c >> ((len - 1) - i)) & 0b1;
        printf("%d", b);
    }

    printf("\n");
    
    return;
}

int main(int argc, char **argv)
{
    char c = 0xA3;
    char c2 = 0xA4;
    char b;
    unsigned int v = 0xA1B2C3D4;

    printf("c = %c\n", c);
    printf("c2 = %c\n", c2);
    printf("c = %02X\n", (unsigned) c);
    printf("c = ");
    print_char_bits(c);

    b = (c >> 4);

    printf("b = %02X\n", (unsigned) b);
    printf("b = ");
    print_char_bits(b);

    c = (v >> 16) & 0b1111;
    
    printf("c = %02X\n", (unsigned) c);
    printf("c = ");
    print_char_bits(c);

    printf("v = %08X\n", v);

    v = (v & 0xFFF0FFFF) | 0x00090000;

    printf("v = %08X\n", v);
    
    return 0;
}
