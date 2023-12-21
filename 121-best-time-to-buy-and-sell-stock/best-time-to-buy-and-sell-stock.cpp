class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int min = prices[0];
        for(int i=0; i<n; i++) {
            if(min < prices[i]) {
                ans = max(ans, prices[i] - min);
            }
            else if(min > prices[i]) {
                min = prices[i];
            }
        }
        return ans;
    }
};