class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++) {
            if(nums[i] == nums[i-1]) {
                
                ans += count + 1;
                count++;
            }
            else {
                count = 0;
            }
        }
        return ans;
    }
};