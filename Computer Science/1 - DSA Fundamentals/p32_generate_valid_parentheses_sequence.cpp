/*

You are given the number of opening parentheses (n)
Find all the possible balanced parentheses equations

for example, for n = 3, we get
()()()
()(())
(())()
(()())
((()))

5 permutations

The number of permutations is given by  (2nCn) / (n+1)

Reference:
https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(string str, int n, int pos, int start, int end, vector<string> &result ) {
    if ( end == n ) {
        result.push_back( str );
        return;
    }

    else { 
        if ( start > end ) {
            str[pos] = ')';
            solve( str, n, pos+1, start, end+1, result );
        }

        if ( start < n ) {
            str[pos] = '(';
            solve( str, n, pos+1, start+1, end, result );
        }
    }
}


vector<string> generateParenthesis( int n ) {
    vector<string> result;
    string sequence = "";
    for ( int i = 0; i < 2*n; i++ ) {
        sequence += "*";
    }

    if ( n > 0 ) {
        solve( sequence, n, 0, 0, 0, result );
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the value of n:\n";
    cin >> n;
    
    vector<string> result = generateParenthesis(n);

    cout << "There are " << result.size() << " such valid permutations\n";
    for ( auto x : result ) {
        cout << x << "\n";
    }

    cout << "\n";

    return 0;
}