/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
    * Integers in each row are sorted from left to right.
    * The first integer of each row is greater than the last integer of the previous row.
    
Input:  [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
3 4
1  3  5  7
10 11 16 20
23 30 34 60
3

Output:
true

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> rowFound = findRow(matrix, target, m, n);
        
        if(rowFound[0] == -1) {
            return false;
        }
        
        if(rowFound[1] == 1) {
            return true;
        }
        
        return BinarySearch(matrix, target, rowFound[0], n);
        
    }
    
    vector<int> findRow(vector<vector<int>>& matrix, int target, int m, int n) {
        /*
        Uses Binary Search on the first column of a matrix and returns
        an array of 2 integers.
        
        Case 1
        If the first integer is -1, then the target cannot exist in the matrix
        
        Case 2
        If the first integer is k (k!=-1), and the second integer is 0, then
        the target may exist in row k
        
        Case 3
        If the first integer is k (k!=-1), and the second integer is 1, then
        the target exists at matrix[k][0]
        
        
        */
        
        // Target out of array bounds (Case 1)
        if(matrix[0][0] > target || matrix[m-1][n-1] < target) {
            return {-1, -1};
        }
        
        int ll = 0;
        int ul = m-1;
        
        while(ul >= ll) {
            int mid = (ll+ul)/2;
            
            // Case 2
            if(matrix[mid][0] == target) {
                return {mid, 1};
            }
            
            // Case 3
            else if(mid == m-1 || (matrix[mid][0] < target && matrix[mid+1][0] > target)) {
                return {mid, 0};   
            }
            
            else if(matrix[mid][0] < target) {
                ll = mid + 1;
            }
            else {
                ul = mid - 1;
            }
            
        }
        
        cout << "Something went wrong" << endl;
        return {-1,-1};
        
    }
    
    bool BinarySearch(vector<vector<int>> matrix, int x, int row, int n) {
        int ll = 0;
        int ul = n-1;
        
        while(ul >= ll) {
            int mid = (ll+ul)/2;
            
            if(matrix[row][mid] == x) {
                return true;
            }
            else if(matrix[row][mid] > x) {
                ul = mid-1;
            }
            else {
                ll = mid+1;
            }
        }
        
        return false;
    }
    
};


int main() {

    int m,n;
    cin >> m >> n;
    vector<vector<int>> vi;
    for(int i = 0; i < m; i++) {
        vector<int> row;
        for(int j = 0; j < n; j++) {
            int k;
            cin >> k;
            row.push_back(k);
        }
        vi.push_back(row);
    }

    int target;
    cin >> target;

    Solution sol;
    cout << sol.searchMatrix(vi,target) << endl;

    return 0;
}