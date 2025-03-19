class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;

        int flipCount = 0;
        vector<bool> isFlipped(n, false);

        for(int i=0; i<n; i++) {
            if(i >= 3 && isFlipped[i-3]) {
                flipCount--;
            }
            
            if(flipCount %  2 == nums[i]) {
                if(i+3 > n) {
                    return -1;
                }
                flipCount++;
                flips++;
                isFlipped[i] = true;
            }
        }

        return flips;
    }
};