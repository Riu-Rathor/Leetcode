class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long result = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        while(j < n) {
            if(nums[j] == maxi) {
                count++;
            }

            while(count >= k) {
                result += n-j;
                if(nums[i] == maxi) {
                    count--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};