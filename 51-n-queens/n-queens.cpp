class Solution {
    bool isValid(vector<string> &board, int row, int col, int n) {
        // check upward
        for(int i=row-1; i>=0; i--) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        // left diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        // right diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> &board, int row, vector<vector<string>> &result, int n) {
        if(row >= n) {
            result.push_back(board);
            return;
        }
        for(int col=0; col<n; col++) {
            if(isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, row+1, result, n);
                board[row][col] = '.';
            }
        }        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;

        vector<string> board(n, string(n, '.'));
        solve(board, 0, result, n);
        return result;
    }
};