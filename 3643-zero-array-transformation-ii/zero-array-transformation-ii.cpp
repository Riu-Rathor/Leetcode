class Solution {
    bool checkWithDifferenceArray(vector<int>& nums, vector<vector<int>>& queries,  int k, int n) {
        vector<int> diff(n, 0);

        for(int i=0; i<=k; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int x = queries[i][2];

            diff[start] += x;
            if(end+1 < n)
                diff[end+1] -= x;
        }
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += diff[i];
            diff[i] = sum;

            if(nums[i] - diff[i] > 0) {
                return false;
            }
        }
        return true;
    }

    bool checkAllZero(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0){
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int Q = queries.size();

        if(checkAllZero(nums)) {
            return 0;
        }
        
        int s = 0;
        int e = Q-1;
        int result = -1;
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(checkWithDifferenceArray(nums, queries, mid, n)) {
                result = mid + 1;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return result;
    }
};