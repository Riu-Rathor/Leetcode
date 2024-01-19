class Solution {
    // Recursion + Memoization
 int solve(vector<vector<int>>& matrix, int row, int col, int n, vector<vector<int>> &dp) {
        if(row == n-1) {
            return matrix[row][col];
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int minSum = INT_MAX;
        int sum = matrix[row][col];
        for(int shift = -1; shift<=1; shift++) {
            if(col+shift < n && col+shift >= 0 && row+1 < n) {
                minSum = min(minSum, sum + solve(matrix, row+1, col+shift, n, dp));
            }
        }        
        return dp[row][col] = minSum;
    }

    // Tabular Method
    int solveTab(vector<vector<int>>& matrix, int n) {
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int col = 0; col < n; col++) {
            dp[n-1][col] = matrix[n-1][col];
        }
        
        
        for(int row = n-2; row >= 0; row--) {
            for(int col = n-1; col >= 0; col--) {
                dp[row][col] = INT_MAX;
                int sum = matrix[row][col];
                for(int shift = -1; shift <= 1; shift++) {
                    if(col + shift < n && col + shift >= 0 && row + 1 < n) {
                        dp[row][col] = min(dp[row][col], sum + dp[row+1][col+shift]);
                    }
                }
            }
        }

        int minSum = INT_MAX;
        for(int col = 0; col < n; col++) {
            minSum = min(minSum, dp[0][col]);
        }
        return minSum;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int result = INT_MAX;
        int n = matrix.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        for(int j = 0; j < n; j++) {
            result = min(result, solveTab(matrix, n));           
        }
        // result = solveTab(matrix, n);
        return result;
    }
};