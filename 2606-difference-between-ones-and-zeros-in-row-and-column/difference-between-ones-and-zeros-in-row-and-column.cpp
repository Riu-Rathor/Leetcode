class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 0));
        vector<int> oneRow(n, 0);
        vector<int> zeroRow(n, 0);
        vector<int> zeroCol(m, 0);
        vector<int> oneCol(m, 0);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    oneRow[i]++;
                    oneCol[j]++;
                }
                else {
                    zeroRow[i]++;
                    zeroCol[j]++;
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                diff[i][j] = (oneRow[i] + oneCol[j]) - (zeroRow[i] + zeroCol[j]);
            }
        }
        return diff;

    }
};