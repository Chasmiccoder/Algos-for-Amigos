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