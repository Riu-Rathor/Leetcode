class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++) {
            totalSum += nums[i];
        }

        int leftSum = 0;
        int rightSum = 0;
        for(int i=0; i<n; i++) {
            rightSum = totalSum - leftSum;
            int leftEle = i;
            int rightEle = n-i;
            int diff = (nums[i] * leftEle - leftSum) + (rightSum - nums[i] * rightEle);
            result.push_back(diff);
            leftSum += nums[i];
        }
                                                        
        return result;
    }
};