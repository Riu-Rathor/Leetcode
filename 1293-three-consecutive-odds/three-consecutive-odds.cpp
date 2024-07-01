class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int counter = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] % 2 == 1) {
                counter++;
            } 
            else {
                counter = 0;
            }

            if(counter == 3) {
                return true;
            }
        }
        return false;
    }
};