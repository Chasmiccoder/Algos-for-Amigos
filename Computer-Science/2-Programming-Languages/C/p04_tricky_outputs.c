#include <stdio.h>

int main() {
    
    printf("%d", printf("%s", "Hello, World!"));
    // Hello, World!13
    // printf returns the number of characters it has printed

    printf("\n");

    printf("%10s", "Hello");
    //      Hello
    // prints "Hello" with 5 spaces before it since "Hello" is 5 characters short of 10

    printf("\n");

    printf("%10s", "Hello, World!");
    // Hello, World!
    // prints the whole string

    printf("\n");

    char c = 255;
    c = c + 10;
    printf("%d", c);
    // 9
    // char can take values from [0,255], after which it cycles back. (8 bits, 2^8 = 256 )

    printf("\n");

    /*
    valid integer declarations
    
    signed int i;
    signed i;
    unsigned i;
    long i;
    long int i;
    long long int i;
    long long i;          // same as long long int i
    */

    unsigned i = 1;
    int j = -4;
    printf("%u", i+j);
    // 4294967293
    // 1 - 4 = -3, and -3 in 2's complement is the same as 4294967293 for unsigned
    // OR, you can say that 2**32 - 3 = 4294967293
    // will print -3 for "%d"

    printf("\n");

    return 0;
}


