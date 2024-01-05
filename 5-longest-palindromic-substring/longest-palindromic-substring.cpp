class Solution {

    bool isPalindrome(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i >= j) {
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i] == s[j]) {
            return dp[i][j] = isPalindrome(s, i+1, j-1, dp);
        }
        else {
            return dp[i][j] = false;
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLength = INT_MIN;
        int start = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {

                if(isPalindrome(s, i, j, dp)) {
                    if(j-i+1 > maxLength) {
                        maxLength = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
}; 