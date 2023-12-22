class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int zeros = 0;
        int ones = 0;
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                ones++;
            }
        }


        for(int i=0; i<n-1; i++) {
            if(s[i] == '0') {
                zeros++;
            }
            else if(s[i] == '1'){
                ones--;
            }
            int tempCount = zeros + ones;
            ans = max(ans, tempCount);
        }
        return ans;
    }
};