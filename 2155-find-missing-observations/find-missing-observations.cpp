class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        long required_sum = (n + m) * mean;
        long sum = accumulate(begin(rolls), end(rolls), 0);
        long missing_sum = required_sum - sum;
        if (missing_sum < n || missing_sum > n * 6) return {};
        vector<int> ans(n, 1);
        missing_sum -= n;
        for (int i = 0; i < n; i++)
        {
            ans[i] += min(long(5), missing_sum);
            
            missing_sum -= min(long(5), missing_sum);
            if (missing_sum <= 0) break;
        }
        
        return ans;
    }
};