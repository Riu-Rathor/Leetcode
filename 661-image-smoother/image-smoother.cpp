class Solution {

    private:
    int smootherAverage(int i, int j, vector<vector<int>>& img, int n, int m) {
        int sum = img[i][j];
        int cnt = 1;
        if((i-1) >= 0 && (j-1) >= 0) {
            sum += img[i-1][j-1];
            cnt++;
        }

        if((i-1)>= 0) {
            sum += img[i-1][j];
            cnt++;
        }

        if((i-1) >= 0 && (j+1) < m) {
            sum += img[i-1][j+1];
            cnt++;
        }

        if((j-1)>= 0) {
            sum += img[i][j-1];
            cnt++;
        }

        if((j+1)< m) {
            sum += img[i][j+1];
            cnt++;
        }

        if((i+1) < n && (j-1) >= 0) {
            sum += img[i+1][j-1];
            cnt++;
        }

        if((i+1) < n) {
            sum += img[i+1][j];
            cnt++;
        }

        if((i+1) < n  && (j+1) < m) {
            sum += img[i+1][j+1];
            cnt++;
        }

        int avg = floor(sum / cnt);
        return avg;

        
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = smootherAverage(i, j, img, n, m);
            }
        }
        return ans;
    }
};