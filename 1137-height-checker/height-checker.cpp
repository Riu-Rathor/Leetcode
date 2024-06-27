class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> original = heights;
        int count = 0;
        int n = heights.size();
        sort(heights.begin(), heights.end());

        for(int i=0; i<n; i++) {
            if(heights[i] != original[i]) {
                count++;
            }
        }
        return count;
    }
};