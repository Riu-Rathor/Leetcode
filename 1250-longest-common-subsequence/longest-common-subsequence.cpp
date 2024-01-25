class Solution {
    int solve(int i, int j, string a, string b, vector<vector<int>> &dp) {
        if(i >= a.length() || j >= b.length()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int matches = 0;
        int notMatches = 0;
        if(a[i] == b[j]) {
            matches = 1 + solve(i+1, j+1, a, b, dp);
        }
        else {
            notMatches = max(solve(i+1, j, a, b, dp), solve(i, j+1, a, b, dp));
        }
        return dp[i][j] = max(matches, notMatches);
    }

    // Tabular dp
    int solveTab(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=n1-1; i>=0; i--) {
            for(int j=n2-1; j>=0; j--) {
                int matches = 0;
                int notMatches = 0;
                if(a[i] == b[j]) {
                    matches = 1 + dp[i+1][j+1];
                }
                else {
                    notMatches = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = max(matches, notMatches);
            }
        }
        return dp[0][0];
        
    }

    // Space Optimization
    int solveSpace(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();

        vector<int>curr(n2+1, 0);
        vector<int> next(n2+1, 0);

        for(int i=n1-1; i>=0; i--) {
            for(int j=n2-1; j>=0; j--) {
                int matches = 0;
                int notMatches = 0;
                if(a[i] == b[j]) {
                    matches = 1 + next[j+1];
                }
                else {
                    notMatches = max(next[j], curr[j+1]);
                }
                curr[j] = max(matches, notMatches);
            }
            next = curr;
        }
        return curr[0];
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        // return solve(0, 0, text1, text2, dp);
        // return solveTab(text1, text2);
        return solveSpace(text1, text2);
    }
};