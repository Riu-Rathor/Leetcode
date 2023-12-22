class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int ones = 0;
        int zeros = 0;
        int score = INT_MIN;
        for(int i=0; i<n-1; i++) {
            if(s[i] == '0') {
                zeros++;
            }
            else {
                ones++;
            }
            score = max(score, zeros-ones);
        }
        if(s[n-1] == '1') {
            ones++;
        }
        return score + ones;
    }
};