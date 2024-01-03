class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int ans = 0;
        for(string log : logs) {
            int dotCount = 0;
            if(log[0] == '.') dotCount++;
            if(log[1] == '.') dotCount++;
            if(dotCount == 0) {
                ans++;
            } else if(dotCount == 2) {
                if(ans - 1 >= 0) {
                    ans--;
                }
            }
        }
        return ans;

    }
};