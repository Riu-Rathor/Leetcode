class Solution {
public:

    bool isSpecial(int row, int col, int n, int m, vector<vector<int>> &mat) {
        for(int i=0; i<n; i++) {
            if(mat[i][col] == 1 && i != row) {
                return false;
            }
        }
        for(int j=0; j<m; j++) {
            if(mat[row][j] == 1 && j != col) {
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    continue;
                }
                if(mat[i][j] == 1) {
                    if(isSpecial(i,j,n,m,mat)) {
                        ans++; 
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};