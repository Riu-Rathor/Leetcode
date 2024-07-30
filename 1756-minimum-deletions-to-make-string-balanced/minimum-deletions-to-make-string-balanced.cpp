class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> leftCountB(n, 0);
        vector<int> rightCountA(n, 0);
        int countB = 0;
        int countA = 0;

        for(int i=0; i<n; i++) {
            leftCountB[i] = countB;
            if(s[i] == 'b') {
                countB++;
            }
        }

        for(int i=n-1; i>=0; i--) {
            rightCountA[i] = countA;
            if(s[i] == 'a') {
                countA++;
            }
        }

        int minimumDeletion = INT_MAX;
        for(int i=0; i<n; i++) {
            int newDeletion = leftCountB[i] + rightCountA[i];
            minimumDeletion = min(minimumDeletion, newDeletion);
        }

        return minimumDeletion;


    }
};