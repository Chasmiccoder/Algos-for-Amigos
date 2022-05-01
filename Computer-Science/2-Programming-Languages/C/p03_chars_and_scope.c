#include <stdio.h>

int T1 = 0;
int T2;

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

    {
        char c2 = 20;
    }
    
    // printf("%c\n", c2); // error, since c2 exists only within the above block 
    
    printf("T1: %d\n", T1);
    // printf("%d\n", T); // 'T' undeclared error (even though it is declared in global scope, after main)
    
    
    // In this scenario, T2 is defined in global scope, before main; but its assigned a value after main (in global scope)
    printf("T2: %d\n", T2);
    // Interestingly, this prints 5 (which is the assigned value)
    // But it also gives a data definition warning (as if it has been redefined after main)


    int var1 = 0;
    {
        int var1 = 2;
        printf("Inner Block: %d\n", var1);
    }
    printf("Outer Block: %d\n", var1);



    return 0;
}


int T = 2;
T2 = 5;
