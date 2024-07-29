class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;
        for(int j=1; j<n-1; j++) {
            int countSmallerLeft = 0;
            int countLargerLeft = 0;

            for(int i=0; i<j; i++) {
                if(rating[i] < rating[j]) {
                    countSmallerLeft++;
                }
                else if(rating[i] > rating[j]) {
                    countLargerLeft++;
                }
            }

            int countSmallerRight = 0;
            int countLargerRight = 0;

            for(int i=j+1; i<n; i++) {
                if(rating[i] < rating[j]) {
                    countSmallerRight++;
                }
                else if(rating[i] > rating[j]) {
                    countLargerRight++;
                }
            }

            teams += (countSmallerLeft * countLargerRight);
            teams += (countSmallerRight * countLargerLeft);
        }
        return teams;
    }
};