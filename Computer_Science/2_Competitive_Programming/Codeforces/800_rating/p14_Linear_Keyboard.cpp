/*
Problem:
https://codeforces.com/problemset/problem/1607/A

Problem Statement:
You are given a keyboard that consists of 26 keys. 
The keys are arranged sequentially in one row in a certain order. 
Each key corresponds to a unique lowercase Latin letter.

You have to type the word s on this keyboard. It also consists only of lowercase Latin letters.
To type a word, you need to type all its letters consecutively one by one. 
To type each letter you must position your hand exactly over the corresponding key and press it.

Moving the hand between the keys takes time which is equal to the absolute value of the difference 
between positions of these keys (the keys are numbered from left to right). 
No time is spent on pressing the keys and on placing your hand over the first letter of the word.

For example, consider a keyboard where the letters from 'a' to 'z' are arranged in consecutive alphabetical order. 
The letters 'h', 'e', 'l' and 'o' then are on the positions 8, 5, 12 and 15, respectively. 
Therefore, it will take |5−8|+|12−5|+|12−12|+|15−12|=13 units of time to type the word "hello".

Determine how long it will take to print the word s.

Input:
5
abcdefghijklmnopqrstuvwxyz
hello
abcdefghijklmnopqrstuvwxyz
i
abcdefghijklmnopqrstuvwxyz
codeforces
qwertyuiopasdfghjklzxcvbnm
qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
qwertyuiopasdfghjklzxcvbnm
abacaba

Output:
13
0
68
0
74

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

int solve(string keyboard, string word) {
    unordered_map<string,int> pos;
    int len = keyboard.length();
    for(int i = 0; i < len; i++) {
        pos[keyboard.substr(i,1)] = i+1;
    }

    int n = word.length();
    int answer = 0;
    int previous = pos[word.substr(0,1)];
    
    for(int i = 1; i < n; i++) {
        string ch = word.substr(i,1);
        int current = pos[ch];    
        answer += abs(current - previous);
        previous = current;
        
    }

    return answer;
   
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

        string keyboard,word;
        cin >> keyboard;
        // vector<int> vi = inpV<int>(n);
        cin >> word;

        int ans = solve(keyboard,word);

        cout << ans << "\n";
    }

    return 0;
}


/*
Observations -

*/


/*

    ___|  |                             _)                        |             
   |      __ \    _` |   __|  __ `__ \   |   __|   __|   _ \   _` |   _ \   __| 
   |      | | |  (   | \__ \  |   |   |  |  (     (     (   | (   |   __/  |    
  \____| _| |_| \__,_| ____/ _|  _|  _| _| \___| \___| \___/ \__,_| \___| _|    

*/
