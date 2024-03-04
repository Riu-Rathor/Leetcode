class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxScore = 0;
        int score = 0;
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = n-1;
        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i];
                score++;
                maxScore = max(maxScore, score);
                i++;
            }
            else if(score > 0) {
                power += tokens[j];
                score--;
                j--;
            }
            else {
                return maxScore;
            }
        }
        return maxScore;
    }
};