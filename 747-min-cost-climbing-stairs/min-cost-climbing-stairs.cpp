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
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        // return min(solve(0, n,cost,), solve(1, n,cost));
        return min(solveMem(0, n, cost, dp), solveMem(1, n,cost, dp));
    }
};