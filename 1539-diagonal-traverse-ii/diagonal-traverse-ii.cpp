class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i=nums.size()-1; i>=0; i--) {
            for(int j=0; j<nums[i].size(); j++) {
                int diagonal = i + j;
                mp[diagonal].push_back(nums[i][j]);
            }
        }

        vector<int> ans;
        int diagonal = 0;
        while(mp.find(diagonal) != mp.end()) {
            for(int &num : mp[diagonal]) {
                ans.push_back(num);
            }
            diagonal++;
        }
        return ans;
    }
};