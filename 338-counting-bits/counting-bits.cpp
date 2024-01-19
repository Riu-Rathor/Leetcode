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
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        vector<int> dp(n+1, -1);
        for(int i=0; i<=n; i++) {
            ans.push_back(solve(i, dp));
        }
        return ans;
        
    }
};