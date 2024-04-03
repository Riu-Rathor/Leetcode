class Solution {
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool solve(int i, int j, int index, vector<vector<char>>& board, string &word, int n, int m) {
        if(index == word.length()) {
            return true;
        }

        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') {
            return false;
        }

        if(board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &dir : direction) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(solve(new_i, new_j, index+1, board, word, n, m)) {
                return true;
            }
        }

        board[i][j] = temp;
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0] && solve(i, j, 0, board, word, n, m)) {
                    return true;
                }
            }
        }
        return false;
    }
};