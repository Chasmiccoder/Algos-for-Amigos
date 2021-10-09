/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {

    string a,b;
    cin >> a >> b;
    Solution sol;
    cout << sol.isAnagram(a,b) << endl;

    return 0;
}