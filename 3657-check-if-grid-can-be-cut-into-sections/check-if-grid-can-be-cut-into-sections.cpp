class Solution {
    vector<vector<int>> merge(vector<vector<int>> &interval) {
        int n = interval.size();
        vector<vector<int>> result;
        sort(interval.begin(), interval.end());
        result.push_back(interval[0]);

        for(int i=1; i<n; i++) {
            if(interval[i][0] < result.back()[1]) {
                result.back()[1] = max(result.back()[1], interval[i][1]);
            }
            else {
                result.push_back(interval[i]);
            }
        }
        return result;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_axis;
        vector<vector<int>> y_axis;

        for(vector<int> &rectangle : rectangles) {
           int x1 = rectangle[0];
           int y1 = rectangle[1];
           int x2 = rectangle[2];
           int y2 = rectangle[3];
           x_axis.push_back({x1, x2});
           y_axis.push_back({y1, y2});
        }

        x_axis = merge(x_axis);
        y_axis = merge(y_axis);

        if(x_axis.size() >= 3 || y_axis.size() >= 3) {
            return true;
        }
        return false;
    }
};