/*
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.

Example:
leetcode

Output:
0
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        // key: Character value: index of that character
        unordered_map<string,int> frequency;
        vector<string> chars;
        
        for(int i = 0; i < n; i++) {
            string ch = s.substr(i,1);
            if(frequency.find(ch) == frequency.end()) {
                frequency[ch] = i;
                chars.push_back(ch);
            }
            else {
                frequency[ch] = -1;
            }
        }
        
        for(auto ch : chars) {
            int pos = frequency[ch];
            if(pos != -1) {
                return pos; 
            }
        }
        
        return -1;
    }
};

int main() {

    string s;
    cin >> s;
    
    Solution sol;
    cout << sol.firstUniqChar(s);

    return 0;
}