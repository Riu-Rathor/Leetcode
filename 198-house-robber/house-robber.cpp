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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(nums, n, 0, dp);
    }
};