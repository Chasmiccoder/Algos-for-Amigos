/*
Problem:
https://codeforces.com/problemset/problem/1553/A
*/
#include<stdio.h>

int main() {

    int testcases;
    scanf("%d", &testcases);
    for ( int t = 0; t < testcases; t++ ) {
        int n;
        scanf("%d", &n);

        int result = (n+1) / 10;
        printf("%d\n", result);
    }

    return 0;
}