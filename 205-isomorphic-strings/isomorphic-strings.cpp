class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        
        for(int i=0; i<s.length(); i++) {
            if(map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end()) {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            s[i] = map1[s[i]];
        }
        return s == t;
    }
};