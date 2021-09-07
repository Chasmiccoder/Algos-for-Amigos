/*
Problem:
https://codeforces.com/problemset/problem/1537/A
*/

#include <stdio.h>

int main() {
    
    int testcases;
    scanf("%d", &testcases);
    for ( int t = 0; t < testcases; t++ ) {
        int n;
        scanf("%d", &n);

        int sum = 0;
        for ( int i = 0; i < n; i++ ) {
            int num;
            scanf("%d", &num);
            sum += num;
        }

        int result = 0;
        if ( sum == n ) {
            result = 0;
        }
        else if ( sum > n ) { 
            result = sum - n;
        }
        else {
            result = 1;
        }
        
        printf("%d\n", result);
    }

    return 0;
}