class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());
        int val_decrease = 0;
        int i = 0;
        while(k-- && i < n) {
            ans += (happiness[i] - val_decrease) >= 0 ? happiness[i] - val_decrease : 0;
            val_decrease++;
            i++;
        }
        return ans;
    }
};