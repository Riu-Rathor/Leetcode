class Solution {
public:

    int solve(int index, string &s, int &n) {
        if(index == n) {
            return 1;
        }

        if(s[index] == '0') {
            return 0;
        }

        int ithCharacter = solve(index+1, s, n);
        int i_plus_1thCharacter = 0;
        if(index+1 < n) {
            if(s[index] == '1' || s[index] == '2' && s[index+1] <= '6') {
            i_plus_1thCharacter = solve(index+2, s, n);
            }
        }
        return ithCharacter + i_plus_1thCharacter;
    }

    int solveMem(int index, string &s, int &n, vector<int> &dp) {
        if(dp[index] != -1) {
            return dp[index];
        }

        if(index == n) {
            return 1;
        }

        if(s[index] == '0') {
            return 0;
        }        
        int ithCharacter = solve(index+1, s, n);
        int i_plus_1thCharacter = 0;
        if(index+1 < n) {
            if(s[index] == '1' || s[index] == '2' && s[index+1] <= '6') {
            i_plus_1thCharacter = solve(index+2, s, n);
            }
        }
        return dp[index] =  ithCharacter + i_plus_1thCharacter;
    }

    int solveTab(string &s, int &n) {
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '0') {
                dp[i] = 0;
            }
            else {
                int ithCharacter = dp[i+1];
                int i_plus_1thCharacter = 0;
                if(i<n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) {
                    i_plus_1thCharacter = dp[i+2];
                }
                dp[i] = ithCharacter + i_plus_1thCharacter;
            }
            
        }
        return dp[0];

    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        // return solve(0, s, n);
        // return solveMem(0, s, n, dp);
        return solveTab(s, n);
    }
};