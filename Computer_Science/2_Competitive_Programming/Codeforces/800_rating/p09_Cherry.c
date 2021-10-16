/*
Problem:
https://codeforces.com/problemset/problem/1554/A

find the max element during input
try finding second largest in valid range using greatest element as reference
*/

#include<stdio.h>
#include<stdlib.h>

int main() {

    int testcases;
    scanf("%d", &testcases);
    for ( int tt = 0; tt < testcases; tt++ ) {

        int n;
        scanf("%d", &n);

        int* arr = (int*)malloc(n * sizeof(int));

        for ( int i = 0; i < n; i++ ) {
            scanf("%d", &arr[i]);
        }

        long long maxResult = 0;
        for ( int l = 0; l < n; l++ ) {
            for ( int r = l+1; r < n; r++ ) {
                int min = arr[l];
                int max = arr[l];
                for( int i = l+1; i < r; i++ ) {
                
                    if ( max < arr[i] ) {
                        max = arr[i];
                    }
                    if ( min > arr[i] ) {
                        min = arr[i];
                    }
                }
                long long tmp = min * max;
                if ( maxResult < tmp ) {
                    maxResult = tmp;
                }
            }
        }

        printf("%d\n", maxResult);

    }

    return 0;
}

