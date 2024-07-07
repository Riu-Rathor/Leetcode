class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange) {
            int fullBottles = numBottles / numExchange;
            int emptyBottles = numBottles % numExchange;
            ans += fullBottles;
            numBottles = fullBottles + emptyBottles;
        }
        return ans;
    }
};