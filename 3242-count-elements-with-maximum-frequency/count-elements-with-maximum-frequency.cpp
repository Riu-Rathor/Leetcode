class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        int maxFreq = 0;
        for(auto &it: mp) {
            maxFreq = max(maxFreq, it.second);
        }
        for(auto &it : mp) {
            if(it.second == maxFreq) {
                count++;
            }
        }
        

        return count * maxFreq;
    }
};