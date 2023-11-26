class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> prevHeight(m, 0);
        for(int i=0; i<n; i++) {
            vector<int> currHeight = matrix[i];
            for(int j=0; j<m; j++) {
                if(currHeight[j] == 1) {
                    currHeight[j] = currHeight[j] + prevHeight[j];
                }
                
            }
            vector<int> temp = currHeight;
            sort(temp.begin(), temp.end(), greater<int>());
            for(int k=0; k<temp.size(); k++) {
                if(temp[k] >= 1) {
                    ans = max(ans, temp[k]*(k+1));
                }
            }
            prevHeight = currHeight;
        }
        return ans;
    }
};