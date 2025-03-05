class Solution {
    long long solve(int n) {
        vector<long long> dp(n+1, 0);
        dp[1] = 1;

        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + 4*(i-1);
        }
        return dp[n];
    }
public:
    long long coloredCells(int n) {
        return solve(n);
    }
};