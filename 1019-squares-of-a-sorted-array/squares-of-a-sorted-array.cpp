class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            result.push_back(nums[i]*nums[i]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};