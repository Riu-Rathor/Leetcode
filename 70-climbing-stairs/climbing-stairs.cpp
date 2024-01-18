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
            dp[i] = 
            dp[i] = ((i-1 >=0) ? dp[i-1] : 0 )+ ((i-2 >=0) ? dp[i-2] : 0);
        }
        return dp[n];
        
    }

    // Space Optimixation
    int solveSpace(int n) {
        if (n <= 1) {
            return 1;
        }
        int prev1 = 1;
        int prev2 = 0;
        // dp[0] = 1;
        for(int i=1; i<=n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // return solve(n, dp);
        // return solveTab(n);
        return solveSpace(n);
    }
};