class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        int element = 0;
        int ans = 0;
        sort(nums.begin(), nums. end());
        for(int i=n-1; i>=1; i--) {
            int largest = nums[i];
            int newLargest = nums[i-1];
            if(largest != newLargest) {
                ans = ans + element + 1;
            }
            element++;
        }
        return ans;
     }
};