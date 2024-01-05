class Solution {
    int solve(vector<int> &nums, int n, int curr, int prev) {
        if(curr == n) {
            return 0;
        }

        int include = 0;
        int exclude = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solve(nums, n, curr+1, curr);
        }
        exclude = solve(nums, n, curr+1, prev);
        return max(include, exclude);
    }

    // Memoization

    int solveMem(vector<int> &nums, int n, int curr, int prev, vector<vector<int>> &dp) {
        if(curr == n) {
            return 0;
        }

        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }
        int include = 0;
        int exclude = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveMem(nums, n, curr+1, curr, dp);
        }
        exclude = solveMem(nums, n, curr+1, prev, dp);
        return dp[curr][prev+1] = max(include, exclude);
    }

    // Tabular
    int solveTab(vector<int> &nums, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=n-1; prev>=-1; prev--) {
                int include = 0;
                int exclude = 0;
                if(prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + dp[curr+1][curr+1];
                }
                exclude = dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];        
    }

    // Space optimization
    int solveSpace(vector<int> &nums, int n) {
        vector<int> currRow(n+1);
        vector<int> nextRow(n+1);
        
        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=n-1; prev>=-1; prev--) {
                int include = 0;
                int exclude = 0;
                if(prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + nextRow[curr+1];
                }
                exclude = nextRow[prev+1];
                currRow[prev+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return currRow[0];        
    }

    // DP + Binary search
    int solveOptimal(int n, vector<int> &nums) {
        if(n == 0) {
            return 0;
        }

        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n; i++) {
            if(nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            }
            else {
                // find index of just bigger element
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums, n, 0, -1);
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solveMem(nums, n, 0, -1, dp);
        // return solveTab(nums, n);
        // return solveSpace(nums, n);
        return solveOptimal(n, nums);
    }
};