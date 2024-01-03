class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prevRow = 0;
        for(string laser : bank) {
            int currRow = 0;
            for(char ch : laser) {
                if(ch == '1') {
                    currRow++;
                }
            }

            ans += currRow * prevRow;
            if(currRow != 0) {
                prevRow = currRow;
            }
        }
        return ans;
    }
};