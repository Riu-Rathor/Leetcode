class Solution {
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int row, int col, int n, int m) {
        if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) {
            return 0;
        }

        int originalGoldValue = grid[row][col];
        grid[row][col] = 0;
        int maxGold = 0;
        // up, down , left, and right

        for(vector<int> &dir : directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            maxGold = max(maxGold, dfs(grid, new_row, new_col, n, m));
        }

        grid[row][col] = originalGoldValue;
        return originalGoldValue + maxGold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();

        int max_gold = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] != 0) {
                    max_gold = max(max_gold, dfs(grid, i, j, n, m));
                }
            }
        }
        return max_gold;
    }
};