class Solution {

    int solve(int i, int &n, vector<int> &cost) {
        if(i >= n) {
            return 0;
        }

        int oneStep = cost[i] + solve(i+1, n, cost);
        int twoStep = cost[i] + solve(i+2, n, cost);
        return min(oneStep, twoStep);
    }

    // Memoization
    int solveMem(int i, int &n, vector<int> &cost, vector<int> &dp) {
        if(i >= n) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int oneStep = cost[i] + solveMem(i+1, n, cost, dp);
        int twoStep = cost[i] + solveMem(i+2, n, cost, dp);
        return dp[i] =  min(oneStep, twoStep);
    }

    // Tabular
    int solveTab(int i, int &n, vector<int> &cost) {
        vector<int> dp(n+1, 0);
        dp[n-1] = cost[n-1];
        
        for(int i=n-2; i>=0; i--) {
            int oneStep = 0;
            int twoStep = 0;
            if(i+1 <= n) {
                oneStep = cost[i] + dp[i+1];
            }            
            if(i+2 <= n) {
                twoStep = cost[i] + dp[i+2];
            }            
            dp[i] =  min(oneStep, twoStep);

        }
        return dp[i];        
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        // return min(solve(0, n,cost,), solve(1, n,cost));
        // return min(solveMem(0, n, cost, dp), solveMem(1, n,cost, dp));
        return min(solveTab(0, n, cost), solveTab(1, n,cost));
        // return solve(0, n, cost);
    }
};