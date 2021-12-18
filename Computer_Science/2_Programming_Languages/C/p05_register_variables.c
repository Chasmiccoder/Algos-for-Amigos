#include <stdio.h>

int main() {
    register int i = 0;
    printf("Register var's value: %d\n", i);

    int i2 = 100;
    register int* ptr2 = &i2; // can be pointer
    printf("Register as a pointer: %d\n", *ptr2);

    return 0;
}