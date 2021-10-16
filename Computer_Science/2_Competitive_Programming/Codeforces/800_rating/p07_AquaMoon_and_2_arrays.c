/*
Problem:
https://codeforces.com/problemset/problem/1546/A
*/
#include<stdio.h>
#include<stdlib.h>

// returns an array of 2 elements with the indices corresponding to first occurrence of positive and first occ. of negative difference
int* getUnfinished(int *differences, int n) {
    int *result = (int*)malloc(2 * sizeof(int));

    int foundPositive = 0;
    int foundNegative = 0;

    for ( int i = 0; i < n; i++ ) {
        if ( !foundPositive && differences[i] > 0 ) {
            result[0] = i;
            foundPositive = 1;
        }
        if ( !foundNegative && differences[i] < 0 ) {
            result[1] = i;
            foundNegative = 1;
        }
    }

    if ( foundNegative == 0 ) {
        result[1] = n; // ran out of negative
    }
    if ( foundPositive == 0 ) {
        result[0] = n;
    }

    return result;
}


int main() {

    int testcases;
    scanf("%d", &testcases);
    for( int t = 0; t < testcases; t++ ) {

        int n;
        scanf("%d", &n);
        
        int* A = (int*)malloc(n * sizeof(int));
        int* B = (int*)malloc(n * sizeof(int));
        for ( int i = 0; i < n; i++ ) {
            scanf("%d", &A[i]);
        }
        for ( int i = 0; i < n; i++ ) {
            scanf("%d", &B[i]);
        }


        int sumOfDifferences = 0; // Add a[i] - b[i] here
        int* differences = (int*)malloc(n * sizeof(int));
        int numberOfMoves = 0;

        for ( int i = 0; i < n; i++ ) {
            
            differences[i] = A[i] - B[i];
            sumOfDifferences += differences[i];
            numberOfMoves += abs(differences[i]);
            
        }
        numberOfMoves = numberOfMoves / 2;

        // If the number of positives is not the same as the number of negatives, 
        // it is not possible to solve the problem
        if ( sumOfDifferences != 0 ) {
            printf("-1\n");
        }

        else {
            printf("%d\n", numberOfMoves);

            int *indices = getUnfinished(differences, n);
            
            // both run out at the same time, since the solution is possible
            while( indices[0] != n && indices[1] != n ) {

                // make a 'move'
                differences[indices[0]] += -1;
                differences[indices[1]] += +1;

                printf("%d %d\n", indices[0]+1, indices[1]+1);

                indices = getUnfinished(differences, n);

            }
            
        }

    }

    return 0;
}

