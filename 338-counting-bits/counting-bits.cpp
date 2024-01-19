class Solution {
    int solve(int n, vector<int> &dp) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        if(n%2 == 0) {
            return solve(n/2, dp);
        }
        else {
            return solve(n/2, dp) + 1;
        }
    }

    // Tabular 
    vector<int> solveTab(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++) {
            if(i%2 == 0) {
                dp[i] =dp[i/2];
            }
            else {
                dp[i] = dp[i/2] + 1;
            }
        }
        return dp;
        
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        if(n == 0) {
            return {0};
        }
        ans = solveTab(n);
        return ans;
        
    }
};