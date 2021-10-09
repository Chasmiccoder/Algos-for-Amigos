/*
Given two stings ransomNote and magazine, return true if ransomNote can be 
constructed from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example:
"aa"
"aab"

Output:
true
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    // O(nlogn)
    bool canConstruct(string ransomNote, string magazine) {
        int k = ransomNote.length();
        int n = magazine.length();
        
        if(k > n) {
            return false;
        }
        
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        
        int j = 0;
        
        for(int i = 0; i < n; i++) {
            if(ransomNote[j] == magazine[i]) {
                j++;
            }
        }
        
        if(j == k) {
            return true;
        }
        else {
            return false;
        }
    }
    
    // average time for unordered map is O(1) but can go up to O(n^2) in the worst case
    bool canConstruct2(string ransomNote, string magazine) {
        int k = ransomNote.length();
        int n = magazine.length();
        
        if(k > n) {
            return false;
        }
        
        unordered_map<string,int> frequency;
        
        for(int i = 0; i < n; i++) {
            string s = magazine.substr(i,1);
            if(frequency.find(s) == frequency.end()) {
                frequency[s] = 1;
            }
            else {
                frequency[s] += 1;
            }
        }
        
        for(int i = 0; i < k; i++) {
            string s = ransomNote.substr(i,1);
            if(frequency.find(s) == frequency.end()) {
                return false;
            }
            frequency[s] -= 1;
            if(frequency[s] < 0 ) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string magazine, ransomNote;
    cin >> ransomNote;
    cin >> magazine;

    Solution sol;
    cout << "With Sorting Algos: " << sol.canConstruct(ransomNote, magazine) << endl; // slightly faster
    cout << "With Unordered map: " << sol.canConstruct2(ransomNote, magazine) << endl;

    return 0;
}