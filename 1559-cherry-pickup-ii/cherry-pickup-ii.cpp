class Solution {

    // Recursion
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, int rows, int cols) {
        // base case
        if(j1 >= cols || j1 < 0 || j2 >= cols || j2 < 0) {
            return 0;
        }

        if(i == rows-1) {
            if(j1 == j2) {
                return grid[i][j1];
            }
            else {
                return grid[i][j1] + grid[i][j2];
            }
        }
        int maxi = INT_MIN;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                if(j1 == j2) {
                    maxi = max(maxi,  grid[i][j1] + solve(i+1, j1+dj1, j2+dj2, grid, rows, cols));
                }
                else {
                    maxi = max(maxi,  grid[i][j1] + grid[i][j2] + solve(i+1, j1+dj1, j2+dj2, grid, rows, cols));
                }
            }
        }
        return maxi;
    }

    // Memoiation
    int solveMem(int i, int j1, int j2, vector<vector<int>>& grid, int rows, int cols, vector<vector<vector<int>>> &dp) {
        // base case
        if(j1 >= cols || j1 < 0 || j2 >= cols || j2 < 0) {
            return 0;
        }

        if(i == rows-1) {
            if(j1 == j2) {
                return grid[i][j1];
            }
            else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        int maxi = INT_MIN;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                if(j1 == j2) {
                    maxi = max(maxi,  grid[i][j1] + solveMem(i+1, j1+dj1, j2+dj2, grid, rows, cols, dp));
                }
                else {
                    maxi = max(maxi,  grid[i][j1] + grid[i][j2] + solveMem(i+1, j1+dj1, j2+dj2, grid, rows, cols, dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows+1, vector<vector<int>>(cols+1, vector<int>(cols+1, -1)));
        // return solve(0, 0, cols-1, grid, rows, cols);
        return solveMem(0, 0, cols-1, grid, rows, cols, dp);
    }
};