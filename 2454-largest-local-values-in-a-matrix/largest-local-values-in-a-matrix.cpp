class Solution {

    int findLocalMax(vector<vector<int>>& grid, int row, int col) {
        int ans = INT_MIN;
        for(int x=row; x<= row+2; x++) {
            for(int y=col; y<=col+2; y++) {
                ans = max(ans, grid[x][y]);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2, vector<int>(n-2));
        for(int i=0; i<n-2; i++) {
            for(int j=0; j<n-2; j++) {
                maxLocal[i][j] = findLocalMax(grid, i, j);
            }
        }
        return maxLocal;
    }
};