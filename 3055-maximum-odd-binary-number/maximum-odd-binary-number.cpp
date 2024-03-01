class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string result = string(n, '0');
        int j = 0;

        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(ch == '1') {
                if(result[n-1] == '0') {
                    result[n-1] = '1';
                }
                else {
                    result[j] = '1';
                    j++;
                }
            }
        }
        return result;
    }
};