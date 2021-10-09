/*
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it
Example:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal = {{1}};
        
        for(int i = 1; i < numRows; i++) {
            vector<int> row = {1};
            int prevRowLen = pascal[i-1].size();
            for(int j = 1; j < prevRowLen; j++) {
                row.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
            }
            row.push_back(1);
            pascal.push_back(row);
        }
        return pascal;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<vector<int>> res;
    res = sol.generate(n);
    for(auto i : res) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}