/*
Problem:
https://codeforces.com/problemset/problem/1592/A

One day, Ahmed_Hossam went to Hemose and said "Let's solve a gym contest!". Hemose didn't want to do that, 
as he was playing Valorant, so he came up with a problem and told it to Ahmed to distract him. 
Sadly, Ahmed can't solve it... Could you help him?
There is an Agent in Valorant, and he has n weapons. The i-th weapon has a damage value ai, 
and the Agent will face an enemy whose health value is H.
The Agent will perform one or more moves until the enemy dies.

In one move, he will choose a weapon and decrease the enemy's health by its damage value. 
The enemy will die when his health will become less than or equal to 0. 
However, not everything is so easy: the Agent can't choose the same weapon for 2 times in a row.

What is the minimum number of times that the Agent will need to use the weapons to kill the enemy?

Input:
3
2 4
3 7
2 6
4 2
3 11
2 1 7

Output:
1
2
3

*/

#include<iostream>
#include<algorithm>
#include<limits.h>
#include<math.h>
using namespace std;

int main() {

    int test;
    scanf("%d", &test);
    for(int tt = 0; tt < test; tt++) {

        int n,h;
        scanf("%d %d", &n, &h);

        int greatest = INT_MIN;
        int secondGreatest = INT_MIN;

        for ( int i = 0; i < n; i++) {

            int attack;
            scanf("%d", &attack);

            if ( attack >= greatest ) {
                secondGreatest = greatest;
                greatest = attack;
            }

            else if ( attack > secondGreatest ) {
                secondGreatest = attack;
            }
        }

        int result;

        result = 2 * floor( (float)h / (greatest+secondGreatest) );

        if(result/2 * (greatest + secondGreatest) < h) {
            result++;
        }
        if(result/2 * (greatest + secondGreatest) + greatest < h) {
            result++;
        }

        printf("%d\n", result);
 
    }

    return 0;
}