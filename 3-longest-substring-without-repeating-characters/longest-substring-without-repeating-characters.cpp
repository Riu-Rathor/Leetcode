class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++) {
            unordered_map<char, int> mp;
            int j = i;
            for(; j<n; j++) {
                if(mp.find(s[j]) != mp.end()) {
                    break;
                }
                mp[s[j]]++;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};