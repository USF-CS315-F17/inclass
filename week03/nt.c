#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 64
#define MAX_BIT_WIDTH 32

/* The nt_info struct helps keep track of the conversion process and
   supports a normalize representation.
*/
struct nt_info {
    char input[MAX_INPUT_LEN];
    int width;
    int r0;
    int r1;
    unsigned int value;
};

/* Initialize an nt_info struct to default and known initial values. */
void nt_info_init(struct nt_info *nti)
{
    nti->input[0] = '\0';
    nti->width = MAX_BIT_WIDTH;
    nti->r0 = 0;
    nti->r1 = 0;
    nti->value = 0;

    return;
}

/* Print an in_info struct for debugging purposes. */
void nt_info_print(struct nt_info *nti)
{
    printf("input = %s\n", nti->input);
    printf("width = %d\n", nti->width);
    printf("r0    = %d\n", nti->r0);
    printf("r1    = %d\n", nti->r1);
    printf("value = %u\n", nti->value);

    return;
}

/* A helpful usage message. */
void print_usage(void)
{
    printf("usage: nt [-b width] [-r start,end] value\n");
    printf("  width is 4, 8, 16, 32 (default)\n");
    printf("  start is 0 to 31, end is 0 to 31\n");
    printf("  value can be binary, hexadecimal, unsigned or signed decimal.\n");
    return;
}

/* Parse the command line arguments. */
/* NOTE: This will need to be modified to support -b and -r. */
void parse_args(int argc, char **argv, struct nt_info *nti)
{
    if (argc < 2) {
        printf("Insufficient arguments.\n");
        print_usage();
        exit(-1);
    }

    /* Assume the input value is argv[1]. */
    strcpy(nti->input, argv[1]);
    
    return;
}

/* Does the string look like binary input? */
bool is_binary(char *s)
{
    return (s[0] == '0' && s[1] == 'b');
}

/* Validate a binary string value. */
void validate_binary(struct nt_info *nti)
{
    int i;
    bool valid = true;
    int len;
    char c;

    len = strlen(nti->input);

    /* The input must ahave at least one binary digit. E.g., 0b1. */
    /* Also, the number of binary digits cannot exceed the width. */
    if (len < 3 || len > MAX_BIT_WIDTH + 2) {
        valid = false;
    } else {
        for (i = 0; i < MAX_BIT_WIDTH; i++) {
            c = nti->input[i + 2];
            /* If at end of input, then break. */
            if (c == '\0') {
                break;
            }
            /* Check if each digit is a valid binary value. */
            if (!(c == '0' || c == '1')) {
                valid = false;
                break;
            }
        }
    }

    if (!valid) {
        printf("Invalid binary input: %s\n", nti->input);
        print_usage();
        exit(-1);
    }
    
    return;
}

/* Convert a valid binary string into an unsigned int value. */
void normalize_binary(struct nt_info *nti)
{
    unsigned int v = 0;
    int i;
    char c;
    int b;
    int len = strlen(nti->input);

    for (i = 2; i < len; i++) {
        /* Left shift v by one to make room for next bit. */
        /* First time through, v == 0, so this does not change v. */
        v = v << 1;

        /* Get integer value of binary character. */
        c = nti->input[i];
        if (c == '0') {
            b = 0;
        } else if (c == '1') {
            b = 1;
        }

        /* Use logical or to place b in the least significant position of v. */
        v = v | b;
    }

    nti->value = v;
}

/* Convert all valid input representations to the normalized form. */
void normalize_input(struct nt_info *nti)
{

    if (is_binary(nti->input)) {
        validate_binary(nti);
        normalize_binary(nti);
    }
    /* NOTE: Add more checks here for additional forms of input. */
    
    return;
}

void print_binary_value_c_literal(struct nt_info *nti) {
    int i;
    int b;

    printf("0b");
    for (i = nti->width; i >= 0; i--) {
        b = (nti->value >> i) & 0b1;
        printf("%d", b);
    }
    printf(" (base 2)\n");

    return;
}

void print_unsigned_value(struct nt_info *nti)
{
    printf("%u (base 10 unsigned)\n", nti->value);
}

void print_conversions(struct nt_info *nti)
{
    print_binary_value_c_literal(nti);
    print_unsigned_value(nti);
    return;
}

int main(int argc, char **argv)
{
    struct nt_info nti;

    nt_info_init(&nti);

    parse_args(argc, argv, &nti);

    normalize_input(&nti);

    print_conversions(&nti);

    return 0;
}
