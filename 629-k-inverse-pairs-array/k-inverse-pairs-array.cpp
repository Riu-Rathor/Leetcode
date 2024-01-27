

class Solution {
    int MOD = 1e9+7;
    int solve(int n, int k, vector<vector<int>> &dp) {
        if(n == 0) {
            return 0;
        }
        if(k == 0) {
            return 1;
        }
        if(dp[n][k] != -1) {
            return dp[n][k];
        }
        int result = 0;
        for(int i = 0; i <= min(k, n-1); i++) {
            result = (result%MOD + solve(n-1, k-i, dp) % MOD) % MOD;
        }
        return dp[n][k] = result;
    }
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(1001, vector<int> (1001, -1));
        return solve(n, k, dp);
    }
};