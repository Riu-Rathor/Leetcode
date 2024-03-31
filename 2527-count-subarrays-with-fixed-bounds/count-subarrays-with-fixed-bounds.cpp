class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minPos = -1;
        int maxPos = -1;
        int culpritIndex = -1;
        long long ans = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                culpritIndex = i;
            }

            if(nums[i] == minK) {
                minPos = i;
            }

            if(nums[i] == maxK) {
                maxPos = i;
            }

            long long smaller = min(minPos, maxPos);
            long long temp = smaller - culpritIndex;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};