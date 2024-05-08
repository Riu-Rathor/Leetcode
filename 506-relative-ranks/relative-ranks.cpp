class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> result(n);
        
        int max_score = *max_element(begin(score), end(score));
        vector<int> arr(max_score + 1, -1);
        for(int i=0; i<n; i++) {
            arr[score[i]] = i;
        }
        
        int rank = 1;
        for(int i=max_score; i>=0; i--) {
            if(arr[i] != -1) {
                int athelete = arr[i];

                if(rank == 1) {
                    result[athelete] = "Gold Medal";
                }
                else if(rank == 2) {
                    result[athelete] = "Silver Medal";
                }
                else if(rank == 3) {
                    result[athelete] = "Bronze Medal";
                }
                else {
                    result[athelete] = to_string(rank);
                }
                rank++;
            }

        }
        return result;
    }
};