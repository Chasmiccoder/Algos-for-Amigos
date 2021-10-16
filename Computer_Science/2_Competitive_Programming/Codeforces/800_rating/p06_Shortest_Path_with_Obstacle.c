/*
Problem:
https://codeforces.com/problemset/problem/1547/A

There are three cells on an infinite 2-dimensional grid, labeled A, B, and F. Find the length of the shortest path from A to B if:
    * in one move you can go to any of the four adjacent cells sharing a side;
    * visiting the cell F is forbidden (it is an obstacle).


Input
The first line contains an integer t (1 <= t <= 10^4) — the number of test cases in the input. 
Then t test cases follow. Before each test case, there is an empty line.

Each test case contains three lines. The first one contains two integers xA,yA (1 <= xA, yA <= 1000) — 
coordinates of the start cell A. The second one contains two integers xB,yB (1 <= xB, yB <= 1000) — 
coordinates of the finish cell B. 
The third one contains two integers xF,yF (1 <= xF, yF <= 1000) — 
coordinates of the forbidden cell F. All cells are distinct.

Coordinate x corresponds to the column number and coordinate y corresponds to the row number

Output
Output t lines. The i-th line should contain the answer for the i-th test case: 
the length of the shortest path from the cell A to the cell B if the cell F is not allowed to be visited.

Example
Input:
7

1 1
3 3
2 2

2 5
2 1
2 3

1000 42
1000 1
1000 1000

1 10
3 10
2 10

3 8
7 8
3 7

2 1
4 1
1 1

1 344
1 10
1 1

Output:
4
6
41
4
4
2
334

Observation:
The Position of F doesn't matter if the points are not concurrent
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