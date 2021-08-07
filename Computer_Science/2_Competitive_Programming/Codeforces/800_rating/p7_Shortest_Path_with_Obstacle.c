/*
Problem:
https://codeforces.com/problemset/problem/1547/A



The Position of F doesn't matter if the points are not concurrent
Proof:



If the points are concurrent, and if F is in between A and B, then 
we need to add 2 more steps (shift line by one, and one more step to come back to the original line
after dodging the obstacle)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int testcases;
    scanf("%d", &testcases);
    for( int i = 0; i < testcases; i++ ) {
        int Ax,Ay,Bx,By,Fx,Fy;

        scanf("%d %d", &Ax, &Ay);
        scanf("%d %d", &Bx, &By);
        scanf("%d %d", &Fx, &Fy);

        int result = abs( Ax - Bx ) + abs( Ay - By );

        // If points are concurrent
        if ( (Ax == Bx && Bx == Fx && (Ay < Fy && Fy < By || By < Fy && Fy < Ay) ) 
          || (Ay == By && By == Fy && (Ax < Fx && Fx < Bx || Bx < Fx && Fx < Ax) ) ) {
            result += 2; // One move to dodge the obstacle and the other to come back
        }

        printf("%d\n", result);
    }

    return 0;
}