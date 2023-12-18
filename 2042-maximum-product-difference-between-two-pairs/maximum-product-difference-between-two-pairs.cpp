class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int max_second = INT_MIN;
        int mini = INT_MAX;
        int min_second = INT_MAX;

        for(int i=0; i<n; i++) {
            if(nums[i] > maxi) {
                max_second = maxi;
                maxi = nums[i];
            }
            else {
                max_second = max(max_second, nums[i]);
            }

            if(nums[i] < mini) {
                min_second = mini;
                mini = nums[i];
            }  
            else {
                min_second = min(min_second, nums[i]);
            }       
        }
        return (maxi * max_second) - (mini * min_second);
    }
};