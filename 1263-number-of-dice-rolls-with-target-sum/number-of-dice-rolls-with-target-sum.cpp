class Solution {
public:

    const int MOD = 1000000007;

    int solve(int n, int k, int target) {
        if(target < 0) {
            return 0;
        }

        if(n == 0 && target != 0) {
            return 0;
        }

        if(target == 0 && n != 0) {
            return 0;
        }

        if(n == 0 && target == 0) {
            return 1;
        }

        int  ans = 0;
        for(int i=1; i<=k; i++) {
            ans = ((ans) + (solve(n-1, k, target-i))) % MOD;
        }
        return ans;
    }

    // memoization
    int solveMem(int n, int k, int target, vector<vector<int>> &dp) {
        if(target < 0) {
            return 0;
        }

        if(n == 0 && target != 0) {
            return 0;
        }

        if(target == 0 && n != 0) {
            return 0;
        }

        if(n == 0 && target == 0) {
            return 1;
        }

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        int  ans = 0;
        for(int i=1; i<=k; i++) {
            ans = ((ans) + (solve(n-1, k, target-i))) % MOD;
        }
        return dp[n][target] =  ans;
    }
    // tabular (bottom-up)
    int solveTab(int n, int k, int t) {
        vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
        dp[0][0] = 1;

        for(int dice=1; dice<=n; dice++) {
            for(int target=1; target<=t; target++) {
                int ans = 0;
                for(int i=1; i<=k; i++) {
                    if(target-i >= 0) {
                        ans = (ans + dp[dice-1][target-i]) % MOD;
                    }
                }
                dp[dice][target] =  ans;
            }
        }
        return dp[n][t];
    }

    // Space Optimization
    int solveSO(int n, int k, int t) {
        
        vector<int> prev(t+1, 0);
        vector<int> curr(t+1, 0);
        prev[0] = 1;

        for(int dice=1; dice<=n; dice++) {
            for(int target=1; target<=t; target++) {
                int ans = 0;
                for(int i=1; i<=k; i++) {
                    if(target-i >= 0) {
                        ans = (ans + prev[target-i]) % MOD;
                    }
                }
                curr[target] =  ans;
            }
            prev = curr;

        }
        return prev[t];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        // return solve(n, k, target);
        // return solveMem(n, k, target, dp);
        return solveTab(n, k, target);
    }
};