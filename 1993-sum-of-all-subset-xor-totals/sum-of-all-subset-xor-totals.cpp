class Solution {

    void solve(vector<int> &nums, int index, vector<vector<int>> &subsets, vector<int> &currSubset) {
        if(index == nums.size()) {
            subsets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[index]);
        solve(nums, index+1, subsets, currSubset);
        currSubset.pop_back();
        solve(nums, index+1, subsets, currSubset);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;
        solve(nums, 0, subsets, currSubset);
        int result = 0;
        for(vector<int> &subset : subsets) {
            int Xor = 0;
            for(int &num : subset) {
                Xor ^= num;
            }
            result += Xor;
        }
        return result;
    }
};