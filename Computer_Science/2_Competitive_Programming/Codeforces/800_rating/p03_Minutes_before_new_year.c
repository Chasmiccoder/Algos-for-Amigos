/*
Problem:
https://codeforces.com/problemset/problem/1283/A
*/
#include <stdio.h>

int main() {

    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++) {
        int hours, minutes;
        scanf("%d %d", &hours, &minutes);
        int result = (24 - (hours+1)) * 60 + 60 - minutes;
        printf("%d\n", result);
    }

    return 0;
}