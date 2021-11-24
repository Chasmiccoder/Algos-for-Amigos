// Compile using command:
// gcc -o variableModifier .\p05_variable_modifiers_part1.c .\p05_variable_modifiers_part2.c

#include <stdio.h>

extern int var;
extern int var; // this is allowed since its only a declaration, and not a definition (no memory is being allocated)

int var2 = 10;
int main() {
    extern int var2;
    printf("Extern var from another file: %d\n", var);
    printf("Extern variable from this file, but not in this scope: %d\n", var2);

    return 0;
}