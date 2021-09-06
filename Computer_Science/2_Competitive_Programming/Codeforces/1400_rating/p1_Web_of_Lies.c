/*
Problem:
https://codeforces.com/contest/1549/problem/C

===============
Spoilers Ahead!
===============

Observation:
If you encounter an edge, the lower valued noble is going to have to die

Algorithm:
Keep track of the nobles alive in a variable called 'result'

Keep track of the friendships that are a threat to the noble
    A friendship between nobles u and v is a threat to u if u < v

If a new edge is encountered, kill the noble with the lesser value, and add 1 to the
number of relationships that are a threat

While deleting a node, there is a chance that one noble will end up with 0 friends in which case
he is no longer vulnerable. So, bring him back to life
We can do this since it guaranteed that the mentioned edge involves nobles that are alive at the moment
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int *arr = (int*)malloc((n+1) * sizeof(int));
    memset(arr, 0, (n+1) * sizeof(int));

    int result = n; // number of nobels left

    for ( int i = 0; i < m; i++ ) {
        int u,v;
        scanf("%d %d", &u, &v);

        if ( u < v ) {
            arr[u] += 1; // add a friend that is a threat (makes u more vulnerable)
            
            // kill u if it has 1 friend that is a threat. If u has 0, he is safe. If he has more than 1 friend, we've already killed him
            if ( arr[u] == 1 ) {
                result--;
            }
        
        }
        else {
            arr[v] += 1; // same logic as above
            
            if ( arr[v] == 1 ) {
                result--;
            }
        }
    }

    int queries;
    scanf("%d", &queries);

    for ( int i = 0; i < queries; i++ ) {
        int type;
        scanf("%d", &type);
        if ( type == 1 ) {
            int u,v;
            scanf("%d %d", &u, &v);
            if ( u < v ) {
                arr[u] += 1;

                if ( arr[u] == 1 ) {
                    result--;
                }
            }
            else {
                arr[v] += 1;

                if ( arr[v] == 1 ) {
                    result--;
                }
            }
        }
        else if ( type == 2 ) {
            int u,v;
            scanf("%d %d", &u, &v);

            if ( u < v ) {
                arr[u] -= 1; // remove one friend who was a threat

                if ( arr[u] == 0 ) {
                    result++; // bring u back to life because he has 0 friends
                }
            }
            else {
                arr[v] -= 1;

                if ( arr[v] == 0 ) {
                    result++;
                }
            }
        }
        else if ( type == 3 ) {
            printf("%d\n", result); // print the current number of nobles left
        }
    }

    return 0;
}