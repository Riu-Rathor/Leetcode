class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<32; i++) {
            int ones = 0;
            int zeroes = 0;
            int temp = 1 << i;
            for(int &num : nums) {
                int bit = num & temp;
                if(bit == 0) {
                    zeroes++;
                }
                else {
                    ones++;
                }
            }
            if(ones % 3 == 1) {
                ans = ans | (1 << i);
            }
        }
        return ans;
    }
};