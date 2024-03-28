class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int culprit = 0;
        while(j < n) {
            freq[nums[j]]++;
            if(freq[nums[j]] == k + 1) {
                culprit++;
            }

            if(culprit > 0) {
                freq[nums[i]]--;
                if(freq[nums[i]] == k) {
                    culprit--;
                }
                i++;
            }

            if(culprit == 0) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};