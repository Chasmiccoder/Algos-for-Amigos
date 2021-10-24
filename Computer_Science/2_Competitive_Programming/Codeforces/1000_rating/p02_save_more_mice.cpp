/*
Problem:
https://codeforces.com/contest/1593/problem/C

Problem Statement:
There are one cat, k mice, and one hole on a coordinate line. 
The cat is located at the point 0, the hole is located at the point n. 
All mice are located between the cat and the hole: 
The i-th mouse is located at the point xi (0<xi<n). At each point, many mice can be located.
In one second, the following happens. 

First, exactly one mouse moves to the right by 1. 
If the mouse reaches the hole, it hides (i.e. the mouse will not any more move to any point 
and will not be eaten by the cat). Then (after that the mouse has finished its move) the 
cat moves to the right by 1. If at the new cat's position, some mice are located, the 
cat eats them (they will not be able to move after that). The actions are performed until 
any mouse hasn't been hidden or isn't eaten.

In other words, the first move is made by a mouse. If the mouse has reached the hole, it's saved. 
Then the cat makes a move. The cat eats the mice located at the pointed the cat has reached 
(if the cat has reached the hole, it eats nobody).

Each second, you can select a mouse that will make a move. 
What is the maximum number of mice that can reach the hole without being eaten?


Input Format:
The first line contains one integer t (1 <= t <= 10^4) — the number of test cases. Then t test cases follow.
Each test case consists of two lines. The first line contains two integers n and k (2 <= n <= 10^9, 1 <= k <= 4 ⋅ 10^5). 
The second line contains k integers x1,x2,…xk (1≤xi<n) — the initial coordinates of the mice.

It is guaranteed that the sum of all k given in the input doesn't exceed 4 . 10^5.

Input:
3
10 6
8 7 5 4 9 4
2 8
1 1 1 1 1 1 1 1
12 11
1 2 3 4 5 6 7 8 9 10 11

Output:
3
1
4

*/

// cin, cout
#include <iostream>

// string, erase()
#include <string>

// vector<>, push_back(), pop_back()
#include <vector>

// sort()
#include <algorithm>

// INT_MIN, INT_MAX
#include <limits.h>

// pair, make_pair()
#include <utility>

// unordered_map, find()
#include <unordered_map>

using namespace std;


/*
====================
Function Shortcuts
====================
*/

#define pb push_back
#define mp make_pair


/*
=================================
Input / Output Helper Functions
=================================
*/

// Take n elements from the user and store them in a vector (int, long long, string, ...)
template<typename X>
vector<X> inpV(int n) {
    vector<X> vi;
    for(int i = 0; i < n; i++) {
        X tmp;
        cin >> tmp;
        vi.push_back(tmp);
    }
    return vi;
}


// For Faster IO  (Use either cin/cout or scanf/printf)
void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


/*
================
Debugging Tools
================
*/

#define db(i) cout << i << "\n";
#define dbV(vi) for(auto x : vi) { cout << x << " "; } cout << "\n";
#define dbM(map) for(auto x : map) { cout << x.first << " " << x.second << "\n"; } cout << "\n";



/*
=======================
Problem Specific Funcs
=======================
*/

int solve(vector<int> board, int n, int k) {
    board.pb(0);
    board.pb(n);

    sort(board.begin(), board.end());

    int saved = 0;
    int i = 0;
    int j = k;
    int currentMouse = board[j];
    int cat = 0;
    
    while(currentMouse > cat) {
        while(currentMouse < n) {
            currentMouse++;
            cat++;
        }
        saved++;
        j--;
        currentMouse = board[j];
    }

    // db(saved);
    return saved;
}


/*
=======================
Quick Testing Function
=======================
*/
void Test(int correct) {

    // int n = 10, k = 6;
    // vector<int> vi = {8, 7, 5, 4, 9, 4};
    // correct = 3;

    // int n = 2, k = 8;
    // vector<int> vi = {1,1,1,1,1,1,1,1};
    // correct = 1;

    int n = 12, k = 11;
    vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    correct = 4;

    int ans = solve(vi,n,k);
    if(ans != correct) {
        db("wrong\n");
    }
    else {
        db("right\n");
    }
    exit(0);
}

int main() {
    FAST();

    // Test(3);

    int testcases;
    cin >> testcases;
    for(int test = 0; test < testcases; test++) {

        int n,k;
        cin >> n >> k;

        vector<int> vi = inpV<int>(k);

        int ans = solve(vi, n, k);

        cout << ans << "\n";
    }

    return 0;
}


/*

Observations -
Compute the cumulative steps taken by the cat, and by the mice
Keep processing until the cat catches up to the furthest non-safe mouse
Greedy strategy = Let the mouse closest to the hole be moved ahead

*/