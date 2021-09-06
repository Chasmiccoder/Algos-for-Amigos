/*
Problem:
https://codeforces.com/contest/1567/problem/A


Problem Statement:
=================
Alice has a grid with 2 rows and n columns. 
She fully covers the grid using n dominoes of size 1 by 2.
Alice may place them vertically or horizontally, and each cell should be covered by exactly one domino.

Input:
The first line contains an integer t the number of test cases 
The first line of each test case contains an integer n - the width of the grid.
The second line of each test case contains a string s consisting of n characters, 
each of which is either L, R, U, or D, representing the left, right, top, or bottom half of a domino, 
respectively. This string represents one of the rows of the grid.

Additional constraint on the input: each input corresponds to at least one valid tiling.

Output
For each test case, output one string - the other row of the grid, using the same format as the input string. 
If there are multiple answers, print any.

Example Input:
4
1
U
2
LR
5
LRDLR
6
UUUUUU

Output:
D
LR
LRULR
DDDDDD

*/

#include<iostream>
#include<string>

using namespace std;

int main() {

    int testcases;
    scanf("%d", &testcases);
    for( int test = 0; test < testcases; test++ ) {
        int n;
        scanf("%d", &n);

        string s = "";
        string ans = "";
        cin >> s;

        for( int i = 0; i < n; i++ ) {
            string c = s.substr(i,1);
            if ( c == "L" ) {
                ans += "LR";
                i++;
            }
            else if ( c == "U" ) {
                ans += "D";
            }

            else if ( c == "D" ) {
                ans += "U";
            }
            
        }

        cout << ans << "\n";
    }
    return 0;
}