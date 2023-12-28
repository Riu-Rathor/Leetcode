class Solution {
public:

    int solve(int n) {
        if(n == 0) {
            return 1;
        } 
        if(n < 0) {
            return 0;
        }

        return solve(n-1) + solve(n-2);
    }

    // memoization
    int solveMem(int n, vector<int> &dp) {
        if(n == 0) {
            return 1;
        } 
        if(n < 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] =  solveMem(n-1, dp) + solveMem(n-2, dp);
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // return solve(n);
        return solveMem(n, dp);
    }
};