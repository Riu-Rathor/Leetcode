class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int ele;
        for(int i=0; i<n; i++) {
            if(count == 0) {
                ele = nums[i];
            }
            if(nums[i] == ele) {
                count++;
            }
            else {
                count--;
            }
        }

        // confirm whether the element we got is the majority or not 
        int countEle = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == ele) {
                countEle++;
            }
        }

        if(countEle > n / 2) {
            return ele;
        }
        return -1;
    }
};