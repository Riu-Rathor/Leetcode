class Solution {

    // Recursion 
    int solve(int n) {
        if(n == 0) {
            return 0;
        }

        if(n == 1 || n == 2) {
            return 1;
        }

        return solve(n-3) + solve(n-2) + solve(n-1);
    }

    // Memoization
    int solveMem(int n, vector<int> &dp) {
        if(n == 0) {
            return 0;
        }

        if(n == 1 || n == 2) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = solveMem(n-3, dp) + solveMem(n-2, dp) + solveMem(n-1, dp);
    }


public:
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return solveMem(n, dp);
    }
};