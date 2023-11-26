class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<pair<int, int>> prevHeights; // {height, column}

        for(int row=0; row<m; row++) {
            vector<pair<int, int>> currHeight;
            vector<bool> visited(n, false);
            for(auto [height, col] : prevHeights) {
                if(matrix[row][col] == 1) {
                    currHeight.push_back({height+1, col});
                    visited[col] = true;
                }
            }


            for(int col=0; col<n; col++) {
                if(!visited[col] && matrix[row][col] == 1) {
                    currHeight.push_back({1, col});
                }
            }

            for(int i=0; i<currHeight.size(); i++) {
                int H = currHeight[i].first;
                int base = i+1;
                maxArea = max(maxArea, H*base);
            }

            prevHeights = currHeight;
        



        }
        return maxArea;

    }
};