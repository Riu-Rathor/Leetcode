 class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int result = 0;
        int length = 1;
        int lastColor = colors[0];
        for(int i=1; i<n; i++) {
            if(colors[i] == lastColor) {
                length = 1;
            }
            else {
                length++;
                if(length >= k) {
                    result++;
                }
            }
            lastColor = colors[i];
        }

        for(int i=0; i<k-1; i++) {
            if(colors[i] == lastColor) {
                length = 1;
                break;
            }
            else {
                length++;
                if(length >= k) {
                    result++;
                }
            }
            lastColor = colors[i];
        }
        return result;
    }
};