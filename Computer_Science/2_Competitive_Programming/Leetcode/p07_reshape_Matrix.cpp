/*
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into 
a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows 
and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the 
same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; 
Otherwise, output the original matrix.

Example Input
{{1,2},{3,4}}
1 4

Output Vector:
{{1,2,3,4}}

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        vector<vector<int>> vi;
        int m = mat.size();
        int n = mat[0].size();
        
        if(r*c != m*n) {
            return mat;
        }
        
        int i = 0;
        int j = 0;
        
        for(int l = 0; l < r; l++) {
            vector<int> row;
            for(int k = 0; k < c; k++) {
                
                row.push_back(mat[i][j]);
                update(&i, &j, m, n);
            }
            vi.push_back(row);
        }
        
        return vi;
    }
    
    void update(int* i, int* j, int m, int n) {
        if(*j < n-1) {
            *j = *j + 1;
        }
        else {
            *j = 0;
            *i = *i + 1;    
        }
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

    int r,c;
    cin >> r >> c;
    
    Solution sol;
    vector<vector<int>> newV = sol.matrixReshape(vi,r,c);

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << newV[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}