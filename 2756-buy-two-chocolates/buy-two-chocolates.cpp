class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int smallest = INT_MAX;
        int second_smallest = INT_MAX;
        for(int i=0; i<n; i++) {
            if(prices[i] < smallest) {                
                second_smallest = smallest;
                smallest = prices[i];
            }
            else {
                second_smallest = min(second_smallest, prices[i]);
            }
        }

        int sum = smallest + second_smallest;
        if(sum > money) {
            return money;
        }
        return money - sum;
    }
};