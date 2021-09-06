/*
Problem:
https://codeforces.com/problemset/problem/1426/A
*/

#include <stdio.h>
#include <math.h>

int main() {
    int testcases;
    scanf("%d", &testcases);
    for( int t = 0; t < testcases; t++ ) {
        int n,x;
        scanf("%d %d", &n, &x);
        int ans = 1;

        if ( n > 2 ) {
            ans = (n-2) / x + 2;
            if ( (n-2) % x == 0 ) {
                ans--;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}