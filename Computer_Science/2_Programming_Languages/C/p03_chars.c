#include <stdio.h>

int main() {
    // char can hold 1 byte
    char c = 65;
    printf("%c\n", c);
    c = 'B';
    printf("%c\n", c);

    /*
    what gets displayed depends on the binary representation of the number.
    Since char has only 1 byte (8 bits), the numbers 128 and -128 will have the same
    binary representation 10000000b = 2^7 
    and 10000000b = -2^7

    Similarly, 
    -1 and 255 will have the same binary representation (space ' ')
    -1   = 11111111b = -2^7 + 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0
    255  = 11111111b = +2^7 + 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0

    */

    c = 128;
    printf("128: %c\n", c);
    c = -128;
    printf("-128: %c\n", c);

    c = -1;
    printf("128: %c\n", c);
    c = 255;
    printf("-128: %c\n", c); // both print a space ' '

    return 0;
}