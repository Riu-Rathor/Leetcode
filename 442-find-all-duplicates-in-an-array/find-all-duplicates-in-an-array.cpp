class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            int num = abs(nums[i]);
            int index = num - 1;
            if(nums[index] < 0) {
                ans.push_back(index + 1);
            }
            else {
                nums[index] *= -1;
            }            
        }
        return ans;
    }
};