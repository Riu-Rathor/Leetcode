class Solution {

    int getNextIndex(vector<vector<int>> &arr, int s, int currJobEnd, int n) {
        int e = n-1;
        int result = n+1;
        while(s <= e) {
            int mid  = s + (e-s)/2;
            if(arr[mid][0] >= currJobEnd) {
                result = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>> &arr, int n, int index, vector<int> &dp) {
        if(index >= n) {
            return 0;
        }

        if(dp[index] != -1) {
            return dp[index];
        }

        int nextjob = getNextIndex(arr, index+1, arr[index][1], n);
        int include = arr[index][2] + solve(arr, n, nextjob, dp);
        int exclude = solve(arr, n, index+1, dp);
        return dp[index] = max(include, exclude);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> arr(n, vector<int> (3, 0));
        for(int i=0; i<n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end());
        vector<int> dp(n+1, -1);
        return solve(arr, n, 0, dp);
        
    }
};