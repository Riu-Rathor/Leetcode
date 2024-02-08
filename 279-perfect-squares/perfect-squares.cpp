class Solution {

// Recursion + Memoization
    int solve(int n, vector<int> &dp) {
        if(n <= 0) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int ans = INT_MAX;
        for(int i=1; i<=sqrt(n); i++) {
           ans = min(ans, 1 + solve(n-(i*i), dp));            
        }
        return dp[n] = ans;
    }

    // Bottom up
    int solveTab(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int j=1; j<=n; j++) {
            int ans = INT_MAX;
            for(int i=1; i<=sqrt(j); i++) {
                int temp = 1 + dp[j-(i*i)];
                ans = min(ans, temp);            
            }
            dp[j] = ans;
        }
        return dp[n];        
    }

public:
    int numSquares(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);
        return solveTab(n);
    }
};