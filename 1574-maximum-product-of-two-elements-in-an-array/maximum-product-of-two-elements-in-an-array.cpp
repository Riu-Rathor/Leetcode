class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxElement = INT_MIN;
        int secondMax = INT_MIN;
        
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] > maxElement) {
                secondMax = maxElement;
                maxElement = nums[i];
            } 
            else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }
        return (maxElement-1) * (secondMax-1);
    }
};