class Solution {

    int solve(vector<int>& jd, int n, int index, int d, vector<vector<int>> &dp) {
        // base case
        if(d == 1) {
            int maxD = jd[index];
            for(int i=index; i<n; i++) {
                maxD = max(maxD, jd[i]);
            }
            return maxD;
        }

        if(dp[index][d] != -1) {
            return dp[index][d];
        }

        int maxDiff = jd[index];
        int finalResult = INT_MAX;
        for(int i=index; i<=n-d; i++) {
            maxDiff = max(maxDiff, jd[i]);
            int result = maxDiff + solve(jd, n, i+1, d-1, dp);
            finalResult = min(finalResult, result);
        }
        return dp[index][d] = finalResult;

    }

    // tabular
     int solve(vector<int>& jd, int n, int d) {
        vector<vector<int>> dp(n+1, vector<int>(d+1, 0));
        for(int i=0; i<n; i++) {
            dp[i][1] = *max_element(begin(jd)+i, end(jd));
        }
        for(int days = 2; days<=d; days++) {
            for(int index=0; index<=n-days; index++) {
                int maxDiff = jd[index];
                int finalResult = INT_MAX;
                for(int i=index; i<=n-days; i++) {
                    maxDiff = max(maxDiff, jd[i]);
                    int result = maxDiff + dp[i+1][days-1];
                    finalResult = min(finalResult, result);
                }
                 dp[index][days] = finalResult;
            }
        }
        return dp[0][d];

        

    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) {
            return -1;
        }
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        // return solve(jobDifficulty, n, 0, d);
        // return solve(jobDifficulty, n, 0, d, dp);
        return solve(jobDifficulty, n, d);
    }
};