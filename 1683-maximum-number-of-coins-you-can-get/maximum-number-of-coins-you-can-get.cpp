class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int ans = 0;
        int bob = 0;
        int me = n-2;
        while(bob < me) {
            ans += piles[me];
            me -= 2;
            bob++;
        }
        return ans;
    }
};