class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> rightCountA(n, 0);
        int countB = 0;
        int countA = 0;
        for(int i=n-1; i>=0; i--) {
            rightCountA[i] = countA;
            if(s[i] == 'a') {
                countA++;
            }
        }

        int minimumDeletion = INT_MAX;
        for(int i=0; i<n; i++) {
            minimumDeletion = min(minimumDeletion, (rightCountA[i] + countB));
            if(s[i] == 'b') {
                countB++;
            }
        }
        return minimumDeletion;
    }
};