class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(26, 0);
        int ans = 1;
        for(int i=0; i<n; i++) {
            int curr = s[i] - 'a';
            int left = max(0, curr - k);
            int right = min(25, curr + k);
            int longest = 0;
            for(int j=left; j<=right; j++) {
                longest = max(longest, dp[j]);
            }

            dp[curr] = max(dp[curr], longest + 1);
            ans = max(ans, dp[curr]);
        }
        return ans;
    }
};