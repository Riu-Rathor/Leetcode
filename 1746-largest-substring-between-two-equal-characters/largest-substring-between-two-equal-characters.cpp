class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int starting[26];
        int ending[26];
        int ans = -1;
        for(int i=0; i<26; i++) {
            starting[i] = -1;
            ending[i] = -1;
        }
        for(int i=0; i<s.length(); i++) {
            if(starting[s[i]-'a'] == -1) {
                starting[s[i]-'a'] = i;
            }
            ending[s[i]-'a'] = i;
        }

        for(int i=0; i<26; i++) {
            if(starting[i] != -1 && ending[i] != -1 && starting[i] != ending[i]) {
                ans = max(ans, ending[i] - starting[i] - 1);
            }
        }
        return ans;
    }
};