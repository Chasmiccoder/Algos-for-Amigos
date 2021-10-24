/*
Problem:
https://codeforces.com/contest/1593/problem/D1

Problem Statement:
Polycarp has an array of n (n is even) integers a1, a2, ... , an. 
Polycarp conceived of a positive integer k. After that, Polycarp began performing the following 
operations on the array: take an index i (1 <= i <= n) and reduce the number ai by k.

After Polycarp performed some (possibly zero) number of such operations, it turned out that all 
numbers in the array became the same. Find the maximum k at which such a situation is possible, 
or print −1 if such a number can be arbitrarily large.

Input:
3
6
1 5 3 1 1 5
8
-1 0 1 -1 0 1 -1 0
4
100 -1000 -1000 -1000

Output:
2
1
1100

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
    if(a < 0) {
        a = abs(a);
    }
    if(b < 0) {
        b = abs(b);
    }

    if(a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    if(a == 0) {
        return b;
    }

    return getGCD(b % a, a);
}



/*
=======================
Problem Specific Funcs
=======================
*/

int solve(vector<int> vi, int n) {

    sort(vi.begin(), vi.end());

    if(vi[0] == vi[n-1]) {
        return -1;
    }

    vi = getUnique<int>(vi);
    n = vi.size();

    int smallest = vi[0];
    int answer = abs(smallest - vi[1]);

    for(int i = 2; i < n; i++) {
        int num = vi[i] - smallest;
        answer = getGCD(abs(answer), abs(num));
    }
    return answer;
}


/*
=======================
Quick Testing Function
=======================
*/
void Test(int correct = 0) {

    // int n = 6;
    // vector<int> vi = {1,5,3,1,1,5};
    // int ans = solve(vi,n);
    // correct = 2;


    int n = 4;
    vector<int> vi = {210452, -553585, -303337, -97565};
    int ans = solve(vi,n);
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

        int n;
        cin >> n;
        vector<int> vi = inpV<int>(n);

        int ans = solve(vi, n);

        cout << ans << "\n";
    }

    return 0;
}


/*
Observations -
If all the elements are the same, the answer is -1
Else
    1. ans = secondSmallest - smallest
    2. Find gcd(ans, xi-smallest). That is the new answer
    3. Do (2) for all xi
*/
