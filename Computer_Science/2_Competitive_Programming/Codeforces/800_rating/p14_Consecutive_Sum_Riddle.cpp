/*
Problem:
https://codeforces.com/contest/1594/problem/A

You are given an integer n. You need to find two integers l and r such that −10^18 <=  l < r <= 10^18
l + (l+1) + ... + (r−1) + r = n

Input:
7
1
2
3
6
100
25
3000000000000

Output:
0 1
-1 2 
1 2 
1 3 
18 22
-2 7
999999999999 1000000000001

Observation:
Negative numbers cancel out their positive counterparts

*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int tt;
    scanf("%d", &tt);
    for(int test = 0; test < tt; test++) {
        long long n;
        scanf("%lld", &n);
        
        if(n > 0) {
            printf("%lld %lld\n",-n+1,n );
        }
        else {
            printf("%lld %lld\n", -(n+1),n);
        }
    }
    return 0;
}