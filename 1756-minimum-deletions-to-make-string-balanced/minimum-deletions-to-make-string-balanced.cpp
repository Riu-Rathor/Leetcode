class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int countA = 0;
        int countB = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == 'a') {
                countA++;
            }
        }

        int minimumDeletion = INT_MAX;
        for(int i=0; i<n; i++) {
            if(s[i] == 'a') {
                countA--;
            }
            minimumDeletion = min(minimumDeletion, (countA + countB));
            if(s[i] == 'b') {
                countB++;
            }
        }
        return minimumDeletion;
    }
};