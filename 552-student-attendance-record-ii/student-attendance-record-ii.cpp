class Solution {
    #define MOD 1000000007
    int solve(int n, int absent, int late, vector<vector<vector<int>>>& dp) {
        if(absent == 2 || late == 3) {
            return 0;
        }
        
        if(n == 0) {
            return 1;
        }

        if (dp[n][absent][late] != -1) {
            return dp[n][absent][late];
        }

        int P = solve(n-1, absent, 0, dp) % MOD;
        int A = solve(n-1, absent+1, 0, dp) % MOD;
        int L = solve(n-1, absent, late+1, dp) % MOD;
        return dp[n][absent][late] = ((A + L) % MOD + P) % MOD;
  }

int solveTab(int n, int absent, int late) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i=0; i<2; ++i) {
            for(int j=0; j<3; ++j) {
                dp[0][i][j] = 1;
            }
        }

        for(int i=1; i<=n; i++) {
            for(int absent=0; absent<2; absent++) {
                for(int late=0; late<3; late++) {

                    long long result = dp[i-1][absent][0];
                    result += (absent == 0 ? dp[i-1][absent+1][0] : 0);
                    result += (late < 2 ? dp[i-1][absent][late+1] : 0);
                    dp[i][absent][late] = result % MOD;
                }
            }
        }
        return dp[n][0][0];        
  }
public:
    int checkRecord(int n) {
        int late = 0;
        int absent = 0;
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solveTab(n, 0, 0);
    }
};