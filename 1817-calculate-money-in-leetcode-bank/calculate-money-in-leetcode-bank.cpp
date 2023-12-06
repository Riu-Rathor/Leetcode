class Solution {
public:
    int totalMoney(int n) {
        int mondayNumber = 1;
        int count = mondayNumber;
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans = ans + count;
            count++;
            if(i % 7 == 0) {
                mondayNumber++;
                count = mondayNumber;
            }
        }
        return ans;
    }
};