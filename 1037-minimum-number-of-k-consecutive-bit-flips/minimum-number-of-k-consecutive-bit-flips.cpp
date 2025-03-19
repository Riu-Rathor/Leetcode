class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
      int n = nums.size();
        int flips = 0;

        int flipCount = 0;
        vector<bool> isFlipped(n, false);

        for(int i=0; i<n; i++) {
            if(i >= k && isFlipped[i-k]) {
                flipCount--;
            }
            
            if(flipCount %  2 == nums[i]) {
                if(i+k > n) {
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