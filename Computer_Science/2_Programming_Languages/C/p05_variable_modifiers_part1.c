// Compile using command:
// gcc -o variableModifier .\p05_variable_modifiers_part1.c .\p05_variable_modifiers_part2.c

#include <stdio.h>

extern int var;
extern int var; // multiple declaration is allowed since its only a declaration, and not a definition (no memory is being allocated)

int y;

int var2 = 10;

extern int var3 = 16; // By assigning a value to the extern variable, we are allocating space for it, which means that var3 from another scope (say, p05_variable_modifiers_part2), will not get fetched

int main() {

    extern int var2;
    printf("Extern var from another file: %d\n", var); // 15
    printf("Extern variable from this file, but not in this scope: %d\n", var2); // 10

    // the following 2 declarations are the same
    auto int x;
    // int x;

    printf("Auto variable: %d\n", x); // 4194432 (garbage value)
    printf("Global variable: %d\n", y); // 0 (assigned to 0 by default)

    return 0;
}