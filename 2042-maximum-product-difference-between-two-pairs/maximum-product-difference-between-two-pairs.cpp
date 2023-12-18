class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // int max = INT_MIN;
        // int max_second = INT_MIN;
        // int min = INT_MAX;
        // int min_second = INT_MAX;

        return (nums[n-1] * nums[n-2]) - (nums[0] * nums[1]);

    }
};