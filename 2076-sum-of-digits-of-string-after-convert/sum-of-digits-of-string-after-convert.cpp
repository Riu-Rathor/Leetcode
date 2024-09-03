class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        int n = s.length();
        for(int i=0; i<n; i++) {
            num += to_string((s[i] - 'a') + 1);
        }
        int result = 0;
        while(k--) {
            result = 0;
            for(int i=0; i<num.size(); i++) {
                result += (num[i] - '0');
            }
            num = to_string(result);
        }
        return result;
    }
};