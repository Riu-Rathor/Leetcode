class Solution {

    int solve(vector<int> &nums, int index, int Xor) {
        if(index == nums.size()) {
            return Xor;
        }

        
        int include = solve(nums, index+1, Xor^nums[index]);
        int exclude = solve(nums, index+1, Xor);
        return include + exclude;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        // return solve(nums, 0, 0);
        int n = nums.size();
        int result = 0;
        for(int &num : nums) {
            result |= num;
        }
        return result << (n-1);
    }
};