class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;

        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        int maxFreq = 0;
        for(auto it : mp) {
            maxFreq = max(maxFreq, it.second);
        }

        for(auto it : mp) {
            if(it.second == maxFreq) {
                ans++;
            }
        }
        return ans * maxFreq;
    }
};