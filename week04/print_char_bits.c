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

void print_char_bits_array(char c)
{
    int i;
    int len = sizeof(char) * 8;
    int a[len];

    for (i = 0; i < len; i++) {
        a[i] = c & 0b1;
        c = c >> 1;
    }

    for (i = (len - 1); i >= 0; i--) {
        printf("%d", a[i]);
    }

    printf("\n");

    return;
}

void print_char_bits_rec(char c, int n)
{
    int b;
    
    if (n == 0) {
        printf("\n");
        return;
    } else {
        b = (c >> (n - 1)) & 0b1;
        printf("%d", b);
        print_char_bits_rec(c, n-1);
        return;
    }
}

int main(int argc, char **argv)
{
    char c;
    
    if (argc != 2) {
        printf("usage: print_char_bits <string_of_one_char>\n");
        exit(-1);
    }

    c = argv[1][0];
    
    printf("char : %c\n", c);
    printf("ascii: %d\n", c);
    print_char_bits(c);
    print_char_bits_array(c);
    print_char_bits_rec(c, 8);

    return 0;
}
