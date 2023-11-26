class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            vector<int> temp;
            for(int j=0; j<m; j++) {
                if(i > 0 && matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i-1][j];
                }
                temp.push_back(matrix[i][j]);
            }
            sort(temp.begin(), temp.end(), greater<int>());
            for(int k=0; k<temp.size(); k++) {
                if(temp[k] >= 1) {
                    ans = max(ans, temp[k]*(k+1));
                }
            }
        }
        return ans;
    }
};