class Solution {
    
    int solve(int i, int remainingWidth, int n, vector<vector<int>> &books, int maxHeight, int originalWidth, vector<vector<int>> &dp) {
        if(i >= n) {
            return maxHeight;
        }

        if(dp[i][remainingWidth] != -1) {
            return dp[i][remainingWidth];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        if(bookW <= remainingWidth) {
            keep = solve(i+1, (remainingWidth - bookW), n, books, max(maxHeight, bookH), originalWidth, dp);
        }

        skip = maxHeight + solve(i+1, (originalWidth - bookW), n, books, bookH, originalWidth, dp);
        return dp[i][remainingWidth] = min(keep, skip);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        vector<vector<int>> dp(n+1, vector<int>(shelfWidth+1, -1));
        return solve(0, shelfWidth, n, books, 0, shelfWidth, dp);
    }
};