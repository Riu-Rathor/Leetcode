class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        set<int> st(begin(nums), end(nums));
        vector<int> temp(begin(st), end(st));
        for(int i=0; i<temp.size(); i++) {
            int minElement = temp[i];
            int maxElement = minElement + n - 1;
            int j = upper_bound(begin(temp), end(temp), maxElement) - begin(temp);
            int within_range = j-i;
            int outOfBound = n - within_range;
            result = min(result, outOfBound);
        }
        return result;
    }
};