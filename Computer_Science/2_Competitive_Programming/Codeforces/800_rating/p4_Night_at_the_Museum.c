/*
Problem:
https://codeforces.com/problemset/problem/731/A
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b) {
    if ( a < b ) {
        return a;
    }
    else {
        return b;
    }
}

int main() {

    char word[100];
    scanf("%s", &word);

    int len = strlen(word);
    int count = 0;
    int pos = 0;

    for ( int i = 0; i < len; i++ ) {
        int place = word[i] - 97;

        count += min( abs(place - pos), abs(26 - abs(place - pos)) );

        // Update the previous letter
        pos = place;
    }

    printf("%d\n", count);

    return 0;
}