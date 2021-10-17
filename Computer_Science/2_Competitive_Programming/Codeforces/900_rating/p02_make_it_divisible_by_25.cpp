/*
Problem:
https://codeforces.com/contest/1593/problem/B

Problem Statement:
It is given a positive integer n. In 1 move, one can select any single digit and remove it 
(i.e. one selects some position in the number and removes the digit located at this position). 
The operation cannot be performed if only one digit remains. 

If the resulting number contains leading zeroes, they are automatically removed.

Input:
5
100
71345
3259
50555
2050047

Output:
0
3
1
3
2
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;



/*
================
Debugging Tools
================
*/

#define db(i) cout << i << endl;




/*
=======================
Problem Specific Funcs
=======================
*/

// When we know that there is at least one Zero
// Final answer = 0
int onlyZero(string s, int index) {
    
    int n = s.length();
    int numZeros = 0;
    for(int i = index+1; i < n; i++) {
        if(s.substr(i,1) == "0") {
            numZeros++;
        }
    }
    return n - 1 - numZeros;
}

int findEndingPair(string s, int index, string type) {
    // start the search  from the LSB (index+1)

    int moves = 0;
    int i = index+1;
    bool found = false;

    vector<string> vi = {"0", "5"};
    if(type == "ending with 5") {
        vi[0] = "2";
        vi[1] = "7";
    }

    while(i < s.length()) {
        string ch = s.substr(i,1);

        if(ch != vi[0] && ch != vi[1]) {
            s.erase(i,1);
            moves++;
            i--;
        }
        else {
            found = true;
            break;
        }
        i++;        
    }

    if(found) {
        return moves + index;
    }
    return -1;
}

int solve(string s) {
    

    reverse(s.begin(), s.end());

    string lastTwo = s.substr(0,2);
    if(lastTwo == "00" || lastTwo == "52" || lastTwo == "05" || lastTwo == "57") { // when the number ends with: 00, 25, 50, 75
        return 0;
    }

    int n = s.length();
    vector<int> result;
    bool onlyZeroFound = true;
    bool get00or50 = true;
    bool get25or75 = true;

    int i = 0;
    
    while(i < s.length()) {
        string ch = s.substr(i,1);

        if(ch == "0") {
            if(onlyZeroFound) {
                onlyZeroFound = false;       
                result.push_back( onlyZero(s,i) );
            }
            if(get00or50) {
                get00or50 = false;
                result.push_back( findEndingPair(s,i, "ending with 0") );
            }
        }

        else if(ch == "5") {
            if(get25or75) {
                result.push_back( findEndingPair(s,i, "ending with 5") );
            }
        }

        i++;
    }

    int smallest = INT_MAX;
    for(auto x : result) {
        if(x != -1 && smallest > x) {
            smallest = x;
        }
    }
    return smallest;
}


/*
=======================
Quick Testing Function
=======================
*/
void Test(string s, int correct) {

    int ans = solve(s);
    if(ans != correct) {
        db("wrong\n");
    }
    else {
        db("right\n");
    }
    exit(0);
}

int main() {

    /*
    string s = "100101";  // 2
    s = "10576301";       // 4
    s =  "10076301";      // 4
    s = "1205";           // 1
    s = "50555";          // 3
    cout << "Input: " << s << endl; 
    Test(s,3);
    */

    int testcases;
    cin >> testcases;
    for(int test = 0; test < testcases; test++) {
        string num;
        cin >> num;

        int ans = solve(num);

        cout << ans << "\n";
    }

    return 0;
}


/*

Cases to take care of

If 0 is found:
    Reduce num to 0 [done]
    Find a 5 after 0 to get 50 [done]
    Find another 0 after 0 to get 00 [done]

If 5 is found:
    Find a 2 after 5 to get 25 [done]
    Find a 7 after 5 to get 75 [done]

*/