class Solution {
public:
    int specialArray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        for(int i=0; i<=maxElement; i++) {
            int count = 0;
            for(int &num : nums) {
                if(num >= i) {
                    count++;
                }
            }
            if(count == i) {
                return i;
            }
        }
        return -1;
    }
};