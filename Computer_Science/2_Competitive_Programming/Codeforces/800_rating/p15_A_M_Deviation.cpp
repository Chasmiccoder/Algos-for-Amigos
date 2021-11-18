/*
Problem Link:
https://codeforces.com/problemset/problem/1605/A

Problem Statement:
A number a2 is said to be the arithmetic mean of two numbers a1 and a3, 
if the following condition holds: a1 + a3 = 2 * a2
We define an arithmetic mean deviation of three numbers a1, a2 and a3 as follows: d(a1,a2,a3) = |a1 + a3 - 2 * a2|

Arithmetic means a lot to Jeevan. 
He has three numbers a1, a2 and a3 and he wants to minimize the arithmetic mean deviation d(a1,a2,a3). 
To do so, he can perform the following operation any number of times (possibly zero):
    Choose i,j from {1,2,3} such that i !=j and increment ai by 1 and decrement aj by 1

What is the minimum value of the arithmetic mean deviation

Input:
13
3 4 5
2 2 6
1 6 5
1 1 1
1 1 2
1 1 3
1 1 4
1 1 5
1 1 6
1 1 7
1 1 8
1 1 9
1 1 10

Output:
0
1
0
0
1
1
0
1
1
0
1
1
0

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

// abs()
#include <cstdlib>

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

// For Faster IO  (Use either cin/cout or scanf/printf)
void FAST() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

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

/*
================
Debugging Tools
================
*/

#define db(i) cout << i << "\n";
#define dbV(vi) for(auto x : vi) { cout << x << " "; } cout << "\n";
#define dbM(map) for(auto x : map) { cout << x.first << " " << x.second << "\n"; } cout << "\n";

/*
==================
Useful Algorithms
==================
*/

// returns factors of integer in descending order
vector<int> getFactors(int n) {
    vector<int> vi;
    for(int i = n; i >= 1; i--) {        
        if(n % i == 0) {
            vi.pb(i);
        }
    }
    return vi;
}

// Takes a sorted vector and returns a vector of unique elements
template<typename X>
vector<X> getUnique(vector<X> vi) {
    X previous = vi[0];
    vector<X> result;
    result.pb(previous);
    
    for(auto x : vi) {
        if(x != previous) {
            result.pb(x);
        }
        previous = x;
    }
    return result;
}

int getGCD(int a, int b) {
    if(a == 0) {
        return b;
    }
    return getGCD(b%a, a);
}



/*
=======================
Problem Specific Funcs
=======================
*/

int solve() {
    int a1,a2,a3;
    cin >> a1 >> a2 >> a3;

    int result = abs(a1 + a3 - 2 * a2) % 3;
    if(result == 2)
        result = 1;
    return result;
}


/*
=======================
Quick Testing Function
=======================
*/
void Test(int correct = 0) {

    int n = 4;
    vector<int> vi = {210452, -553585, -303337, -97565};
    int ans = 1;
    // ans = solve();
    correct = 1;

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

    // Test();

    int testcases;
    cin >> testcases;
    for(int test = 0; test < testcases; test++) {

        int ans = solve();
        cout << ans << "\n";
    }

    return 0;
}


/*
Observations -

It won't matter if (i = 1 and j = 3) or (i = 3 and j = 1)
Therefore, 2 must be involved.

When a1 is incremented and a2 is decremented
a1 + a3 + 1 - 2 * (a2 - 1) = a1 + a3 - 2 * a2 + 3

When a1 is decremented and a2 is incremented
a1 + a3 - 1 - 2 * (a2 + 1) = a1 + a3 - 2 * a2 - 3

Either + 3 or - 3 get added in each move.

Find minimum using (mod 3)
If the answer is 2, return 1, since we can subtract 3 from it to get -1, and abs(-1) = 1

*/


/*

    ___|  |                             _)                        |             
   |      __ \    _` |   __|  __ `__ \   |   __|   __|   _ \   _` |   _ \   __| 
   |      | | |  (   | \__ \  |   |   |  |  (     (     (   | (   |   __/  |    
  \____| _| |_| \__,_| ____/ _|  _|  _| _| \___| \___| \___/ \__,_| \___| _|    

*/
