class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rowZero(n, 0);
        vector<int> colZero(m, 0);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    rowZero[i] = 1;
                    colZero[j] = 1;
                }
            }
        }


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(rowZero[i] == 1 || colZero[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};