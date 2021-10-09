/*
Determine if a 9 x 9 Sudoku board is valid.
Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
* A Sudoku board (partially filled) could be valid but is not necessarily solvable.
* Only the filled cells need to be validated according to the mentioned rules.

Example:
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

Input:
5 3 . . 7 . . . . 6 . . 1 9 5 . . . . 9 8 . . . . 6 . 8 . . . 6 . . . 3 4 . . 8 . 3 . . 1 7 . . . 2 . . . 6 . 6 . . . . 2 8 . . . . 4 1 9 . . 5 . . . . 8 . . 7 9

Output: 1 (true, since this board is valid)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int dim = 9; // dimensions of the Sudoku Board
        for(int i = 0; i < dim; i++) {
            
            unordered_map<int,int> row;
            unordered_map<int,int> col;
            
            for(int j = 0; j < dim; j++) {
                
                // Checks if row 'i' is valid
                if(board[i][j] != '.') {
                    
                    if(row.find(board[i][j]) == row.end()) {
                        row[board[i][j]] = 1;
                    }
                    else {
                        
                        return false;
                    }
                }
                
                // Checks if column 'i' is valid
                if(board[j][i] != '.') {
                    
                    if(col.find(board[j][i]) == col.end()) {
                        col[board[j][i]] = 1;
                    }
                    else {
                        
                        return false;
                    }
                }
                
                // Box topleft squares: [0,0],[0,3],[6,9],[3,0],...
                // if we have found the topleft square of the box, see
                // if that box is valid
                if(i % 3 == 0 && j % 3 == 0) {
                    unordered_map<int,int> box;
                    for(int l = 0; l < 3; l++) {
                        for(int k = 0; k < 3; k++) {
                            
                            if(board[i+l][j+k] != '.' && box.find(board[i+l][j+k]) == box.end()) {
                                box[board[i+l][j+k]] = 1;
                            }
                            else if(board[i+l][j+k] != '.') {
                                
                                return false;
                            }
                        }
                    }
                }
                
            }
        }
        
        return true;
    }
};

int main() {

    vector<vector<char>> board;
    for(int i = 0; i < 9; i++) {
        vector<char> row;
        for(int j = 0; j < 9; j++) {
            char ch;
            cin >> ch;
            row.push_back(ch);
        }
        board.push_back(row);
    }

    Solution sol;
    cout << sol.isValidSudoku(board);

    return 0;
}











