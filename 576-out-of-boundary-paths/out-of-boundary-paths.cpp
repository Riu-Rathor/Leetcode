#define MOD 1000000007
class Solution {
    int solve(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>> &dp) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }
        if(maxMove <= 0) {
            return 0;
        }
        if(dp[i][j][maxMove] != -1) {
            return dp[i][j][maxMove];
        }
        long long  up = solve(m, n, maxMove-1, i-1, j, dp) % MOD;
        long long  down = solve(m, n, maxMove-1, i+1, j, dp) % MOD;
        long long left = solve(m, n, maxMove-1, i, j-1, dp) % MOD;
        long long right = solve(m, n, maxMove-1, i, j+1, dp) % MOD;
        return dp[i][j][maxMove] = (left + right + up + down) % MOD;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};