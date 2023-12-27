class Solution {
public:
    int partitionString(string s) {
        int  freq[26] = {0};
        int ans = 1;
        for(int i=0; i<s.length(); i++) {
            int charToDigit = s[i] - 'a';
            if(freq[charToDigit] != 0) {
                ans++;
                fill(begin(freq), end(freq), 0);
                freq[charToDigit]++;
            }
            else {
                freq[charToDigit]++;
            }
        }
        return ans;
    }
};