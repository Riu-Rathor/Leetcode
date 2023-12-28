
int dp[101][27][101][101];
class Solution {
    public:
    
    int solve(string &s, int i, int prevChar, int freq, int k) {
        if(k < 0) {
            return INT_MAX;
        }

        if(i >= s.length()) {
            return 0;
        }

        if(dp[i][prevChar][freq][k] != -1) {
            return dp[i][prevChar][freq][k];
        }
        int delete_i = solve(s, i+1, prevChar, freq, k-1);
        int keep_i = 0;
        if(prevChar != s[i] - 'a') {
            keep_i = 1 + solve(s, i+1, s[i]-'a', 1, k);
        }
        else {
            int one_more_addition = 0;
            if(freq == 1 || freq == 9 || freq == 99) {
                one_more_addition = 1;
            }
            keep_i = one_more_addition + solve(s, i+1, prevChar, freq+1, k);
        }
        return dp[i][prevChar][freq][k] = min(delete_i, keep_i);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 26, 0, k);
    }
};