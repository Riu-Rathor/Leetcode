class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            freq[nums[i]]++;
            if(freq[nums[i]] > ans.size()) {                
                ans.push_back({});
            }
            ans[freq[nums[i]]-1].push_back(nums[i]);
        }
        return ans;
    }
};