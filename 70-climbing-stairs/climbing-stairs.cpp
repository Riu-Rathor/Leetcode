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
        if(n == 0 || n == 1) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] =  solveMem(n-1, dp) + solveMem(n-2, dp);        
    }

    // tabular method
    int solveTab(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] =  dp[i-1] + dp[i-2];  
        }
        return dp[n];
    }

    // Space optimization
    int solveSpace(int n) {
        // vector<int> dp(n+1, 0);
        int prev = 1;
        int curr = 1;
        for(int i=2; i<=n; i++) {
            int temp = curr;
            curr =  prev + curr; 
            prev = temp;
        }
        return curr;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // return solve(n);
        // return solveMem(n, dp);
        // return solveTab(n);
        return solveSpace(n);
    }
};