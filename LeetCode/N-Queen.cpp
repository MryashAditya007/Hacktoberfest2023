class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.')); // Initialize an empty chessboard
        
        solve(result, board, 0, n);
        
        return result;
    }
    
    void solve(vector<vector<string>>& result, vector<string>& board, int row, int n) {
        if (row == n) {
            result.push_back(board); // Found a valid solution, add it to the result
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q'; // Place a queen
                
                solve(result, board, row + 1, n); // Recur for the next row
                
                board[row][col] = '.'; // Backtrack: remove the queen
            }
        }
    }
    
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check the column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // Check the upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        // Check the upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
};

