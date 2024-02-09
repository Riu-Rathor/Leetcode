class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prevIndex(n, -1);

        int lastIndex = 0;
        int maxLen = 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < dp[j]+1) {
                        dp[i] = dp[j] + 1;
                        prevIndex[i] = j;
                    }

                    if(dp[i] > maxLen) {
                        maxLen = dp[i];
                        lastIndex = i;
                    }
                }
            }
        }
        vector<int> result;
        while(lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = prevIndex[lastIndex];
        }
        return result;
    }
};