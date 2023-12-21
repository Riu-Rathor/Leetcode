class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> pointsX;
        for(int i=0; i<points.size(); i++) {
            pointsX.push_back(points[i][0]);
        }

        sort(pointsX.begin(), pointsX.end());
        int maxi = INT_MIN;
        for(int i=1; i<pointsX.size(); i++) {
            int diff = pointsX[i] - pointsX[i-1];
            maxi = max(maxi, diff);
        }
        return maxi;
    }
};