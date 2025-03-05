class Solution {
    long long solve(int n, vector<long long> &dp) {
        if(n == 1) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = solve(n-1, dp) + 4*(n-1);
    }
public:
    long long coloredCells(int n) {
        vector<long long> dp(n+1, -1);
        return solve(n, dp);
    }
};