/*
Problem:
https://codeforces.com/contest/1567/problem/B

Problem Statement
Alice gave Bob two integers a and b (a>0 and b>0). 
Being a curious boy, Bob wrote down an array of non-negative integers with MEX value of all elements 
equal to a and XOR value of all elements equal to b.
What is the shortest possible length of the array Bob wrote?

The input consists of multiple test cases. The first line contains an integer t - the number of test cases. 
The description of the test cases follows.
The only line of each test case contains two integers a and b 
(1 <= a <= 3 * 10^5; 0 <= b <= 3 * 10^5) — the MEX and XOR of the array, respectively.

Output
For each test case, output one (positive) integer — the length of the shortest array with MEX a and XOR b.

Example Input:
5
1 1
2 1
2 0
1 10000
2 10000

Output:
3
2
3
2
3

*/

#include<iostream>

using namespace std;


// Calculates 1 ^ 2 ^ 3 ^ ... ^ n
int XOR(int n) {
    
    if ( n % 4 == 0 ) {
        return n;
    }
    if ( n % 4 == 1 ) {
        return 1;
    }
    if ( n % 4 == 2 ) {
        return n+1;
    }
    if ( n % 4 == 3 ) {
        return 0;
    }
    
}

int main() {

    int testcases;
    scanf("%d", &testcases);
    for ( int test = 0; test < testcases; test++ ) {
        int a,b;
        scanf("%d %d", &a, &b);

        int answer = a;
    
        int xor1 = XOR(a-1);

        if ( xor1 != b ) {
            answer++;

            // case in which we need one more number such that the MEX of the array doesn't change
            if ( (xor1 ^ b) == a ) {
                answer++;
            }
        }

        printf("%d\n", answer);
    }
    return 0;
}