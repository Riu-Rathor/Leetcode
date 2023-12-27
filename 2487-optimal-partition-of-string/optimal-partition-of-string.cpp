class Solution {
public:
    int partitionString(string s) {
        // int freq[26] = {0};
        vector<int> v;
        int ans = 1;
        for(int i=0; i<s.length(); i++) {
            int charToDigit = s[i] - 'a';
            // if(freq[charToDigit] != 0) {
            if(find(v.begin(), v.end(), s[i]) != v.end()) {
                ans++;
                // fill(begin(freq), end(freq), 0);
                v.clear();
                // freq[charToDigit]++;
                v.push_back(s[i]);
            }
            else {
                v.push_back(s[i]);
            }
        }
        return ans;
    }
};