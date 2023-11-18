class Solution {

    int bSearch(int target_index, vector<int> &nums, vector<long> &prefixSum, int k) {
        int s = 0;
        int e = target_index;
        int result = target_index;
        while(s <= e) {
            int mid = s + (e-s) / 2;
            long  count = target_index - mid + 1;
            long originalSum = prefixSum[target_index] - prefixSum[mid] + nums[mid];
            long expectedSum = count * nums[target_index];
            long operations = expectedSum - originalSum;
            if(operations > k) {
                s = mid + 1;
            }
            else {
                result = mid;
                e = mid - 1;
            }
        }
        return target_index - result + 1;
    }


public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefixSum(n);        
        int result = 0;
        sort(nums.begin(), nums.end());
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        
        for(int i=0; i<n; i++) {
            int freq = bSearch(i, nums, prefixSum, k);
            result = max(result, freq);
        }
        return result;
    }
};