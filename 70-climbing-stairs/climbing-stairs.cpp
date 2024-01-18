class Solution {

    int solve(int n, vector<int> &dp) {
        if(n == 0) {
            return 1;
        }
        if(n < 0) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    // Tabular method
    int solveTab(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            dp[n] = dp[n-1] + (n-2 >=0) ? dp[n-2] : 0;
        }
        return dp[n];
        
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};