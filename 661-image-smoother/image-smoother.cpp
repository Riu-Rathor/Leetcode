class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<int> prev(n);
        int topCorner = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int sum = 0;
                int count = 0;
                // adding bottom corners
                if(i+1<m) {
                    if(j-1>=0) {
                        sum += img[i+1][j-1];
                        count++;
                    }
                    sum += img[i+1][j];
                    count++;
                    if(j+1<n) {
                        sum += img[i+1][j+1];
                        count++;
                    }
                }

                // right neighbour
                if(j+1<n) {
                    sum += img[i][j+1];
                    count++;
                }

                // left neightbout

                if(j-1 >= 0) {
                    sum += prev[j-1];
                    count++;
                }
                // current cell
                sum += img[i][j];
                count++;

                // top neighbours
                if(i-1 >= 0) {
                    if(j-1 >= 0) {
                        sum += topCorner;
                        count++;
                    }

                    sum += prev[j];
                    count++;

                    if(j+1 < n) {
                        sum += prev[j+1];
                        count++;
                    }
                }

                
                if(i-1>=0) {
                    topCorner = prev[j];
                }
                
                prev[j] = img[i][j];
                img[i][j] = sum / count;                
            }
        }
        return img;
    }
};