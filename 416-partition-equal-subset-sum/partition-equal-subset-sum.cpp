class Solution {
    bool solve(int i, int target, int sum, vector<int> &nums, vector<vector<int>> &dp) {
        if(i >= nums.size()) {
            return false; 
        }
    
        if(sum > target) {
            return false;
        }

        if(sum == target) {
            return true;
        }

        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        bool take = solve(i+1, target, sum+nums[i], nums, dp);
        bool notTake = solve(i+1, target, sum, nums, dp);
        return dp[i][sum] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int &num : nums) {
            sum += num;
        }

        if(sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));

        return solve(0, target, 0, nums, dp);
    }
};