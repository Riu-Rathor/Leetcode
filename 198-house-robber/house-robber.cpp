class Solution {
    int solve(vector<int> &nums, int n, int index, vector<int> &dp) {
        if(index >= n) {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int include = nums[index] + solve(nums, n, index+2, dp);
        int exclude = solve(nums, n, index+1, dp);
        return dp[index] = max(include, exclude);
    }
    
    // tabular dp
    int solveTab(vector<int> &nums, int n) {
        vector<int> dp(n+1, 0);
        for(int index=n-1; index >= 0; index--) {
            int include = nums[index] + (index + 2 < n ? dp[index+2] : 0);
            int exclude = dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[0];    
    }

    // Space optimization
    int solveSpace(vector<int> &nums, int n) {
        // vector<int> dp(n+1, 0);
        int curr = 0;
        int next1 = 0;
        int next2 = 0;
        for(int index=n-1; index >= 0; index--) {
            int include = nums[index] + (index + 2 < n ? next2 : 0);
            int exclude = next1;
            curr = max(include, exclude);
            next2 = next1;
            next1 = curr;
        }
        return next1;    
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1, -1);
        // return solve(nums, n, 0, dp);
        // return solveTab(nums, n);
        return solveSpace(nums, n);
    }
};