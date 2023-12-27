class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int total = 0;
        int maxi = INT_MIN;
        int count = 1;
        for(int i=1; i<n; i++) {
            if(colors[i] == colors[i-1]) {
                if(count == 1) {
                    total += neededTime[i-1];
                    maxi = max(maxi, neededTime[i-1]);
                }
                count++;
                total += neededTime[i];
                maxi = max(maxi, neededTime[i]);
            }
            else if(count != 1) {
                ans += total - maxi;
                count = 1;
                total = 0;
                maxi = INT_MIN;
            }
        }

        if(count != 1) {
            ans += total - maxi;
        }
        return ans;
    }
};